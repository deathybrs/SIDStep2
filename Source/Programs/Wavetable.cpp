#include "Wavetable.h"


#include <array>


#include "JuceHeader.h"


#include "../SIDProgram.h"


Wavetable::Wavetable ()
{
    waveTable . add (
                     DEFAULT_WAVEFORM
                    );
    waveTable . add (
                     END_COMMAND
                    ); // end
    selectedRow = waveTable . size ();
}


Wavetable::Wavetable (
        XmlElement* e
        )
{
    for ( auto i = 0 ; i < e -> getNumChildElements () ; i++ )
    {
        const auto r = e -> getChildElement (
                                             i
                                            );
        unsigned int row = 0;

        if ( r -> getTagName () == "row" )
        {
            if ( r -> getBoolAttribute (
                                        "triangle"
                                       ) )
            {
                row |= TRIANGLE_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "sawtooth"
                                       ) )
            {
                row |= SAWTOOTH_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "pulse"
                                       ) )
            {
                row |= PULSE_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "noise"
                                       ) )
            {
                row |= NOISE_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "test"
                                       ) )
            {
                row |= TEST_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "ring"
                                       ) )
            {
                row |= RING_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "sync"
                                       ) )
            {
                row |= SYNC_BIT;
            }
            if ( r -> getBoolAttribute (
                                        "gate"
                                       ) )
            {
                row |= GATE_BIT;
            }
        }
        else if ( r -> getTagName () == "command" )
        {
            if ( r -> getStringAttribute (
                                          "type"
                                         ) == "end" )
            {
                row = END_COMMAND;
            }
            else if ( r -> getStringAttribute (
                                               "type"
                                              ) == "goto" )
            {
                row = GOTO_COMMAND;
            }
            else if ( r -> getStringAttribute (
                                               "type"
                                              ) == "sustain-to" )
            {
                row = SUSTAIN_TO_COMMAND;
            }

            if ( row != END_COMMAND )
            {
                row |= r -> getIntAttribute (
                                             "argument"
                                            ) & UCHAR_MAX;
            }
        }

        waveTable . add (
                         row
                        );
    }
    selectedRow = waveTable . size ();
}


Wavetable::Wavetable (
        const Wavetable& other
        )
    :
    waveTableIndex (
                    other . waveTableIndex
                   )
  , sustained (
               other . sustained
              )
  , released (
              other . released
             )
  , releaseCounter (
                    other . releaseCounter
                   )
  , forVoice (
              other . forVoice
             )
{
    for each ( unsigned int row in other . waveTable )
        waveTable . add (
                         row
                        );
    selectedRow = waveTable . size ();
}


Wavetable::Wavetable (
        Wavetable&& other
        ) noexcept
    :
    waveTableIndex (
                    other . waveTableIndex
                   )
  , sustained (
               other . sustained
              )
  , released (
              other . released
             )
  , releaseCounter (
                    other . releaseCounter
                   )
  , forVoice (
              other . forVoice
             )
{
    for each ( unsigned int row in other . waveTable )
        waveTable . add (
                         row
                        );
    selectedRow = waveTable . size ();
}

Wavetable::~Wavetable ()
{
        SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > >()->remove(
            this
        );
        SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > >()->remove(
            this
        );
        SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > >()->remove(
            this
        );
        SharedResourcePointer < ListenerList < WavetableSelectionChanged > >()->remove(
            this
        );
        SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > >()->remove(
            this
        );
        SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > >()->remove(
            this
        );
        SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > >()->remove(
            this
        );

        wavetableRowChangedListeners->remove(
            this
        );
}

auto
    Wavetable::operator= (
            const Wavetable& other
            ) -> Wavetable&
{
    if ( &other == this )
    {
        return *this;
    }

    waveTableIndex = other . waveTableIndex;
    sustained      = other . sustained;
    released       = other . released;
    releaseCounter = other . releaseCounter;
    forVoice       = other . forVoice;

    for each ( unsigned int row in other . waveTable )
        waveTable . add (
                         row
                        );
    selectedRow = waveTable . size ();

    return *this;
}


