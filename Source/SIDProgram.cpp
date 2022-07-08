#include "../JuceLibraryCode/JuceHeader.h"

#include "SIDProgram.h"

SidProgram::SidProgram ()
    :
    name (
          "New Patch" )
  , envelope (
              new sEnvelope () )
  , noteTable (
               new NoteTable () )
  , pulseTable (
                new PulseTable () )
  , wavetable (
               new Wavetable () )
  , expression (
                new Expressions () )
{
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
}

SidProgram::SidProgram (
        XmlElement* e
        )
    :
    name (
          e -> getStringAttribute (
                                   "name" ) )
  , id (
        Uuid (
              e -> getStringAttribute (
                                       "id" ) ) )
  , envelope (
              new sEnvelope (
                             e -> getChildByName (
                                                  "envelope" ) ) )
  , noteTable (
               new NoteTable (
                              e -> getChildByName (
                                                   "notetable" ) ) )
  , pulseTable (
                new PulseTable (
                                e -> getChildByName (
                                                     "pulsetable" ) ) )
  , wavetable (
               new Wavetable (
                              e -> getChildByName (
                                                   "wavetable" ) ) )
  , expression (
                new Expressions (
                                 e -> getChildByName (
                                                      "expressions" ) ) )
  , factoryPreset (
                   e -> getBoolAttribute (
                                          "factory-preset" ) )
{
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
}

SidProgram::SidProgram (
        const SidProgram& other
        )
    :
    name (
          other . name )
  , id (
        Uuid (
              other . id ) )
  , envelope (
              new sEnvelope (
                             *other . envelope ) )
  , noteTable (
               new NoteTable (
                              *other . noteTable ) )
  , pulseTable (
                new PulseTable (
                                *other . pulseTable ) )
  , wavetable (
               new Wavetable (
                              *other . wavetable ) )
  , expression (
                new Expressions (
                                 *other . expression ) )
  , factoryPreset (
                   other . factoryPreset )
{
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
}

SidProgram::SidProgram (
        SidProgram&& other
        ) noexcept
    :
    name (
          std::move (
                     name ) )
  , id (
        Uuid (
              other . id ) )
  , envelope (
              std::move (
                         other . envelope ) )
  , noteTable (
               std::move (
                          other . noteTable ) )
  , pulseTable (
                std::move (
                           other . pulseTable ) )
  , wavetable (
               std::move (
                          other . wavetable ) )
  , expression (
                std::move (
                           other . expression ) )
  , factoryPreset (
                   other . factoryPreset )
{
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
}

SidProgram::~SidProgram ()
{
    Select (
            false );
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> remove (
                                                                                this );
    envelope   = nullptr;
    noteTable  = nullptr;
    pulseTable = nullptr;
    wavetable  = nullptr;
    expression = nullptr;
}

auto
    SidProgram::operator= (
            const SidProgram& other
            ) -> SidProgram&
{
    if ( &other == this ) { return *this; }
    name = String (
                   other . name );
    id = Uuid (
               other . id );
    envelope = new sEnvelope (
                              *other . envelope );
    noteTable = new NoteTable (
                               *other . noteTable );
    pulseTable = new PulseTable (
                                 *other . pulseTable );
    wavetable = new Wavetable (
                               *other . wavetable );
    expression = new Expressions (
                                  *other . expression );
    factoryPreset = other . factoryPreset;
    return *this;
}

auto
    SidProgram::operator= (
            SidProgram&& other
            ) noexcept -> SidProgram&
{
    if ( &other == this ) { return *this; }
    name = std::move (
                      other . name );
    id = Uuid (
               other . id );
    envelope = std::move (
                          other . envelope );
    noteTable = std::move (
                           other . noteTable );
    pulseTable = std::move (
                            other . pulseTable );
    wavetable = std::move (
                           other . wavetable );
    expression = std::move (
                            other . expression );
    factoryPreset = other . factoryPreset;
    return *this;
}

auto
    SidProgram::GetName () const -> String { return name; }

void
    SidProgram::SetName (
            const String value
            )
{
    name = String (
                   value );
}

auto
    SidProgram::GetId () const -> Uuid { return id; }

void
    SidProgram::ResetId () { id = Uuid (); }

void
    SidProgram::Write (
            XmlElement* e
            ) const
{
    e -> setAttribute (
                       "name"
                     , name );
    e -> setAttribute (
                       "id"
                     , id . toDashedString () );
    e -> setAttribute (
                       "factory-preset"
                     , String (
                               static_cast < int > ( false ) ) );
    e -> setAttribute (
                       "patch-version"
                     , String (
                               PATCH_VERSION ) );
    envelope -> write (
                       e );
    noteTable -> Write (
                        e );
    pulseTable -> Write (
                         e );
    wavetable -> Write (
                        e );
    expression -> write (
                         e );
}

void
    SidProgram::WriteState (
            MemoryBlock& dest_data
            ) const
{
    dest_data . append (
                        static_cast < const void* > ( &PATCH_VERSION )
                      , sizeof PATCH_VERSION );
    unsigned int name_length = name . length ();
    dest_data . append (
                        static_cast < const void* > ( &name_length )
                      , sizeof name_length );
    const char* name_string = name . getCharPointer ();
    dest_data . append (
                        static_cast < const void* > ( name_string )
                      , name_length );
    const auto   did       = id . toDashedString ();
    unsigned int id_length = did . length ();
    dest_data . append (
                        static_cast < const void* > ( &id_length )
                      , sizeof id_length );
    const char* id_string = did . getCharPointer ();
    dest_data . append (
                        static_cast < const void* > ( id_string )
                      , id_length );
    dest_data . append (
                        static_cast < const void* > ( &factoryPreset )
                      , sizeof factoryPreset );
    envelope -> writeState (
                            dest_data );
    noteTable -> WriteState (
                             dest_data );
    pulseTable -> WriteState (
                              dest_data );
    wavetable -> WriteState (
                             dest_data );
    expression -> writeState (
                              dest_data );
}

