#pragma once
#include "UnsignedShortCommand.h"

class VibratoSpeed final : public UnsignedShortCommand
{
public:
    VibratoSpeed (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_VIB_SPD; }
};