auto
    Wavetable::operator= (
            Wavetable&& other
            ) noexcept -> Wavetable&
{
    if ( &other == this )
    {
        return *this;
    }

    waveTableIndex = other . waveTableIndex;
    sustained      = other . sustained;
    released       = other . released;
    releaseCounter = other . releaseCounter;
    forVoice       = other . forVoice;

    for each ( unsigned int row in other . waveTable )
        waveTable . add (
                         row
                        );
    selectedRow = waveTable . size ();

    return *this;
}


void
    Wavetable::Select (
            const bool value
            )
{
    if ( value )
    {
        SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> add (
                                                                                       this
                                                                                      );
        SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> add (
                                                                                        this
                                                                                       );
        SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> add (
                                                                                       this
                                                                                      );
        SharedResourcePointer < ListenerList < WavetableSelectionChanged > > () -> add (
                                                                                        this
                                                                                       );

        wavetableRowChangedListeners -> add (
                                             this
                                            );
    }
    else
    {
        SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> remove (
                                                                                          this
                                                                                         );
        SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> remove (
                                                                                           this
                                                                                          );
        SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> remove (
                                                                                          this
                                                                                         );
        SharedResourcePointer < ListenerList < WavetableSelectionChanged > > () -> remove (
                                                                                           this
                                                                                          );

        wavetableRowChangedListeners -> remove (
                                                this
                                               );
    }
}


void
    Wavetable::Write (  // NOLINT(readability-convert-member-functions-to-static)
            XmlElement* e
            ) const
{
    auto wt = e -> getChildByName (
                                   "wavetable"
                                  );
    if ( wt == nullptr )
    {
        wt = new XmlElement (
                             "wavetable"
                            );
        e -> addChildElement (
                              wt
                             );
    }

    wt -> deleteAllChildElements ();

    for each ( unsigned int v in waveTable )
    {
        if ( v < 0x100 )
        {
            auto row = new XmlElement (
                                       "row"
                                      );

            row -> setAttribute (
                                 "triangle"
                               , String (
                                         ( v & 0x10 ) == 0x10
                                        )
                                );
            row -> setAttribute (
                                 "sawtooth"
                               , String (
                                         ( v & 0x20 ) == 0x20
                                        )
                                );
            row -> setAttribute (
                                 "pulse"
                               , String (
                                         ( v & 0x40 ) == 0x40
                                        )
                                );
            row -> setAttribute (
                                 "noise"
                               , String (
                                         ( v & 0x80 ) == 0x80
                                        )
                                );
            row -> setAttribute (
                                 "test"
                               , String (
                                         ( v & 0x08 ) == 0x08
                                        )
                                );
            row -> setAttribute (
                                 "ring"
                               , String (
                                         ( v & 0x04 ) == 0x04
                                        )
                                );
            row -> setAttribute (
                                 "sync"
                               , String (
                                         ( v & 0x02 ) == 0x02
                                        )
                                );
            row -> setAttribute (
                                 "gate"
                               , String (
                                         ( v & 0x01 ) == 0x01
                                        )
                                );

            wt -> addChildElement (
                                   row
                                  );
        }
        else
        {
            auto command = new XmlElement (
                                           "command"
                                          );

            if ( ( v & 0x100 ) == 0x100 )
            {
                command -> setAttribute (
                                         "type"
                                       , "end"
                                        );
            }
            else if ( ( v & 0x200 ) == 0x200 )
            {
                command -> setAttribute (
                                         "type"
                                       , "goto"
                                        );
            }
            else if ( ( v & 0x400 ) == 0x400 )
            {
                command -> setAttribute (
                                         "type"
                                       , "sustain-to"
                                        );
            }

            if ( ( v & 0x100 ) != 0x100 )
            {
                command -> setAttribute (
                                         "argument"
                                       , String (
                                                 v & 0xff
                                                )
                                        );
            }

            wt -> addChildElement (
                                   command
                                  );
        }
    }
}


void
    Wavetable::WriteState (
            MemoryBlock& dest_data
            ) const
{
    unsigned int size = waveTable . size ();
    dest_data . append (
                        static_cast < const void* > ( &size )
                      , sizeof size
                       );

    for ( const auto& row : waveTable )
    {
        dest_data . append (
                            static_cast < const void* > ( &row )
                          , sizeof row
                           );
    }
}


