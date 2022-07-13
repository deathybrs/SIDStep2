#include "SharedProperties.h"


using namespace juce;


SharedProperties::SharedProperties ()
    :
    PropertiesFile (
                    GetOptions () )
  , factory (
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

void
    SharedProperties::MergePatches ()
{
    auto left = factory . getXmlValue (
                                       "patches" );
    auto right = getXmlValue (
                              " patches" );

    merged = std::make_shared < XmlElement > (
                                              "patches" );

    merged -> addChildElement (
                               new XmlElement (
                                               "basses" ) );
    merged -> addChildElement (
                               new XmlElement (
                                               "drums" ) );
    merged -> addChildElement (
                               new XmlElement (
                                               "leads" ) );
    merged -> addChildElement (
                               new XmlElement (
                                               "keys" ) );
    merged -> addChildElement (
                               new XmlElement (
                                               "pads" ) );
    merged -> addChildElement (
                               new XmlElement (
                                               "sfx" ) );
    merged -> addChildElement (
                               new XmlElement (
                                               "misc" ) );
    for ( auto i = 0 ; i < merged -> getNumChildElements () ; i++ )
    {
        const auto& category = merged -> getChildElement (
                                                          i ) -> getTagName ();
        const auto& leftCategory = left -> getChildByName (
                                                           category );
        for ( auto l = 0 ; l < leftCategory -> getNumChildElements () ; l++ )
        {
            const auto& patch = leftCategory -> getChildElement (
                                                                 l );
            // Thinking about it, this is a terrible way to do this because the
            // files are independently updateable, so merging them statically
            // will just make patches stop saving.
            //
            // Abandoning the effort for the time being, as this requires more thought to approach.
        }
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

auto
    SharedProperties::GetFactoryOptions () -> Options
{
    Options props;
    props . applicationName  = "SIDStep 2";
    props . filenameSuffix   = ".factory";
    props . commonToAllUsers = false;
    return props;
}
