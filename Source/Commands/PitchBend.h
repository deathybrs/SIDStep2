#pragma once
#include "SignedShortCommand.h"

class PitchBendCommand final : public SignedShortCommand
{
public:
    // for now, this reduces pitch bend from +/- 8191 to +/- 2091.
    // The negative bit is 0x800 of the value, it is translated internally by this class.
    PitchBendCommand (
            const double time
          , const short  value
            )
        :
        SignedShortCommand (
                            time
                          , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_PITCH_BEND; }
};
