/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "../Command.h"
#include "../Recorder.h"
#include "FrameRow.h"

//[/Headers]

#include "CommandView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CommandView::CommandView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1440, 40);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CommandView::~CommandView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CommandView::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CommandView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    CommandView::AttachRecording (
            std::shared_ptr < Recorder >& record
            )
{
    recording = record;
    MessageManager::callAsync (
                               [=] ()
                               {
                                   removeAllChildren ();
                                   rows . clear ();
                                   size_t max_frame = 0;
                                   if ( !recording -> globalCommands . empty () && recording -> globalCommands . at (
                                                                                                                     recording -> globalCommands . size () - 1 ) -> GetTime () > static_cast < long > ( max_frame ) )
                                   {
                                       max_frame = recording -> globalCommands . at (
                                                                                     recording -> globalCommands . size () - 1 ) -> GetTime ();
                                   }
                                   for ( auto voice = 0 ; voice < 3 ; voice++ )
                                   {
                                       if ( !recording -> voiceCommands . at (
                                                                              voice ) . empty () && recording -> voiceCommands . at (
                                                                                                                                     voice ) . at (
                                                                                                                                                   recording -> voiceCommands . at (
                                                                                                                                                                                    voice ) . size () - 1 ) -> GetTime () > static_cast < long > ( max_frame ) )
                                       {
                                           max_frame = recording -> voiceCommands . at (
                                                                                        voice ) . at (
                                                                                                      recording -> voiceCommands . at (
                                                                                                                                       voice ) . size () - 1 ) -> GetTime ();
                                       }
                                   }
                                   size_t                    next_global_frame = 0;
                                   std::array < size_t , 3 > next_voice_frames = {
                                           0
                                         , 0
                                         , 0
                                   };
                                   size_t                    current_global_index  = 0;
                                   std::array < size_t , 3 > current_voice_indices = {
                                           0
                                         , 0
                                         , 0
                                   };
                                   std::vector < std::vector < std::shared_ptr < Command > > >                    global_frames;
                                   std::array < std::vector < std::vector < std::shared_ptr < Command > > > , 3 > voice_frames;
                                   std::array < std::vector < size_t > , 4 >                                      widths;
                                   for ( size_t frame = 0 ; frame < max_frame ; frame++ )
                                   {
                                       std::vector < std::shared_ptr < Command > > global_frame;
                                       while ( current_global_index < recording -> globalCommands . size () && recording -> globalCommands . at (
                                                                                                                                                 current_global_index ) -> GetTime () == static_cast < long > ( frame ) )
                                       {
                                           global_frame . push_back (
                                                                     recording -> globalCommands . at (
                                                                                                       current_global_index ) );
                                           current_global_index++;
                                       }
                                       global_frames . push_back (
                                                                  global_frame );
                                       for ( size_t command_index = 0 ; command_index < global_frame . size () ; command_index++ )
                                       {
                                           const auto argument_count = global_frame . at (
                                                                                          command_index ) -> Render () . size ();
                                           if ( widths . at (
                                                             0 ) . size () <= command_index )
                                           {
                                               widths . at (
                                                            0 ) . push_back (
                                                                             argument_count );
                                           }
                                           else
                                           {
                                               if ( widths . at (
                                                                 0 ) . at (
                                                                           command_index ) < argument_count )
                                               {
                                                   widths . at (
                                                                0 ) . at (
                                                                          command_index ) = argument_count;
                                               }
                                           }
                                       }
                                       if ( current_global_index < recording -> globalCommands . size () )
                                       {
                                           next_global_frame = recording -> globalCommands . at (
                                                                                                 current_global_index ) -> GetTime ();
                                       }
                                       for ( size_t voice = 0 ; voice < 3 ; voice++ )
                                       {
                                           std::vector < std::shared_ptr < Command > > voice_frame;
                                           while ( current_voice_indices . at (
                                                                               voice ) < recording -> voiceCommands . at (
                                                                                                                          voice ) . size () && recording -> voiceCommands . at (
                                                                                                                                                                                voice ) . at (
                                                                                                                                                                                              current_voice_indices . at (
                                                                                                                                                                                                                          voice ) ) -> GetTime () == static_cast < long > ( frame ) )
                                           {
                                               voice_frame . push_back (
                                                                        recording -> voiceCommands . at (
                                                                                                         voice ) . at (
                                                                                                                       current_voice_indices . at (
                                                                                                                                                   voice ) ) );
                                               current_voice_indices . at (
                                                                           voice )++;
                                           }
                                           voice_frames . at (
                                                              voice ) . push_back (
                                                                                   voice_frame );
                                           for ( size_t command_index = 0 ; command_index < voice_frame . size () ; command_index++ )
                                           {
                                               const auto argument_count = voice_frame . at (
                                                                                             command_index ) -> Render () . size ();
                                               if ( widths . at (
                                                                 voice + 1 ) . size () <= command_index )
                                               {
                                                   widths . at (
                                                                voice + 1 ) . push_back (
                                                                                         argument_count );
                                               }
                                               else
                                               {
                                                   if ( widths . at (
                                                                     voice + 1 ) . at (
                                                                                       command_index ) < argument_count )
                                                   {
                                                       widths . at (
                                                                    voice + 1 ) . at (
                                                                                      command_index ) = argument_count;
                                                   }
                                               }
                                           }
                                           if ( current_voice_indices . at (
                                                                            voice ) < recording -> voiceCommands . at (
                                                                                                                       voice ) . size () )
                                           {
                                               next_voice_frames . at (
                                                                       voice ) = recording -> voiceCommands . at (
                                                                                                                  voice ) . at (
                                                                                                                                current_voice_indices . at (
                                                                                                                                                            voice ) ) -> GetTime ();
                                           }
                                       }
                                   }
                                   _ASSERT (
                                            global_frames.size() == max_frame );
                                   for ( size_t voice = 0 ; voice < 3 ; voice++ )
                                   {
                                       _ASSERT (
                                                global_frames.size() == voice_frames.at(voice).size() );
                                   }
                                   auto width = 0;
                                   for ( size_t frame = 0 ; frame < max_frame ; frame++ )
                                   {
                                       auto frame_row      = std::make_shared < FrameRow > ();
                                       auto voice_commands = std::array < std::vector < std::shared_ptr < Command > > , 3 > {
                                               voice_frames . at (
                                                                  0 ) . at (
                                                                            frame )
                                             , voice_frames . at (
                                                                  1 ) . at (
                                                                            frame )
                                             , voice_frames . at (
                                                                  2 ) . at (
                                                                            frame )
                                       };
                                       frame_row -> AttachRow (
                                                               frame
                                                             , widths
                                                             , global_frames . at (
                                                                                   frame )
                                                             , voice_commands );
                                       addAndMakeVisible (
                                                          *frame_row );
                                       frame_row -> setTopLeftPosition (
                                                                        0
                                                                      , static_cast < int > ( 40 * frame ) );
                                       width = frame_row -> getWidth ();
                                       rows . push_back (
                                                         frame_row );
                                   }
                                   setBounds (
                                              0
                                            , 0
                                            , width
                                            , static_cast < int > ( 40 * max_frame ) );
                               } );
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CommandView" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1440" initialHeight="40">
  <BACKGROUND backgroundColour="323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

