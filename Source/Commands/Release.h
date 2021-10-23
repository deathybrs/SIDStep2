#pragma once
#include "NybbleCommand.h"

class Release final : public NybbleCommand
{
public:
    Release (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_RELEASE; }
};
