#pragma once


#include <JuceHeader.h>


class SharedProperties final : public PropertiesFile
{
public:
    SharedProperties ();

    auto
        GetPatches () const -> XmlElement*;

private:
    void
        InitializeProperties ();

    static auto
        GetOptions () -> Options;
};
