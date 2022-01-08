#include "Command.h"

#include <utility>

Command::Command (
        const COMMANDS                type
      , const long                    time
      , std::vector < unsigned char > values
        )
    :
    type (
          type )
  , time (
          time )
  , values (
            std::move (
                       values ) ) {}

auto
    Command::operator== (
            Command& other
            ) -> bool
{
    if ( type != other . type ) { return false; }
    if ( time != other . time ) { return false; }
    if ( values . size () != other . values . size () ) { return false; }
    for ( size_t i = 0 ; i < values . size () ; i++ )
    {
        if ( values . at (
                          i ) != other . values . at (
                                                      i ) ) { return false; }
    }
    return true;
}

auto
    Command::operator!= (
            Command& other
            ) -> bool
{
    return !operator== (
                        other );
}

auto
    Command::GetType () const -> COMMANDS { return type; }

auto
    Command::GetTime () const -> long { return time; }

auto
    Command::Render () const -> std::vector < unsigned char >
{
    std::vector < unsigned char > ret;
    // ret.push_back(
    //                 static_cast < unsigned char > ( type ) );
    for ( auto value : values )
    {
        ret . push_back (
                         value );
    }
    return ret;
}
