// ReSharper disable CppInconsistentNaming
#pragma once
class SampleRateChanged
{
public:
    virtual ~SampleRateChanged() = default;

    virtual void
        onSampleRateChanged (
                double newRate
                ) = 0;
};
