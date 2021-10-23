#pragma once
#include "Command.h"

class NybbleCommand : public Command
{
public:
    NybbleCommand (
            double        time
          , unsigned char value
            );

    auto
        ToBin () -> Array < unsigned char > override;

    auto
        GetValue () const -> unsigned char;

    void
        SetValue (
                unsigned char v
                );

private:
    unsigned char value;
};
