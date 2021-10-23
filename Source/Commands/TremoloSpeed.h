#pragma once
#include "UnsignedShortCommand.h"

class TremoloSpeed final : public UnsignedShortCommand
{
public:
    TremoloSpeed (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_TREMOLO_SPD; }
};
