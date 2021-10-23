#pragma once


#include <JuceHeader.h>

#include "SIDProgram.h"

#include "Listeners/ListenerInitializer.h"


class SidRegisters;
class Renderer;
class Bank;


class SidStep2 final
        : public ReferenceCountedObject
        , public SampleRateChanged
        , public BankProgramChanged
        , public LiveTitleChanged
        , public LiveArtistChanged
        , public LivePatchEditorModeClicked
        , public LivePatchListMode
        , public LivePatchListSelectedIndexChanged
        , public LivePatchChanged
        , public LiveRemovePatchClicked
        , public ProgramParameterChanged
        , public PatchEditorLiveModeClicked
        , public LiveExportArmed
        , public LiveDoneExporting
{
public:
    SidStep2 ();

    ~SidStep2 () override;

    SidStep2 (
            SidStep2&& other
            ) = delete;

    auto
        operator= (
                SidStep2&& other
                ) -> SidStep2& = delete;

    void
        GetStateInformation (
                MemoryBlock& dest_data
                ) const;

    void
        SetStateInformation (
                const void* data
              , int         size_in_bytes
                );

    void
        Generate (
                MidiBuffer&                         midi_messages
              , AudioSampleBuffer&                  buffer
              , AudioPlayHead::CurrentPositionInfo& position_info
                );

    void
        onSampleRateChanged (
                double new_rate
                ) override;

    void
        onLivePatchEditorModeClicked () override;

    void
        onPatchEditorLiveModeClicked () override;

    void
        onLiveTitleChanged (
                String value
                ) override;

    void
        onLiveArtistChanged (
                String value
                ) override;

    void
        onBankProgramChanged (
                String                                   old_id
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    void
        onLivePatchListMode (
                int value
                ) override;

    void
        onLivePatchListSelectedIndexChanged (
                int value
                ) override;

    void
        onLiveRemovePatchClicked () override;

    void
        onLiveExportArmed () override;

    void
        onLiveDoneExporting () override;

    VOICE_REGISTER (
                    unsigned int
                  , LivePatchChanged
                  , ProgramParameterChanged
                  , { if (value >= static_cast<unsigned int>(programs.size())) return; channelProgramCopies[voice]->getObjectPointer(currentChannelProgram[voice])->SetForVoice(-1); currentChannelProgram.set(voice, value); channelProgramCopies[voice]->getObjectPointer(currentChannelProgram[voice])->SetForVoice(voice); SharedResourcePointer<ListenerList<LoadLivePatch>>()->call(&LoadLivePatch::onLoadLivePatch, voice, channelProgramCopies[voice]->getObjectPointer(currentChannelProgram[voice])); } )


private:
    static const int SIXTEEN_BIT = 0x8000;
    static const int BUFFER_SIZE = 16;
    static const int FILTER_RES_ROUTE = 0x17;
    static const int VOLUME_FILTER_MODE = 0x18;
    static const int LOW_NYBBLE = 0x0f;

    static constexpr double CPU_FREQUENCY      = 985248.0;
    static constexpr double ONE_MINUTE         = 60.0;
    static constexpr double FRAME_RATE         = 50.0;
    static constexpr double FILTER_COEFFICIENT = 0.9;


    void
        Frame (
                unsigned frame
              , bool     playing = false
                );

    void
        ProcessVoice (
                int v
                ) const;

    void
        FirePatchListChanged () const;


    String                                              title;
    String                                              artist;
    ReferenceCountedObjectPtr < SidRegisters >          sidRegisters;
    ReferenceCountedObjectPtr < Bank >                  bank;
    ReferenceCountedArray < SidProgram >                programs;
    OwnedArray < ReferenceCountedArray < SidProgram > > channelProgramCopies;
    Array < int >                                       currentChannelProgram;
    int                                                 sampleRate;
    int                                                 samplesPerFrame;
    double                                              cyclesPerSample;
    long                                                sampleIndex;
    bool                                                live;
    int                                                 patchListMode;
    int                                                 patchSelectionIndex;
    bool                                                recording;
    bool                                                armed;
    double                                              tempo {};
    unsigned lastFrame {
            UINT_MAX
    };


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  SidStep2 )
};
