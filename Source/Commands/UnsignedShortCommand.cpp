#include "UnsignedShortCommand.h"

UnsignedShortCommand::UnsignedShortCommand (
        const double         time
      , const unsigned short value
        )
    :
    Command (
             time )
  , value (
           value ) {}

auto
    UnsignedShortCommand::ToBin () -> Array < unsigned char >
{
    Array < unsigned char > ret;
    auto                    first        = GetCommandByte ();
    const unsigned char     upper_nybble = ( value & 0xF00 ) >> 8;
    first |= upper_nybble;
    const unsigned char lower_byte = value & 0xFF;
    ret . add (
               first );
    ret . add (
               lower_byte );
    return ret;
}

auto
    UnsignedShortCommand::GetValue () const -> unsigned short { return value; }

void
    UnsignedShortCommand::SetValue (
            unsigned short value
            ) { this -> value = value; }
