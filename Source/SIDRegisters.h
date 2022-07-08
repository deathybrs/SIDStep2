// ReSharper disable CppInconsistentNaming
#pragma once


#include <JuceHeader.h>

#include "Defines.h"
#include "Note.h"
#include "SIDStep2.h"

#include "Listeners/ListenerInitializer.h"


class SID;
class SidStep2;


class SidRegisters final
        : public ReferenceCountedObject
        , public LiveCutoffChanged
        , public LiveResonanceChanged
        , public LiveVoiceFilterChanged
        , public LiveLowPassChanged
        , public LiveBandPassChanged
        , public LiveHighPassChanged
        , public LiveVolumeChanged
        , public LiveTitleChanged
        , public LiveArtistChanged
        , public LoadLivePatch
        , public CutoffParameterChanged
        , public ResonanceParameterChanged
        , public FilterVoiceParameterChanged
        , public LowPassParameterChanged
        , public BandPassParameterChanged
        , public HighPassParameterChanged
        , public VolumeParameterChanged
        , public NoteOn
        , public NoteOff
        , public QuarterNoteTick
        , public LiveExportArmed
        , public LiveDoneExporting
{
public:
    SidRegisters ();

    SidRegisters (
            SidRegisters& other
            ) = delete;

    SidRegisters (
            SidRegisters&& other
            ) = delete;

    ~SidRegisters () override;

    auto
        operator= (
                const SidRegisters& other
                ) -> SidRegisters& = delete;

    auto
        operator= (
                SidRegisters&& other
                ) -> SidRegisters& = delete;

    // Frequency ($d400-$d401 / $d407-$d408 /  $d40e-$d40f)
    void
        SetNote (
                unsigned int voice
              , unsigned int note
                );

    void
        onLiveDoneExporting () override;

    void
        onLiveExportArmed () override;

    void
        onLiveTitleChanged (
                String value
                ) override;

    void
        onLiveArtistChanged (
                String value
                ) override;

    // Filter Cutoff ($d415-$d416)
    SID_REGISTER (
                  unsigned int
                , LiveCutoffChanged
                , CutoffParameterChanged
                , { auto log_val = static_cast<unsigned int>( round(cutoff_base * pow(binary_base, 1.0/cutoff_divisor * ((static_cast<double>(value) / cutoff_range) - cutoff_offset)))); DirtyWrite(0x15, (log_val & 0x07)); DirtyWrite(0x16, (log_val & 0x7f8) >> 3); } )

    // Filter Resonance & Routing ($d417)
    SID_REGISTER (
                  unsigned int
                , LiveResonanceChanged
                , ResonanceParameterChanged
                , { DirtyWrite(0x17, ((registers[0x17] & 0x0f) | (value << 4))); } )
    VOICE_REGISTER (
                    bool
                  , LiveVoiceFilterChanged
                  , FilterVoiceParameterChanged
                  , { unsigned int bit = 1 << voice; if (value) DirtyWrite(0x17, (registers[0x17] | bit)); else DirtyWrite(0x17, (registers[0x17] & (0xff - bit))); } )

    // Filter Mode & Volume Control ($d418)
    SID_REGISTER (
                  bool
                , LiveLowPassChanged
                , LowPassParameterChanged
                , { if (value) DirtyWrite(0x18, (registers[0x18] | 0x10)); else DirtyWrite(0x18, (registers[0x18] & 0xef)); } )
    SID_REGISTER (
                  bool
                , LiveBandPassChanged
                , BandPassParameterChanged
                , { if (value) DirtyWrite(0x18, (registers[0x18] | 0x20)); else DirtyWrite(0x18, (registers[0x18] & 0xdf)); } )
    SID_REGISTER (
                  bool
                , LiveHighPassChanged
                , HighPassParameterChanged
                , { if (value) DirtyWrite(0x18, (registers[0x18] | 0x40)); else DirtyWrite(0x18, (registers[0x18] & 0xbf)); } )
    SID_REGISTER (
                  unsigned int
                , LiveVolumeChanged
                , VolumeParameterChanged
                , { DirtyWrite(0x18, ((registers[0x18] & 0xf0) | (value & 0xf))); } )

    void
        onNoteOn (
                unsigned int channel
              , unsigned int note
              , unsigned int velocity
                ) override;

    void
        onNoteOff (
                unsigned int channel
              , unsigned int note
              , unsigned int velocity
                ) override;

    void
        onLoadLivePatch (
                unsigned int                             voice
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    //void onLiveExportArmed() override;
    //void onLiveDoneExporting() override;
    void
        onQuarterNoteTick (
                unsigned int ppq
              , bool         playing
                ) override;

    auto
        ReadRegister (
                int index
                ) const -> int;

private:
    static const int register_array_size       = 0x19;
    static const int last_register             = 0x18;
    static const int low_nybble_max            = 0x0f;
    static const int _8_bits_max               = 0xff;
    static const int _7_bits_max               = 0x7f;
    static const int delay_bit                 = 0x80;
    static const int data_row_length           = 0x10;
    static const int voice_control_offset      = 4;
    static const int attack_decay_offset       = 5;
    static const int sustain_release_offset    = 6;
    static const int pulse_hi_nybble           = 0xf00;
    static const int pulse_hi_nybble_bit_shift = 8;
    static const int voice_register_offset     = 7;
    static const int wavetable_command_bitmask = 0xfe;
    static const int pulse_width_default       = 0x08;

    static constexpr double clock_freq          = 985248.0;
    static constexpr double sample_freq         = 44100.0;
    static constexpr double pass_freq           = 19845.0;
    static constexpr double cutoff_base         = 0.9995117188;
    static constexpr double binary_base         = 2.0;
    static constexpr double cutoff_divisor      = 0.0833333333;
    static constexpr double cutoff_range        = 2047.0;
    static constexpr double cutoff_offset       = 0.0833333333;
    static constexpr double middle_a            = 440.0;
    static constexpr double octave              = 12.0;
    static constexpr double note_middle_offset  = 69.0;
    static constexpr double binary_bit_13       = 4096.0;


    friend class SidStep2;


    void
        SetFrame (
                unsigned int frame
                );

    void
        SetLoopStart (
                unsigned int frame
                );

    void
        SetLoopEnd (
                unsigned int frame
                );

    void
        ProcessNotesOnOff (
                int v
                );

    void
        ProcessPulseWidth (
                int v
                );

    void
        WriteNotes (
                int v
                );

    void
        WriteRegisters ();

    void
        ReleaseProcessor (
                int v
                );

    void
        NotesOff (
                int v
                ) const;

    auto
        NotesMatchesReleasedNotes (
                int v
                ) const -> bool;

    void
        DirtyWrite (
                int                                       index
              , std::array < int , register_array_size >& row
                );

    void
        DirtyWrite (
                int index
              , int value
                );


    bool recording {
            false
    };
    FileChooser                                              fileBrowser;
    ScopedPointer < SID >                                    sid;
    ReferenceCountedArray < SidProgram >                     programs;
    OwnedArray < Array < Note > >                            notes;
    OwnedArray < OwnedArray < Array < unsigned int > > >     hardRestartReleasedNotesDelay;
    int                                                      hardRestartReleasedNotesDelayIndex;
    OwnedArray < Array < unsigned int > >                    releasedNotes;
    Array < int >                                            arpIndex;
    std::vector < std::array < int , register_array_size > > record;
    Array < int >                                            registers;
    Array < bool >                                           dirty;
    Array < int >                                            hardRestartCounter;
    String                                                   songTitle {
            ""
    };
    String songArtist {
            ""
    };
    unsigned int currentQuarterNote {
            0
    };
    std::vector < int > barFrames;
    unsigned int currentFrame {
            0
    };
    unsigned int lastFrame {
            0
    };
    unsigned int loopStart {
            0
    };
    unsigned int loopEnd {
            0
    };
};
