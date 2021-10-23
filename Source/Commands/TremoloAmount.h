#pragma once
#include "UnsignedShortCommand.h"

class TremoloAmount final : public UnsignedShortCommand
{
public:
    TremoloAmount (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_TREMOLO_AMT; }
};