void
    SidProgram::WriteCopyState (
            MemoryBlock& dest_data
            ) const
{
    envelope -> writeCopyState (
                                dest_data );
    noteTable -> WriteCopyState (
                                 dest_data );
    pulseTable -> WriteCopyState (
                                  dest_data );
    wavetable -> WriteCopyState (
                                 dest_data );
    expression -> writeCopyState (
                                  dest_data );
}

auto
    SidProgram::LoadState (
            MemoryInputStream& stream
            ) -> ReferenceCountedObjectPtr < SidProgram >
{
    ReferenceCountedObjectPtr < SidProgram > p (
                                                new SidProgram () );
    int version;
    stream . read (
                   &version
                 , sizeof version );
    if ( version < 1 || version > PATCH_VERSION ) { return nullptr; }
    unsigned int name_length;
    stream . read (
                   &name_length
                 , sizeof name_length );
    const auto name_string = new char[name_length + 1];
    stream . read (
                   name_string
                 , static_cast < int > ( name_length ) );
    name_string [ name_length ] = 0; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    p -> name                   = String (
                                          name_string );
    delete[] name_string;
    unsigned int id_length;
    stream . read (
                   &id_length
                 , sizeof id_length );
    const auto id_string = new char[id_length + 1];
    stream . read (
                   id_string
                 , static_cast < int > ( id_length ) );
    id_string [ id_length ] = 0; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    p -> id                 = Uuid (
                                    id_string );
    delete[] id_string;
    stream . read (
                   &p -> factoryPreset
                 , sizeof p -> factoryPreset );
    sEnvelope::loadState (
                          stream
                        , p );
    NoteTable::LoadState (
                          stream
                        , p );
    PulseTable::LoadState (
                           stream
                         , p );
    Wavetable::LoadState (
                          stream
                        , p );
    Expressions::loadState (
                            stream
                          , p );
    return p;
}

auto
    SidProgram::LoadCopyState (
            MemoryInputStream&                             stream
          , const ReferenceCountedObjectPtr < SidProgram > original
            ) -> ReferenceCountedObjectPtr < SidProgram >
{
    ReferenceCountedObjectPtr < SidProgram > p (
                                                new SidProgram (
                                                                *original ) );
    sEnvelope::loadCopyState (
                              stream
                            , p );
    NoteTable::LoadCopyState (
                              stream
                            , p );
    PulseTable::LoadCopyState (
                               stream
                             , p );
    Wavetable::LoadCopyState (
                              stream
                            , p );
    Expressions::loadCopyState (
                                stream
                              , p );
    return p;
}

auto
    SidProgram::GetEnvelope () const -> ReferenceCountedObjectPtr < sEnvelope > { return envelope; }

auto
    SidProgram::GetNoteTable () const -> ReferenceCountedObjectPtr < NoteTable > { return noteTable; }

auto
    SidProgram::GetPulseTable () const -> ReferenceCountedObjectPtr < PulseTable > { return pulseTable; }

auto
    SidProgram::GetWavetable () const -> ReferenceCountedObjectPtr < Wavetable > { return wavetable; }

auto
    SidProgram::GetExpression () const -> ReferenceCountedObjectPtr < Expressions > { return expression; }

auto
    SidProgram::IsFactoryPreset () const -> bool { return factoryPreset; }

void
    SidProgram::Start () const
{
    noteTable -> Start ();
    pulseTable -> Start ();
    wavetable -> Start ();
    expression -> Start ();
}

void
    SidProgram::Step () const
{
    noteTable -> Step ();
    pulseTable -> Step ();
    wavetable -> Step ();
    expression -> Step ();
}

void
    SidProgram::Release () const
{
    noteTable -> Release (
                          envelope -> getRelease () );
    pulseTable -> Release (
                           envelope -> getRelease () );
    wavetable -> Release (
                          envelope -> getRelease () );
    expression -> Release ();
}

void
    SidProgram::Select (
            const bool value
            )
{
    selected = value;
    if ( value )
    {
        SharedResourcePointer < ListenerList < PatchEditorNameChanged > > () -> add (
                                                                                     this );
    }
    else
    {
        SharedResourcePointer < ListenerList < PatchEditorNameChanged > > () -> remove (
                                                                                        this );
    }
    envelope -> select (
                        value );
    noteTable -> Select (
                         value );
    pulseTable -> Select (
                          value );
    wavetable -> Select (
                         value );
    expression -> select (
                          value );
}

void
    SidProgram::SetForVoice (
            const int value
            )
{
    forVoice = value;
    envelope -> SetForVoice (
                             value );
    noteTable -> SetForVoice (
                              value );
    pulseTable -> SetForVoice (
                               value );
    wavetable -> SetForVoice (
                              value );
    expression -> setForVoice (
                               value );
}

void
    SidProgram::onBankProgramChanged (
            const String                                   old_id
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    if ( old_id != id . toDashedString () && program -> id . toDashedString () != id . toDashedString () )
    {
        if ( selected )
        {
            Select (
                    false );
        }
        return;
    }
    if ( selected ) { return; }
    if ( old_id == id . toDashedString () && old_id != program -> id . toDashedString () )
    {
        id = Uuid (
                   program -> id . toDashedString () );
    }
    if ( id . toDashedString () == program -> id . toDashedString () )
    {
        if ( !selected )
        {
            Select (
                    true );
        }
    }
}

void
    SidProgram::onPatchEditorNameChanged (
            const String value
            )
{
    SetName (
             value );
}
