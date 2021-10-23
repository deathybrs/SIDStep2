#include "PulseTable.h"


#include "Wavetable.h"

#include <array>

#include "../SIDProgram.h"


PulseTable::PulseTable ()
{
    table . add (
                 CYCLE_CENTER
                );
    table . add (
                 static_cast < unsigned int > ( END_COMMAND )
                );
}


PulseTable::PulseTable (
        XmlElement* e
        )
{
    for ( auto i = 0 ; i < e -> getNumChildElements () ; i++ )
    {
        const auto r = e -> getChildElement (
                                             i
                                            );
        auto new_row = END_COMMAND;

        if ( r -> getTagName () == "pulse-cycle" )
        {
            new_row = r -> getIntAttribute (
                                            "value"
                                           );
        }
        else if ( r -> getTagName () == "command" )
        {
            auto command_type = r -> getStringAttribute (
                                                         "type"
                                                        );
            if ( command_type == "end" )
            {
                new_row = END_COMMAND;
            }
            else if ( command_type == "goto" )
            {
                new_row = GOTO_COMMAND | r -> getIntAttribute (
                                                               "argument"
                                                              );
            }
            else if ( command_type == "sustain-to" )
            {
                new_row = SUSTAIN_TO_COMMAND | r -> getIntAttribute (
                                                                     "argument"
                                                                    );
            }
        }

        table . add (
                     new_row
                    );
    }
}


