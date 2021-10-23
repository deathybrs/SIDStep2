#pragma once
#include "UnsignedShortCommand.h"

class Note final : public UnsignedShortCommand
{
public:
    Note (
            const double         time
          , const unsigned short value
          , const double         duration
            )
        :
        UnsignedShortCommand (
                              time
                            , value )
      , duration (
                  duration ) {}

    auto
        GetCommandByte () -> unsigned char override { return CC_NOTE; }

    auto
        GetDuration () const -> double { return duration; }

private:
    double duration;
};
