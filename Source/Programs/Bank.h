#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED


#include <JuceHeader.h>


#include "Categories.h"

#include "../Listeners/ListenerInitializer.h"


class SID;

class SharedProperties;
struct Note;


class Bank
        : public ReferenceCountedObject ,
          public BankNew ,
          public BankLoad ,
          public BankSave ,
          public BankSaveAs ,
          public BankRefreshLive ,
          public SampleRateChanged ,
          public LivePatchSelected
{
public:
    Bank ();

    ~Bank ();

    void
        Generate (
                MidiBuffer&                         midiMessages
              , AudioSampleBuffer&                  buffer
              , AudioPlayHead::CurrentPositionInfo& positionInfo
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
                double newRate
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
        dirtyWrite (
                int index
                );

    void
        dirtyWrite (
                int index
              , int value
                );

    static String
        getCategoryElementName (
                Category c
                );

    ScopedPointer < SID > sid;

    ReferenceCountedObjectPtr < SidProgram > currentProgram;

    Array < Note >         notes;
    Array < unsigned int > releasedNotes;
    int                    arpIndex;

    Array < int >  registers;
    Array < bool > dirty;

    int    sampleRate;
    int    samplesPerFrame;
    double cyclesPerSample;
    long   sampleIndex;

    SharedResourcePointer < SharedProperties > properties;

    SharedResourcePointer < ListenerList < BankTreeChanged > >    bankTreeChangedListeners;
    SharedResourcePointer < ListenerList < BankProgramChanged > > bankProgramChangedListeners;
    SharedResourcePointer < ListenerList < BankNew > >            bankNewListeners;
    SharedResourcePointer < ListenerList < BankLoad > >           bankLoadListeners;
    SharedResourcePointer < ListenerList < BankSave > >           bankSaveListeners;
    SharedResourcePointer < ListenerList < BankStartSaveAs > >    bankStartSaveAsListeners;
    SharedResourcePointer < ListenerList < BankSaveAs > >         bankSaveAsListeners;
};


#endif  // BANK_H_INCLUDED
