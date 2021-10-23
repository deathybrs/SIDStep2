#pragma once
#include "NybbleCommand.h"

class FilterType final : public NybbleCommand
{
public:
    FilterType (
            const double        time
          , const unsigned char value
            )
        :
        NybbleCommand (
                       time
                     , value ) {}

    auto
        GetCommandByte () -> unsigned char override { return GC_FILTER_TYPE; }
};
