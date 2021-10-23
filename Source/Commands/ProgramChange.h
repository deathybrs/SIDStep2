#pragma once
#include "UnsignedShortCommand.h"

class ProgramChange final : public UnsignedShortCommand
{
public:
    ProgramChange (
            const double         time
          , const unsigned short value
            )
        :
        UnsignedShortCommand (
                              time
                            , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_PROGRAM; }
};
