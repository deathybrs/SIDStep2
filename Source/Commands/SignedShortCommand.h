#pragma once
#include "Command.h"

class SignedShortCommand : public Command
{
public:
    SignedShortCommand (
            double time
          , short  value
            );

    Array < unsigned char >
        ToBin () override;

    short
        GetValue () const;

    void
        SetValue (
                short value
                );

private:
    short value;
};
