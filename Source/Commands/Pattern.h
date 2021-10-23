#pragma once
#include "UnsignedShortCommand.h"

class Pattern final : public UnsignedShortCommand
{
public:
    Pattern (
            double         time
          , unsigned short value
          , unsigned char  channel
            );

    auto
        ToBin () -> Array < unsigned char > override;

    auto
        GetCommandByte () -> unsigned char override;

    auto
        GetChannel () const -> unsigned char;

    void
        SetChannel (
                unsigned char value
                );

private:
    unsigned char channel;
};
