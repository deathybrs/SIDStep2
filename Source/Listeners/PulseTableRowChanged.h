// ReSharper disable CppInconsistentNaming
#pragma once
class PulseTableRowChanged
{
public:
    virtual ~PulseTableRowChanged () = default;

    virtual void
        onPulseTableRowChanged (
                unsigned int value
                ) = 0;
};
