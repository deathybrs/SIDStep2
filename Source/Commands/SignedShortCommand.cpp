#include "SignedShortCommand.h"

SignedShortCommand::SignedShortCommand (
        const double time
      , const short  value
        )
    :
    Command (
             time )
  , value (
           value ) {}

auto
    SignedShortCommand::ToBin () -> Array < unsigned char >
{
    Array < unsigned char > ret;
    const auto              temp_value = static_cast < short > ( abs (
                                                                      value / 4 ) );
    auto          first        = GetCommandByte ();
    unsigned char upper_nybble = ( temp_value & 0x700 ) >> 8;
    if ( value < 0 ) { upper_nybble |= 0x8; }
    else { upper_nybble &= 0x7; }
    first |= upper_nybble;
    const unsigned char lower_byte = temp_value & 0xFF;
    ret . add (
               first );
    ret . add (
               lower_byte );
    return ret;
}

auto
    SignedShortCommand::GetValue () const -> short { return value; }

void
    SignedShortCommand::SetValue (
            short value
            ) { this -> value = value; }
