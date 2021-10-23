#include "NybbleCommand.h"

NybbleCommand::NybbleCommand (
        const double        time
      , const unsigned char value
        )
    :
    Command (
             time )
  , value (
           value ) {}

auto
    NybbleCommand::ToBin () -> Array < unsigned char >
{
    Array < unsigned char > ret;
    auto byte   = GetCommandByte ();
    const unsigned char     nybble = value & 0xF;
    byte |= nybble;
    ret . add (
               byte );
    return ret;
}

auto
    NybbleCommand::GetValue () const -> unsigned char { return value; }

void
    NybbleCommand::SetValue (
            const unsigned char v
            ) { value = v; }
