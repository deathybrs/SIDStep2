#include "Expression.h"

#include <JuceHeader.h>


#include "../SIDProgram.h"


Expressions::Expressions (
        std::shared_ptr < EventDispatcher > dispatcher
        )
    : 
    dispatcher (
                dispatcher )
  , vibrato (
             new Vibrato (
                          dispatcher ) )
  , tremolo (
             new Tremolo () )
  , pitchBendRange (
                    8192 )
  , pulseWidthDefault (
                       0 )
  , pulseWidthRange (
                     2047 )
  , pulseWidthCenter (
                      2048 )
  , pulseOffset (
                 pulseWidthDefault )
  , currentPitchBend (
                      0 )
  , forVoice (
              -1 )
{
    dispatcher -> livePitchBendChangedListeners -> add (
                                                        this );
    dispatcher -> livePulseWidthChangedListeners -> add (
                                                         this );
    dispatcher -> pitchBendListeners -> add (
                                             this );
    dispatcher -> pitchBendParameterChangedListeners -> add (
                                                             this );
    dispatcher -> pulseWidthParameterChangedListeners -> add (
                                                              this );
}

Expressions::Expressions (
        std::shared_ptr < EventDispatcher > dispatcher
      , XmlElement*                         e
        )
    :
    dispatcher (
                dispatcher )
  , vibrato (
             new Vibrato (
                          dispatcher
                        , e -> getChildByName (
                                               "vibrato" ) ) )
  , tremolo (
             new Tremolo (
                          e -> getChildByName (
                                               "tremolo" ) ) )
  , pitchBendRange (
                    static_cast < unsigned int > ( e -> getIntAttribute (
                                                                         "pitch-bend-range" ) ) )
  , pulseWidthDefault (
                       static_cast < float > ( e -> getDoubleAttribute (
                                                                        "pulse-width-default" ) ) )
  , pulseWidthRange (
                     static_cast < unsigned int > ( e -> getIntAttribute (
                                                                          "pulse-width-range" ) ) )
  , pulseWidthCenter (
                      static_cast < unsigned int > ( e -> getIntAttribute (
                                                                           "pulse-width-center" ) ) )
  , pulseOffset (
                 pulseWidthDefault )
  , currentPitchBend (
                      0 )
  , forVoice (
              -1 )
{
    dispatcher -> livePitchBendChangedListeners -> add (
                                                        this );
    dispatcher -> livePulseWidthChangedListeners -> add (
                                                         this );
    dispatcher -> pitchBendListeners -> add (
                                             this );
    dispatcher -> pitchBendParameterChangedListeners -> add (
                                                             this );
    dispatcher -> pulseWidthParameterChangedListeners -> add (
                                                              this );
}

Expressions::Expressions (
        Expressions& original
        )
    :
    dispatcher (
                original . dispatcher )
  , vibrato (
             new Vibrato (
                          *original . vibrato ) )
  , tremolo (
             new Tremolo (
                          *original . tremolo ) )
  , pitchBendRange (
                    original . pitchBendRange )
  , pulseWidthDefault (
                       original . pulseWidthDefault )
  , pulseWidthRange (
                     original . pulseWidthRange )
  , pulseWidthCenter (
                      original . pulseWidthCenter )
  , pulseOffset (
                 pulseWidthDefault )
  , currentPitchBend (
                      0 )
  , forVoice (
              -1 )
{
    dispatcher -> livePitchBendChangedListeners -> add (
                                                        this );
    dispatcher -> livePulseWidthChangedListeners -> add (
                                                         this );
    dispatcher -> pitchBendListeners -> add (
                                             this );
    dispatcher -> pitchBendParameterChangedListeners -> add (
                                                             this );
    dispatcher -> pulseWidthParameterChangedListeners -> add (
                                                              this );
}

Expressions::~Expressions ()
{
    dispatcher -> livePitchBendChangedListeners -> remove (
                                                           this );
    dispatcher -> livePulseWidthChangedListeners -> remove (
                                                            this );
    dispatcher -> pitchBendListeners -> remove (
                                                this );
    dispatcher -> pitchBendParameterChangedListeners -> remove (
                                                                this );
    dispatcher -> pulseWidthParameterChangedListeners -> remove (
                                                                 this );
    vibrato = nullptr;
    //tremolo = nullptr;
}

