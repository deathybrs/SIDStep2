#pragma once
#include "NybbleCommand.h"

class Decay final : public NybbleCommand
{
public:
    Decay (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_DECAY; }
};