PulseTable::PulseTable (
        const PulseTable& other
        )
    :
    pulseTableIndex (
                     other . pulseTableIndex
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
  , selectedRow (
                 other . selectedRow
                )
  , forVoice (
              other . forVoice
             )
{
    for ( auto row : other . table )
    {
        table . add (
                     row
                    );
    }
}


PulseTable::PulseTable (
        PulseTable&& other
        ) noexcept
    :
    pulseTableIndex (
                     other . pulseTableIndex
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
  , selectedRow (
                 other . selectedRow
                )
  , forVoice (
              other . forVoice
             )
{
    for ( auto row : other . table )
    {
        table . add (
                     row
                    );
    }
    other . table . clear ();
}


auto
    PulseTable::operator= (
            const PulseTable& other
            ) -> PulseTable&
{
    if ( &other == this )
    {
        return *this;
    }

    pulseTableIndex = other . pulseTableIndex;
    sustained       = other . sustained;
    released        = other . released;
    releaseCounter  = other . releaseCounter;
    selectedRow     = other . selectedRow;
    forVoice        = other . forVoice;

    table . clear ();
    for ( auto row : other . table )
    {
        table . add (
                     row
                    );
    }

    return *this;
}


auto
    PulseTable::operator= (
            PulseTable&& other
            ) noexcept -> PulseTable&
{
    if ( &other == this )
    {
        return *this;
    }

    pulseTableIndex = other . pulseTableIndex;
    sustained       = other . sustained;
    released        = other . released;
    releaseCounter  = other . releaseCounter;
    selectedRow     = other . selectedRow;
    forVoice        = other . forVoice;

    table . clear ();
    for ( auto row : other . table )
    {
        table . add (
                     row
                    );
    }
    other . table . clear ();

    return *this;
}


void
    PulseTable::Select (
            const bool value
            )
{
    if ( value )
    {
        SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> add (
                                                                                        this
                                                                                       );
        SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> add (
                                                                                       this
                                                                                      );
        SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> add (
                                                                                       this
                                                                                      );
        SharedResourcePointer < ListenerList < PulseTableSelectionChanged > > () -> add (
                                                                                         this
                                                                                        );
        pulseTableRowChangedListeners -> add (
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
        SharedResourcePointer < ListenerList < PulseTableSelectionChanged > > () -> remove (
                                                                                            this
                                                                                           );
        pulseTableRowChangedListeners -> remove (
                                                 this
                                                );
    }
}


void
    PulseTable::Write (
            XmlElement* e
            ) const
{
    auto pt = e -> getChildByName (
                                   "pulsetable"
                                  );

    if ( pt == nullptr )
    {
        pt = new XmlElement (
                             "pulsetable"
                            );
        e -> addChildElement (
                              pt
                             );
    }

    pt -> deleteAllChildElements ();

    for ( auto pulse : table )
    {
        if ( ( pulse & COMMAND_NYBBLE_MASK ) == 0x0000 )
        {
            auto row = new XmlElement (
                                       "pulse-cycle"
                                      );
            row -> setAttribute (
                                 "value"
                               , String (
                                         pulse
                                        )
                                );

            pt -> addChildElement (
                                   row
                                  );
        }
        else
        {
            auto command = new XmlElement (
                                           "command"
                                          );
            if ( ( pulse & END_COMMAND ) == END_COMMAND )
            {
                command -> setAttribute (
                                         "type"
                                       , "end"
                                        );
            }
            else if ( ( pulse & GOTO_COMMAND ) == GOTO_COMMAND )
            {
                command -> setAttribute (
                                         "type"
                                       , "goto"
                                        );
            }
            else if ( ( pulse & SUSTAIN_TO_COMMAND ) == SUSTAIN_TO_COMMAND )
            {
                command -> setAttribute (
                                         "type"
                                       , "sustain-to"
                                        );
            }

            if ( ( pulse & END_COMMAND ) != END_COMMAND )
            {
                command -> setAttribute (
                                         "argument"
                                       , String (
                                                 pulse & ARGUMENT_NYBBLE_MASK
                                                )
                                        );
            }

            pt -> addChildElement (
                                   command
                                  );
        }
    }
}


void
    PulseTable::WriteState (
            MemoryBlock& dest_data
            ) const
{
    unsigned int size = table . size ();
    dest_data . append (
                        static_cast < const void* > ( &size )
                      , sizeof size
                       );

    for ( const auto& row : table )
    {
        const unsigned int row_size = sizeof ( unsigned int );
        dest_data . append (
                            static_cast < const void* > ( &row )
                          , row_size
                           );
    }
}


void
// ReSharper disable once CppMemberFunctionMayBeStatic
    PulseTable::WriteCopyState (
            MemoryBlock& dest_data
            ) const {}


void
    PulseTable::LoadState (
            MemoryInputStream&                             stream
          , const ReferenceCountedObjectPtr < SidProgram > o
            )
{
    auto nt = o -> GetPulseTable ();
    nt -> table . clear ();

    unsigned int count;
    stream . read (
                   &count
                 , sizeof count
                  );

    for ( unsigned int i = 0 ; i < count ; i++ )
    {
        unsigned int row;
        const unsigned int size = sizeof (unsigned int);
        stream . read (
                       &row
                     , size
                      );
        nt -> table . add (
                           row
                          );
    }
}


void
    PulseTable::LoadCopyState (
            MemoryInputStream&                       stream
          , ReferenceCountedObjectPtr < SidProgram > o
            ) {}


auto
    PulseTable::GetPulseTableSize () const -> unsigned
{
    return table . size ();
}


auto
    PulseTable::GetPulseTableEntryAt (
            const unsigned index
            ) const -> unsigned
{
    return table [ static_cast < int > ( index ) ];
}


auto
    PulseTable::GetCurrentPulseTableEntry () const -> unsigned
{
    if ( pulseTableIndex == -1 )
    {
        return CYCLE_CENTER;
    }

    return GetPulseTableEntryAt (
                                 pulseTableIndex
                                );
}


void
    PulseTable::AddPulseTableEntry (
            const unsigned value
            )
{
    table . add (
                 value
                );
}


void
    PulseTable::SetPulseTableEntryAt (
            const unsigned index
          , const unsigned       value
            )
{
    if ( table . size () > index )
    {
        table . set (
                     static_cast < int > ( index )
                   , value
                    );
    }
}


void
    PulseTable::InsertPulseTableEntryAt (
            const unsigned index
          , const unsigned       value
            )
{
    if ( table . size () > index )
    {
        table . insert (
                        static_cast < int > ( index )
                      , value
                       );
    }
}


void
    PulseTable::RemovePulseTableEntryAt (
            const unsigned index
            )
{
    if ( table . size () > index )
    {
        table . remove (
                        static_cast < int > ( index )
                       );
    }
}


void
    PulseTable::Start ()
{
    pulseTableIndex = -1;
    releaseCounter  = 0;
    sustained       = false;
    released        = false;
}


void
    PulseTable::Step ()
{
    if ( Released () && DoneReleasing () )
    {
        return;
    }
    pulseTableIndex++;
    if ( pulseTableIndex == static_cast < unsigned int > ( table . size () ) )
    {
        pulseTableIndex--;
    }
    const auto row = table [ pulseTableIndex ];
    if ( ( row & END_COMMAND ) == END_COMMAND )
    {
        pulseTableIndex--;
    }
    else if ( ( row & GOTO_COMMAND ) == GOTO_COMMAND )
    {
        pulseTableIndex = static_cast < int > ( table [ pulseTableIndex ] ) & ARGUMENT_NYBBLE_MASK;
    }
    else if ( ( row & SUSTAIN_TO_COMMAND ) == SUSTAIN_TO_COMMAND )
    {
        sustained = true;
        if ( !released )
        {
            pulseTableIndex = static_cast < int > ( table [ pulseTableIndex ] ) & ARGUMENT_NYBBLE_MASK;
        }
        else
        {
            pulseTableIndex++;
        }

        if ( pulseTableIndex == static_cast < unsigned int > ( table . size () ) )
        {
            pulseTableIndex -= 2;
        }
    }

    if ( releaseCounter > 0 )
    {
        releaseCounter--;
    }
}


void
    PulseTable::Release (
            const unsigned release
            )
{
    releaseCounter = Wavetable::DECAY_RELEASE_FRAMES [ release ];
    released       = true;
}


auto
    PulseTable::Sustained () const -> bool
{
    return sustained;
}


auto
    PulseTable::Released () const -> bool
{
    return released;
}


auto
    PulseTable::DoneReleasing () const -> bool
{
    return releaseCounter <= 0;
}


void
    PulseTable::SetForVoice (
            const int value
            )
{
    forVoice = value;
}


void
    PulseTable::onPatchEditorDeleteTableRowClicked ()
{
    RemovePulseTableEntryAt (
                             selectedRow
                            );
}


void
    PulseTable::onPatchEditorNewTableCommandClicked ()
{
    const unsigned int row = END_COMMAND;

    if ( selectedRow < static_cast < unsigned int > ( table . size () ) )
    {
        InsertPulseTableEntryAt (
                                 selectedRow
                               , row
                                );
    }
    else
    {
        AddPulseTableEntry (
                            row
                           );
    }
}


void
    PulseTable::onPatchEditorNewTableRowClicked ()
{
    const unsigned int row = 2048;
    if ( selectedRow < static_cast < unsigned int > ( table . size () ) )
    {
        InsertPulseTableEntryAt (
                                 selectedRow
                               , row
                                );
    }
    else
    {
        AddPulseTableEntry (
                            row
                           );
    }
}


void
    PulseTable::onPulseTableSelectionChanged (
            const unsigned row
            )
{
    selectedRow = row;
}


void
    PulseTable::onPulseTableRowChanged (
            const unsigned int value
            )
{
    SetPulseTableEntryAt (
                          selectedRow
                        , value
                         );
}


void
    PulseTable::onPatchEditorShowNoteTable ()
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
    PulseTable::onPatchEditorShowPulseTable ()
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
    PulseTable::onPatchEditorShowWaveTable ()
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
