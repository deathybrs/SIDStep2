#pragma once
#include "UnsignedShortCommand.h"

class VibratoAmount final : public UnsignedShortCommand
{
public:
    VibratoAmount (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_VIB_AMT; }
};
