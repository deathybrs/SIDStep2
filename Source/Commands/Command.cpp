#include "Command.h"


#include "Attack.h"
#include "Cutoff.h"
#include "Decay.h"
#include "Filter.h"
#include "FilterType.h"
#include "Note.h"
#include "Pattern.h"
#include "PitchBend.h"
#include "ProgramChange.h"
#include "PulseWidth.h"
#include "Release.h"
#include "Resonance.h"
#include "Sustain.h"
#include "TremoloAmount.h"
#include "TremoloSpeed.h"
#include "VibratoAmount.h"
#include "VibratoSpeed.h"
#include "Volume.h"


#include "../SIDEvent.h"


Command::Command (
        const double time
        )
    :
    time (
          time ) {}

auto
    Command::GetTime () const -> double { return time; }

void
    Command::SetTime (
            const double value
            ) { time = value; }

auto
    Command::CreateCommand (
            const bool global
          , SidEvent*  event
          , const int  channel
            ) -> Command*
{
    const auto command = event -> command;
    const auto t       = event -> time;
    const auto v       = event -> values [ 0 ];
    if ( global )
    {
        switch ( command )
        {
            case SG_CUTOFF:
                return new Cutoff (
                                   t
                                 , static_cast < unsigned short > ( v ) );
            case SG_RESONANCE:
                return new Resonance (
                                      t
                                    , static_cast < unsigned char > ( v ) );
            case SG_FILTER_TYPE:
                return new FilterType (
                                       t
                                     , static_cast < unsigned char > ( v ) );
            case SG_VOLUME:
                return new Volume (
                                   t
                                 , static_cast < unsigned char > ( v ) );
            case SG_PATTERN:
                return new Pattern (
                                    t
                                  , static_cast < unsigned short > ( v )
                                  , static_cast < unsigned char > ( channel ) );
            default:
                return nullptr;
        }
    }
    switch ( command )
    {
        case SC_NOTE:
            return new Note (
                             t
                           , static_cast < unsigned short > ( v )
                           , event -> duration );
        case SC_PULSE_WIDTH:
            return new PulseWidth (
                                   t
                                 , static_cast < unsigned short > ( v ) );
        case SC_ATTACK:
            return new Attack (
                               t
                             , static_cast < unsigned char > ( v ) );
        case SC_DECAY:
            return new Decay (
                              t
                            , static_cast < unsigned char > ( v ) );
        case SC_SUSTAIN:
            return new Sustain (
                                t
                              , static_cast < unsigned char > ( v ) );
        case SC_RELEASE:
            return new Release (
                                t
                              , static_cast < unsigned char > ( v ) );
        case SC_FILTER:
            return new Filter (
                               t
                             , static_cast < unsigned char > ( v ) );
        case SC_PITCH_BEND:
            return new PitchBendCommand (
                                         t
                                       , static_cast < short > ( v ) );
        case SC_VIB_AMT:
            return new VibratoAmount (
                                      t
                                    , static_cast < unsigned short > ( v ) );
        case SC_VIB_SPD:
            return new VibratoSpeed (
                                     t
                                   , static_cast < unsigned short > ( v ) );
        case SC_TREMOLO_AMT:
            return new TremoloAmount (
                                      t
                                    , static_cast < unsigned short > ( v * USHRT_MAX ) );
        case SC_TREMOLO_SPD:
            return new TremoloSpeed (
                                     t
                                   , static_cast < unsigned short > ( v * USHRT_MAX ) );
        case SC_PROGRAM:
            return new ProgramChange (
                                      t
                                    , static_cast < unsigned short > ( v ) );
        default:
            return nullptr;
    }
}
