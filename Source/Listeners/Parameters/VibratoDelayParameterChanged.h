#pragma once


class VibratoDelayParameterChanged
{
public:
    virtual ~VibratoDelayParameterChanged () {}

    virtual void
        onVibratoDelayParameterChanged (
                unsigned int voice
              , unsigned int value
                ) = 0;
};
