#pragma once
#include "UnsignedShortCommand.h"

class PulseWidth final : public UnsignedShortCommand
{
public:
    PulseWidth (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_PULSE_WIDTH; }
};
