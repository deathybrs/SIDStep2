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

    void
        MergePatches ();

    static auto
        GetOptions () -> Options;

    static auto
        GetFactoryOptions () -> Options;

    PropertiesFile                 factory;
    std::shared_ptr < XmlElement > merged;
};
