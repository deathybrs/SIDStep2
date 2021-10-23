#pragma once
#include "UnsignedShortCommand.h"

class Cutoff final : public UnsignedShortCommand
{
public:
    Cutoff (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return GC_CUTOFF; }
};