void
// ReSharper disable once CppMemberFunctionMayBeStatic
    Wavetable::WriteCopyState (
            MemoryBlock& dest_data
            ) const {}


void
    Wavetable::LoadState (
            MemoryInputStream&                             stream
          , const ReferenceCountedObjectPtr < SidProgram > o
            )
{
    auto wt = o -> GetWavetable ();
    wt -> waveTable . clear ();

    unsigned int size;
    stream . read (
                   &size
                 , sizeof size
                  );

    for ( unsigned int i = 0 ; i < size ; i++ )
    {
        unsigned int row;
        stream . read (
                       &row
                     , sizeof row
                      );
        wt -> waveTable . add (
                               row
                              );
    }
}


void
    Wavetable::LoadCopyState (
            MemoryInputStream&                       stream
          , ReferenceCountedObjectPtr < SidProgram > o
            ) {}


auto
    Wavetable::GetWaveTableSize () const -> unsigned int
{
    return static_cast < unsigned int > ( waveTable . size () );
}


auto
    Wavetable::GetWaveTableEntryAt (
            const unsigned int index
            ) const -> unsigned int
{
    return waveTable [ static_cast < int > ( index ) ];
}


auto
    Wavetable::GetCurrentWaveTableEntry () const -> unsigned int
{
    return waveTable [ waveTableIndex ] & ( released
                                                ? RELEASE_MASK
                                                : UCHAR_MAX );
}


void
    Wavetable::AddWaveTableEntry (
            const unsigned int value
            )
{
    waveTable . add (
                     value
                    );
}


void
    Wavetable::InsertWaveTableEntryAt (
            const unsigned int index
          , const unsigned int value
            )
{
    waveTable . insert (
                        static_cast < int > ( index )
                      , value
                       );
}


void
    Wavetable::SetWaveTableEntryAt (
            const unsigned int index
          , const unsigned int value
            )
{
    waveTable . set (
                     static_cast < int > ( index )
                   , value
                    );
}


void
    Wavetable::RemoveWaveTableEntryAt (
            const unsigned int index
            )
{
    if ( waveTable . size () == 0 )
    {
        return;
    }
    waveTable . remove (
                        static_cast < int > ( index )
                       );
    Start ();
}


void
    Wavetable::Start ()
{
    waveTableIndex = -1;
    releaseCounter = 0;
    sustained      = false;
    released       = false;
}


// I need to calculate the frame counts for the various release values
// Of course, the frame counts are different for NTSC, but THAT is a future problem
//                  Attack Rate				 	        Decay/Release Rate
//	DEC 	HEX     (Time / Cycle) 	(Frames / Cycle)    (Time / Cycle)		(Frames / Cycle)
//	0	    (0)     2 mS	        1                   6 mS				1
//	1	    (1)     8 mS	        1                   24 mS				2
//	2	    (2)     16 mS	        1                   48 mS				3
//	3	    (3)     24 mS	        2                   72 mS				4
//	4	    (4)     38 mS	        2                   114 mS				6
//	5	    (5)     56 mS	        3                   168 mS				9
//	6	    (6)     68 mS	        4                   204 mS				11
//	7	    (7)     80 mS	        4                   240 mS				12
//	8	    (8)     100 mS	        5                   300 mS				15
//	9	    (9)     250 mS	        13                  750 mS				38
//	10	    (A)     500 mS	        25                  1.5 S				75
//	11	    (B)     800 mS	        40                  2.4 S				120
//	12	    (C)     1 S	            50                  3 S					150
//	13	    (D)     3 S	            150                 9 S					450
//	14	    (E)     5 S	            250                 15 S				750
//	15	    (F)     8 S	            400                 24 S				1200
// mS adjusted for PAL
//2.0299457598		6.0898372795
//8.1197830394		24.3593491182
//16.2395660788		48.7186982364
//24.3593491182		73.0780473546
//38.5689694371		115.7069083114
//56.8384812758		170.5154438273
//69.0181558349		207.0544675046
//81.197830394		243.5934911819
//101.4972879925	304.4918639774
//253.7432199812	761.2296599435
//507.4864399623	1522.459319887
//811.9783039397	2435.9349118192
//1014.9728799247	3044.918639774
//3044.918639774	9134.7559193218
//5074.8643996233	15224.5931988697
//8119.7830393972	24359.3491181916

