// ReSharper disable CppInconsistentNaming
#pragma once

class PulseTableSelectionChanged
{
public:
    virtual ~PulseTableSelectionChanged() = default;

    virtual void
        onPulseTableSelectionChanged (
                unsigned int row
                ) = 0;
};
