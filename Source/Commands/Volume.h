#pragma once
#include "NybbleCommand.h"

class Volume final : public NybbleCommand
{
public:
    Volume (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return GC_VOLUME; }
};
