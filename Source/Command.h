#pragma once
#include <vector>

enum class COMMANDS
{
    /*VOICE_FILTER_ON_OFF
  , */CUTOFF /*
  , RESONANCE
  , SET_FILTER_TYPE
  , VOLUME*/
  , RESONANCE_ROUTING
  , FILTER_MODE_VOLUME
  , DELAY
  , PROGRAM_CHANGE
  , NOTE_ON
  , NOTE_OFF
  , PITCH_BEND
  , PULSE_WIDTH
  , CHANGE_ATTACK_DECAY
  , CHANGE_SUSTAIN_RELEASE
  , VIBRATO_AMOUNT
  , VIBRATO_SPEED
  , VIBRATO_DELAY
};

class Command
{
public:
    explicit
        Command (
                COMMANDS                      type
              , long                          time
              , std::vector < unsigned char > values
                );

    Command (
            const Command& other
            ) = delete;

    Command (
            Command&& other
            ) = delete;

    ~Command () = default;

    auto
        operator= (
                const Command& other
                ) -> Command& = delete;

    auto
        operator= (
                Command&& other
                ) -> Command& = delete;

    auto
        operator== (
                Command& other
                ) -> bool;

    auto
        operator!= (
                Command& other
                ) -> bool;

    auto
        GetType () const -> COMMANDS;

    auto
        GetTime () const -> long;

    auto
        Render () const -> std::vector < unsigned char >;

private:
    COMMANDS                      type;
    long                          time;
    std::vector < unsigned char > values;
};
