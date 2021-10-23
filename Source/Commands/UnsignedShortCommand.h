#pragma once
#include "Command.h"

class UnsignedShortCommand : public Command
{
public:
    UnsignedShortCommand (
            double         time
          , unsigned short value
            );

    Array < unsigned char >
        ToBin () override;

    unsigned short
        GetValue () const;

    void
        SetValue (
                unsigned short value
                );

private:
    unsigned short value;
};