void
    Wavetable::Step ()
{
    if ( Released () && DoneReleasing () )
    {
        return;
    }
    waveTableIndex++;
    if ( waveTableIndex == static_cast < unsigned int > ( waveTable . size () ) )
    {
        waveTableIndex--;
    }
    if ( ( waveTable [ waveTableIndex ] & END_COMMAND ) == END_COMMAND )
    {
        waveTableIndex--;
    }
    else if ( ( waveTable [ waveTableIndex ] & GOTO_COMMAND ) == GOTO_COMMAND )
    {
        waveTableIndex = static_cast < int > ( waveTable [ waveTableIndex ] ) & UCHAR_MAX;
    }
    else if ( ( waveTable [ waveTableIndex ] & SUSTAIN_TO_COMMAND ) == SUSTAIN_TO_COMMAND )
    {
        sustained = true;
        if ( !released )
        {
            waveTableIndex = static_cast < int > ( waveTable [ waveTableIndex ] ) & UCHAR_MAX;
        }
        else
        {
            waveTableIndex++;
        }

        if ( waveTableIndex == static_cast < unsigned int > ( waveTable . size () ) )
        {
            waveTableIndex -= 2;
        }
    }

    if ( releaseCounter > 0 )
    {
        releaseCounter--;
    }
}


void
    Wavetable::Release (
            const unsigned int release
            )
{
    releaseCounter = DECAY_RELEASE_FRAMES [ release ];
    released       = true;
}


auto
    Wavetable::Sustained () const -> bool
{
    return sustained;
}


auto
    Wavetable::Released () const -> bool
{
    return released;
}


auto
    Wavetable::DoneReleasing () const -> bool
{
    //if (!sustained && released) return true;

    return releaseCounter <= 0;
}


void
    Wavetable::onPatchEditorNewTableRowClicked ()
{
    if ( selectedRow < static_cast < unsigned int > ( waveTable . size () ) )
    {
        InsertWaveTableEntryAt (
                                selectedRow
                              , 0
                               );
    }
    else
    {
        AddWaveTableEntry (
                           0
                          );
    }
}


void
    Wavetable::onPatchEditorNewTableCommandClicked ()
{
    if ( selectedRow < static_cast < unsigned int > ( waveTable . size () ) )
    {
        InsertWaveTableEntryAt (
                                selectedRow
                              , END_COMMAND
                               );
    }
    else
    {
        AddWaveTableEntry (
                           END_COMMAND
                          );
    }
}


void
    Wavetable::onPatchEditorDeleteTableRowClicked ()
{
    RemoveWaveTableEntryAt (
                            selectedRow
                           );
}


void
    Wavetable::onWavetableRowChanged (
            const unsigned int value
            )
{
    SetWaveTableEntryAt (
                         selectedRow
                       , value
                        );
}


void
    Wavetable::onWavetableSelectionChanged (
            const unsigned int row
            )
{
    selectedRow = row;
}


void
    Wavetable::onPatchEditorShowNoteTable ()
{
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > > () -> remove (
                                                                                           this
                                                                                          );
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > () -> remove (
                                                                                               this
                                                                                              );
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > > () -> remove (
                                                                                              this
                                                                                             );
}


void
    Wavetable::onPatchEditorShowPulseTable ()
{
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > > () -> remove (
                                                                                           this
                                                                                          );
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > () -> remove (
                                                                                               this
                                                                                              );
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > > () -> remove (
                                                                                              this
                                                                                             );
}


void
    Wavetable::onPatchEditorShowWaveTable ()
{
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > > () -> add (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > () -> add (
                                                                                            this
                                                                                           );
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > > () -> add (
                                                                                           this
                                                                                          );
}


void
    Wavetable::SetForVoice (
            const int value
            )
{
    forVoice = value;
}
