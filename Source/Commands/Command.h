#pragma once


#include "JuceHeader.h"


struct SidEvent;
class SidProgram;


enum GLOBAL_COMMANDS
{
    GC_CUTOFF = 0x00
  , GC_RESONANCE = 0x10
  , GC_FILTER_TYPE = 0x20
  , GC_VOLUME = 0x30
  , GC_PATTERN = 0x40
};


enum CHANNEL_COMMANDS
{
    CC_NOTE = 0x00
  , CC_PULSE_WIDTH = 0x10
  , CC_ATTACK = 0x20
  , CC_DECAY = 0x30
  , CC_SUSTAIN = 0x40
  , CC_RELEASE = 0x50
  , CC_FILTER = 0x60
  , CC_PITCH_BEND = 0x70
  , CC_VIB_AMT = 0x80
  , CC_VIB_SPD = 0x90
  , CC_TREMOLO_AMT = 0xa0
  , CC_TREMOLO_SPD = 0xb0
  , CC_PROGRAM = 0xc0
};

enum SWITCH_GLOBALS
{
    SG_CUTOFF = 0x0
  , SG_RESONANCE = 0x1
  , SG_FILTER_TYPE = 0x2
  , SG_VOLUME = 0x3
  , SG_PATTERN = 0x4
};

enum SWITCH_COMMANDS
{
    SC_NOTE = 0x00
  , SC_PULSE_WIDTH = 0x1
  , SC_ATTACK = 0x2
  , SC_DECAY = 0x3
  , SC_SUSTAIN = 0x4
  , SC_RELEASE = 0x5
  , SC_FILTER = 0x6
  , SC_PITCH_BEND = 0x7
  , SC_VIB_AMT = 0x8
  , SC_VIB_SPD = 0x9
  , SC_TREMOLO_AMT = 0xA
  , SC_TREMOLO_SPD = 0xB
  , SC_PROGRAM = 0xC
};


class Command
{
public:
    explicit
        Command (
                double time
                );

    virtual ~Command () = default;

    Command (
            const Command& other
            ) = default;

    Command (
            Command&& other
            ) = default;

    auto
        operator= (
                const Command& other
                ) -> Command& = default;

    auto
        operator= (
                Command&& other
                ) -> Command& = default;

    virtual auto
        ToBin () -> Array < unsigned char > = 0;

    virtual auto
        GetCommandByte () -> unsigned char = 0;


    auto
        GetTime () const -> double;


    void
        SetTime (
                double value
                );


    static auto
        CreateCommand (
                bool                                  global
              , SidEvent*                             event
              , int                                   channel = -1
                ) -> Command*;

private:
    double time;
};
