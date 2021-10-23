#pragma once
#include "NybbleCommand.h"

class Attack final : public NybbleCommand
{
public:
    Attack (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_ATTACK; }
};