void
    Expressions::select (
            bool value
            )
{
    if ( value )
    {
        dispatcher -> patchEditorPitchBendRangeChangedListeners -> add (
                                                                        this );
        dispatcher -> patchEditorPulseWidthRangeChangedListeners -> add (
                                                                         this );
        dispatcher -> patchEditorPulseWidthCenterChangedListeners -> add (
                                                                          this );
        dispatcher -> pitchBendListeners -> add (
                                                 this );
        dispatcher -> patchEditorPulseWidthDefaultChangedListeners -> add (
                                                                           this );
    }
    else
    {
        dispatcher -> patchEditorPitchBendRangeChangedListeners -> remove (
                                                                           this );
        dispatcher -> patchEditorPulseWidthRangeChangedListeners -> remove (
                                                                            this );
        dispatcher -> patchEditorPulseWidthCenterChangedListeners -> remove (
                                                                             this );
        dispatcher -> pitchBendListeners -> remove (
                                                    this );
        dispatcher -> patchEditorPulseWidthDefaultChangedListeners -> remove (
                                                                              this );
    }
    vibrato -> Select (
                       value );
    tremolo -> select (
                       value );
}

void
    Expressions::write (
            XmlElement* e
            ) const
{
    XmlElement* ex = e -> getChildByName (
                                          "expressions" );
    if ( ex == nullptr )
    {
        ex = new XmlElement (
                             "expressions" );
        e -> addChildElement (
                              ex );
    }
    ex -> setAttribute (
                        "pitch-bend-range"
                      , String (
                                pitchBendRange ) );
    ex -> setAttribute (
                        "pulse-width-range"
                      , String (
                                pulseWidthRange ) );
    ex -> setAttribute (
                        "pulse-width-center"
                      , String (
                                pulseWidthCenter ) );
    ex -> setAttribute (
                        "pulse-width-default"
                      , String (
                                pulseWidthDefault ) );
    vibrato -> Write (
                      ex );
    tremolo -> write (
                      ex );
}

void
    Expressions::writeState (
            MemoryBlock& destData
            ) const
{
    destData . append (
                       static_cast < const void* > ( &pitchBendRange )
                     , sizeof( pitchBendRange ) );
    destData . append (
                       static_cast < const void* > ( &pulseWidthDefault )
                     , sizeof( pulseWidthDefault ) );
    destData . append (
                       static_cast < const void* > ( &pulseWidthRange )
                     , sizeof( pulseWidthRange ) );
    destData . append (
                       static_cast < const void* > ( &pulseWidthCenter )
                     , sizeof( pulseWidthCenter ) );
    vibrato -> WriteState (
                           destData );
    tremolo -> writeState (
                           destData );
}

void
    Expressions::writeCopyState (
            MemoryBlock& destData
            ) const
{
    destData . append (
                       static_cast < const void* > ( &pulseOffset )
                     , sizeof( pulseOffset ) );
    destData . append (
                       static_cast < const void* > ( &currentPitchBend )
                     , sizeof( currentPitchBend ) );
    vibrato -> WriteCopyState (
                               destData );
    tremolo -> writeCopyState (
                               destData );
}

void
    Expressions::loadState (
            MemoryInputStream&                       stream
          , ReferenceCountedObjectPtr < SidProgram > o
            )
{
    ReferenceCountedObjectPtr < Expressions > ex = o -> GetExpression ();
    stream . read (
                   &ex -> pitchBendRange
                 , sizeof( ex -> pitchBendRange ) );
    stream . read (
                   &ex -> pulseWidthDefault
                 , sizeof( ex -> pulseWidthDefault ) );
    stream . read (
                   &ex -> pulseWidthRange
                 , sizeof( ex -> pulseWidthRange ) );
    stream . read (
                   &ex -> pulseWidthCenter
                 , sizeof( ex -> pulseWidthCenter ) );
    ex -> vibrato -> LoadState (
                                stream
                              , o );
    ex -> tremolo -> loadState (
                                stream
                              , o );
}

void
    Expressions::loadCopyState (
            MemoryInputStream&                       stream
          , ReferenceCountedObjectPtr < SidProgram > o
            )
{
    ReferenceCountedObjectPtr < Expressions > ex = o -> GetExpression ();
    stream . read (
                   &ex -> pulseOffset
                 , sizeof( ex -> pulseOffset ) );
    stream . read (
                   &ex -> currentPitchBend
                 , sizeof( ex -> currentPitchBend ) );
    ex -> vibrato -> LoadCopyState (
                                    stream
                                  , o );
    ex -> tremolo -> loadCopyState (
                                    stream
                                  , o );
}

ReferenceCountedObjectPtr < Vibrato >
    Expressions::getVibrato () const { return vibrato; }

ReferenceCountedObjectPtr < Tremolo >
    Expressions::getTremolo () const { return tremolo; }

