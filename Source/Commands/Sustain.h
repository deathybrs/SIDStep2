#pragma once
#include "NybbleCommand.h"

class Sustain final : public NybbleCommand
{
public:
    Sustain (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_SUSTAIN; }
};
