#pragma once


class LiveVibratoDelayChanged
{
public:
    virtual ~LiveVibratoDelayChanged () {}

    virtual void
        onLiveVibratoDelayChanged (
                unsigned int voice
              , unsigned int value
                ) = 0;
};
