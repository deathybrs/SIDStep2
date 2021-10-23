#include "SharedProperties.h"


using namespace juce;


SharedProperties::SharedProperties ()
    :
    PropertiesFile (
                    GetOptions () ) { InitializeProperties (); }

auto
    SharedProperties::GetPatches () const -> XmlElement*
{
    return getXmlValue (
                        "patches" );
}

void
    SharedProperties::InitializeProperties ()
{
    ScopedPointer < XmlElement > patches_element = GetPatches ();
    if ( patches_element == nullptr )
    {
        // Once some presets are written, then they'll be embedded and initially written out here
        patches_element = new XmlElement (
                                          "patches" );
        setValue (
                  "patches"
                , patches_element );
    }
    if ( patches_element -> getNumChildElements () == 0 )
    {
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "basses" ) );
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "drums" ) );
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "leads" ) );
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "keys" ) );
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "pads" ) );
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "sfx" ) );
        patches_element -> addChildElement (
                                            new XmlElement (
                                                            "misc" ) );
    }
}

auto
    SharedProperties::GetOptions () -> Options
{
    Options props;
    props . applicationName  = "SIDStep 2";
    props . filenameSuffix   = ".bank";
    props . commonToAllUsers = false;
    return props;
}
