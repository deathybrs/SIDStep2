#pragma once


#include "JuceHeader.h"


struct SidEvent
{
    // time in beats
    double          time;
    double          duration;
    unsigned int    command;
    Array < float > values;

    static auto
    // ReSharper disable once CppInconsistentNaming
        compareElements (
                SidEvent* a
              , SidEvent* b
                ) -> int
    {
        if ( a -> time != b -> time ) { return a -> time - b -> time; }
        if ( a -> command != b -> command )
        {
            if ( a -> command == 12 ) { return -1; }
            if ( b -> command == 12 ) { return 1; }
            if ( a -> command == 6 ) { return -1; }
            if ( b -> command == 6 ) { return 1; }
            if ( a -> command == 2 ) { return -1; }
            if ( b -> command == 2 ) { return 1; }
            if ( a -> command == 3 ) { return -1; }
            if ( b -> command == 3 ) { return 1; }
            if ( a -> command == 4 ) { return -1; }
            if ( b -> command == 4 ) { return 1; }
            if ( a -> command == 5 ) { return -1; }
            if ( b -> command == 5 ) { return 1; }
            if ( a -> command == 1 ) { return -1; }
            if ( b -> command == 1 ) { return 1; }
            if ( a -> command == 0 ) { return -1; }
            if ( b -> command == 0 ) { return 1; }
            return a -> command - b -> command;
        }
        return 0;
    }
};
