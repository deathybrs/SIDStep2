#pragma once
#include "JuceHeader.h"
#include "Listeners/ListenerInitializer.h"
#include "Programs/Envelope.h"
#include "Programs/Expression.h"
#include "Programs/NoteTable.h"
#include "Programs/PulseTable.h"
#include "Programs/Wavetable.h"

class SidProgram final
        : public ReferenceCountedObject
        , public BankProgramChanged
        , public PatchEditorNameChanged
{
public:
    SidProgram ();

    explicit
        SidProgram (
                XmlElement* e
                );

    SidProgram (
            const SidProgram& other
            );

    SidProgram (
            SidProgram&& other
            ) noexcept;

    ~SidProgram () override;

    auto
        operator= (
                const SidProgram& other
                ) -> SidProgram&;

    auto
        operator= (
                SidProgram&& other
                ) noexcept -> SidProgram&;

    auto
        GetName () const -> String;

    void
        SetName (
                String value
                );

    auto
        GetId () const -> Uuid;

    void
        ResetId ();

    void
        Write (
                XmlElement* e
                ) const;

    void
        WriteState (
                MemoryBlock& dest_data
                ) const;

    void
        WriteCopyState (
                MemoryBlock& dest_data
                ) const;

    static auto
        LoadState (
                MemoryInputStream& stream
                ) -> ReferenceCountedObjectPtr < SidProgram >;

    static auto
        LoadCopyState (
                MemoryInputStream&                       stream
              , ReferenceCountedObjectPtr < SidProgram > original
                ) -> ReferenceCountedObjectPtr < SidProgram >;

    auto
        GetEnvelope () const -> ReferenceCountedObjectPtr < sEnvelope >;

    auto
        GetNoteTable () const -> ReferenceCountedObjectPtr < NoteTable >;

    auto
        GetPulseTable () const -> ReferenceCountedObjectPtr < PulseTable >;

    auto
        GetWavetable () const -> ReferenceCountedObjectPtr < Wavetable >;

    auto
        GetExpression () const -> ReferenceCountedObjectPtr < Expressions >;

    auto
        IsFactoryPreset () const -> bool;

    void
        Start () const;

    void
        Step () const;

    void
        Release () const;

    void
        Select (
                bool value
                );

    void
        SetForVoice (
                int value
                );

    void
        onPatchEditorNameChanged (
                String value
                ) override;

    void
        onBankProgramChanged (
                String                                   old_id
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

private:
    String                                    name;
    Uuid                                      id;
    ReferenceCountedObjectPtr < sEnvelope >   envelope;
    ReferenceCountedObjectPtr < NoteTable >   noteTable;
    ReferenceCountedObjectPtr < PulseTable >  pulseTable;
    ReferenceCountedObjectPtr < Wavetable >   wavetable;
    ReferenceCountedObjectPtr < Expressions > expression;
    bool                                      factoryPreset {
            false
    };
    bool selected {
            false
    };
    int              forVoice {};
    static const int PATCH_VERSION = 1;
};
