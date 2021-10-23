// ReSharper disable CppInconsistentNaming
#pragma once
class WavetableRowChanged
{
public:
    virtual ~WavetableRowChanged () = default;

    virtual void
        onWavetableRowChanged (
                unsigned int value
                ) = 0;
};
