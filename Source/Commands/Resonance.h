#pragma once
#include "NybbleCommand.h"

class Resonance final : public NybbleCommand
{
public:
    Resonance (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return GC_RESONANCE; }
};
