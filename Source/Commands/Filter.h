#pragma once
#include "NybbleCommand.h"

class Filter final : public NybbleCommand
{
public:
    Filter (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_FILTER; }
};