unsigned int
    Expressions::getPitchBendRange () const { return pitchBendRange; }

void
    Expressions::setPitchBendRange (
            unsigned int value
            )
{
    if ( value < 8193 )
        pitchBendRange = value;
}

unsigned int
    Expressions::getPulseWidthRange () const { return pulseWidthRange; }

void
    Expressions::setPulseWidthRange (
            unsigned int value
            )
{
    if ( value < 4096 )
        pulseWidthRange = value;
}

unsigned int
    Expressions::getPulseWidthCenter () const { return pulseWidthCenter; }

void
    Expressions::setPulseWidthCenter (
            unsigned int value
            )
{
    if ( value < 4096 )
        pulseWidthCenter = value;
}

float
    Expressions::getPulseWidthDefault () const { return pulseWidthDefault; }

void
    Expressions::setPulseWidthDefault (
            float value
            )
{
    if ( value >= -1.0f && value <= 1.0f )
    {
        pulseWidthDefault = value;
        setPulseOffset (
                        value );
    }
}

float
    Expressions::getPulseOffset () const { return pulseOffset; }

void
    Expressions::setPulseOffset (
            float value
            ) { pulseOffset = value; }

float
    Expressions::getPitchBend () const { return currentPitchBend; }

void
    Expressions::setPitchBend (
            float value
            )
{
    if ( value < -1.0f || value > 1.0f )
        return;
    currentPitchBend = value;
}

unsigned int
    Expressions::getCurrentPulseValue () const
{
    int ret = static_cast < int > ( pulseOffset * pulseWidthRange + pulseWidthCenter );
    if ( ret < 0 )
        ret = 0;
    else if ( ret > 4095 )
        ret = 4095;
    return ret;
}

void
    Expressions::Start () const
{
    vibrato -> Start ();
    tremolo -> Start ();
}

void
    Expressions::Step () const
{
    vibrato -> Step ();
    tremolo -> Step ();
}

void
    Expressions::Release () const
{
    vibrato -> Release ();
    tremolo -> Release ();
}

void
    Expressions::onPatchEditorPitchBendRangeChanged (
            unsigned int value
            )
{
    setPitchBendRange (
                       value );
}

void
    Expressions::onPatchEditorPulseWidthRangeChanged (
            unsigned int value
            )
{
    setPulseWidthRange (
                        value );
}

void
    Expressions::onPatchEditorPulseWidthCenterChanged (
            unsigned int value
            )
{
    setPulseWidthCenter (
                         value );
}

void
    Expressions::onPatchEditorPulseWidthDefaultChanged (
            float value
            )
{
    setPulseWidthDefault (
                          value );
}

void
    Expressions::onLivePitchBendChanged (
            unsigned int voice
          , float        value
            )
{
    if ( voice == forVoice )
        setPitchBend (
                      value );
}

void
    Expressions::onLivePulseWidthChanged (
            unsigned int voice
          , float        value
            )
{
    if ( voice == forVoice )
        setPulseOffset (
                        value );
}

void
    Expressions::onPitchBendParameterChanged (
            unsigned int voice
          , float        value
            )
{
    if ( voice == forVoice )
        setPitchBend (
                      value );
}

void
    Expressions::onPulseWidthParameterChanged (
            unsigned int voice
          , float        value
            )
{
    if ( voice == forVoice )
        setPulseOffset (
                        value );
}

void
    Expressions::onPitchBend (
            unsigned voice
          , int      value
            )
{
    float range = static_cast < float > ( getPitchBendRange () );
    float val   = static_cast < float > ( value ) - 8192.0f;
    val /= range;
    if ( val > 1.0 )
        val = 1.0;
    else if ( val < -1.0 )
        val = -1.0;
    dispatcher -> pitchBendParameterChangedListeners -> call (
                                                              &PitchBendParameterChanged::onPitchBendParameterChanged
                                                            , voice
                                                            , val );
}

void
    Expressions::setForVoice (
            int value
            )
{
    if ( value > -1 && value < 3 )
    {
        dispatcher -> pitchBendParameterChangedListeners -> call (
                                                                  &PitchBendParameterChanged::onPitchBendParameterChanged
                                                                , value
                                                                , getPitchBend () );
        dispatcher -> pulseWidthParameterChangedListeners -> call (
                                                                   &PulseWidthParameterChanged::onPulseWidthParameterChanged
                                                                 , value
                                                                 , getPulseOffset () );
    }
    forVoice = value;
    vibrato -> SetForVoice (
                            value );
    tremolo -> setForVoice (
                            value );
}
