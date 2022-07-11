#pragma once
#include <JuceHeader.h>
#include "Categories.h"
#include "../Listeners/ListenerInitializer.h"


// ReSharper disable once CppInconsistentNaming
class SID;
class SharedProperties;
struct Note;

class Bank final
        : public ReferenceCountedObject
        , public BankNew
        , public BankLoad
        , public BankSave
        , public BankSaveAs
        , public BankRefreshLive
        , public SampleRateChanged
        , public LivePatchSelected
{
public:
    Bank (
            const std::shared_ptr < EventDispatcher >& dispatcher
            );

    ~Bank () override;

    void
        Generate (
                MidiBuffer&                         midi_messages
              , AudioSampleBuffer&                  buffer
              , AudioPlayHead::CurrentPositionInfo& position_info
                );

    void
        onBankNew () override;

    void
        onBankLoad (
                String id
                ) override;

    void
        onBankSave () override;

    void
        onBankSaveAs (
                Category category
                ) override;

    void
        onSampleRateChanged (
                double new_rate
                ) override;

    void
        onBankRefreshLive () override;

    void
        onLivePatchSelected (
                ReferenceCountedObjectPtr < SidProgram > program
                ) override;

private:
    void
        Frame ();

    void
        SetNote (
                unsigned int note
                );

    void
        ReleaseProcessor ();

    void
        NotesOff ();

    void
        DirtyWrite (
                int index
                );

    void
        DirtyWrite (
                int index
              , int value
                );

    static auto
        GetCategoryElementName (
                Category c
                ) -> String;

    std::shared_ptr < EventDispatcher >      dispatcher;
    std::shared_ptr < SID >                  sid;
    ReferenceCountedObjectPtr < SidProgram > currentProgram;
    Array < Note >                           notes;
    Array < unsigned int >                   releasedNotes;
    int                                      arpIndex {
            -1
    };
    Array < int >  registers;
    Array < bool > dirty;
    int            sampleRate {
            0
    };
    int samplesPerFrame {
            0
    };
    double cyclesPerSample {
            0
    };
    long sampleIndex {
            0
    };
    SharedResourcePointer < SharedProperties > properties;
    //SharedResourcePointer < ListenerList < BankTreeChanged > >    bankTreeChangedListeners;
    //SharedResourcePointer < ListenerList < BankProgramChanged > > bankProgramChangedListeners;
    //SharedResourcePointer < ListenerList < BankNew > >            bankNewListeners;
    //SharedResourcePointer < ListenerList < BankLoad > >           bankLoadListeners;
    //SharedResourcePointer < ListenerList < BankSave > >           bankSaveListeners;
    //SharedResourcePointer < ListenerList < BankStartSaveAs > >    bankStartSaveAsListeners;
    //SharedResourcePointer < ListenerList < BankSaveAs > >         bankSaveAsListeners;
};
