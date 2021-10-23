// ReSharper disable CppInconsistentNaming
#pragma once
class WavetableSelectionChanged
{
public:
    virtual ~WavetableSelectionChanged () = default;

    virtual void
        onWavetableSelectionChanged (
                unsigned int row
                ) = 0;
};
