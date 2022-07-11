#include "Envelope.h"

#include "../JuceLibraryCode/JuceHeader.h"

#include "../SIDProgram.h"

sEnvelope::sEnvelope (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    dispatcher (
                dispatcher )
  , defaultAttack (
                   0 )
  , defaultDecay (
                  0 )
  , defaultSustain (
                    15 )
  , defaultRelease (
                    0 )
  , attack (
            defaultAttack )
  , decay (
           defaultDecay )
  , sustain (
             defaultSustain )
  , release (
             defaultRelease )
  , forVoice (
              -1 )
{
    dispatcher -> liveAttackChangedListeners -> add (
                                                     this );
    dispatcher -> liveDecayChangedListeners -> add (
                                                    this );
    dispatcher -> liveSustainChangedListeners -> add (
                                                      this );
    dispatcher -> liveReleaseChangedListeners -> add (
                                                      this );
    dispatcher -> attackParameterChangedListeners -> add (
                                                          this );
    dispatcher -> decayParameterChangedListeners -> add (
                                                         this );
    dispatcher -> sustainParameterChangedListeners -> add (
                                                           this );
    dispatcher -> releaseParameterChangedListeners -> add (
                                                           this );
}

sEnvelope::sEnvelope (
        const std::shared_ptr < EventDispatcher >& dispatcher
      , XmlElement*                                e
        )
    :
    dispatcher (
                dispatcher )
  , defaultAttack (
                   static_cast < unsigned int > ( e -> getIntAttribute (
                                                                        "attack" ) ) )
  , defaultDecay (
                  static_cast < unsigned int > ( e -> getIntAttribute (
                                                                       "decay" ) ) )
  , defaultSustain (
                    static_cast < unsigned int > ( e -> getIntAttribute (
                                                                         "sustain" ) ) )
  , defaultRelease (
                    static_cast < unsigned int > ( e -> getIntAttribute (
                                                                         "release" ) ) )
  , attack (
            defaultAttack )
  , decay (
           defaultDecay )
  , sustain (
             defaultSustain )
  , release (
             defaultRelease )
  , forVoice (
              -1 )
{
    dispatcher -> liveAttackChangedListeners -> add (
                                                     this );
    dispatcher -> liveDecayChangedListeners -> add (
                                                    this );
    dispatcher -> liveSustainChangedListeners -> add (
                                                      this );
    dispatcher -> liveReleaseChangedListeners -> add (
                                                      this );
    dispatcher -> attackParameterChangedListeners -> add (
                                                          this );
    dispatcher -> decayParameterChangedListeners -> add (
                                                         this );
    dispatcher -> sustainParameterChangedListeners -> add (
                                                           this );
    dispatcher -> releaseParameterChangedListeners -> add (
                                                           this );
}

sEnvelope::sEnvelope (
        const std::shared_ptr < EventDispatcher >& dispatcher
      , sEnvelope&                                 original
        )
    :
    dispatcher (
                dispatcher )
  , defaultAttack (
                   original . defaultAttack )
  , defaultDecay (
                  original . defaultDecay )
  , defaultSustain (
                    original . defaultSustain )
  , defaultRelease (
                    original . defaultRelease )
  , attack (
            defaultAttack )
  , decay (
           defaultDecay )
  , sustain (
             defaultSustain )
  , release (
             defaultRelease )
  , forVoice (
              -1 )
{
    dispatcher -> liveAttackChangedListeners -> add (
                                                     this );
    dispatcher -> liveDecayChangedListeners -> add (
                                                    this );
    dispatcher -> liveSustainChangedListeners -> add (
                                                      this );
    dispatcher -> liveReleaseChangedListeners -> add (
                                                      this );
    dispatcher -> attackParameterChangedListeners -> add (
                                                          this );
    dispatcher -> decayParameterChangedListeners -> add (
                                                         this );
    dispatcher -> sustainParameterChangedListeners -> add (
                                                           this );
    dispatcher -> releaseParameterChangedListeners -> add (
                                                           this );
}

sEnvelope::~sEnvelope ()
{
    dispatcher -> liveAttackChangedListeners -> remove (
                                                        this );
    dispatcher -> liveDecayChangedListeners -> remove (
                                                       this );
    dispatcher -> liveSustainChangedListeners -> remove (
                                                         this );
    dispatcher -> liveReleaseChangedListeners -> remove (
                                                         this );
    dispatcher -> attackParameterChangedListeners -> remove (
                                                             this );
    dispatcher -> decayParameterChangedListeners -> remove (
                                                            this );
    dispatcher -> sustainParameterChangedListeners -> remove (
                                                              this );
    dispatcher -> releaseParameterChangedListeners -> remove (
                                                              this );
}

void
    sEnvelope::select (
            const bool value
            )
{
    if ( value )
    {
        dispatcher -> patchEditorAttackChangedListeners -> add (
                                                                this );
        dispatcher -> patchEditorDecayChangedListeners -> add (
                                                               this );
        dispatcher -> patchEditorSustainChangedListeners -> add (
                                                                 this );
        dispatcher -> patchEditorReleaseChangedListeners -> add (
                                                                 this );
    }
    else
    {
        dispatcher -> patchEditorAttackChangedListeners -> remove (
                                                                   this );
        dispatcher -> patchEditorDecayChangedListeners -> remove (
                                                                  this );
        dispatcher -> patchEditorSustainChangedListeners -> remove (
                                                                    this );
        dispatcher -> patchEditorReleaseChangedListeners -> remove (
                                                                    this );
    }
}

void
    sEnvelope::write (
            XmlElement* e
            ) const
{
    auto env = e -> getChildByName (
                                    "envelope" );
    if ( env == nullptr )
    {
        env = new XmlElement (
                              "envelope" );
        e -> addChildElement (
                              env );
    }
    env -> setAttribute (
                         "attack"
                       , String (
                                 defaultAttack ) );
    env -> setAttribute (
                         "decay"
                       , String (
                                 defaultDecay ) );
    env -> setAttribute (
                         "sustain"
                       , String (
                                 defaultSustain ) );
    env -> setAttribute (
                         "release"
                       , String (
                                 defaultRelease ) );
}

void
    sEnvelope::writeState (
            MemoryBlock& dest_data
            ) const
{
    dest_data . append (
                        static_cast < const void* > ( &defaultAttack )
                      , sizeof defaultAttack );
    dest_data . append (
                        static_cast < const void* > ( &defaultDecay )
                      , sizeof defaultDecay );
    dest_data . append (
                        static_cast < const void* > ( &defaultSustain )
                      , sizeof defaultSustain );
    dest_data . append (
                        static_cast < const void* > ( &defaultRelease )
                      , sizeof defaultRelease );
}

void
    sEnvelope::writeCopyState (
            MemoryBlock& dest_data
            ) const
{
    dest_data . append (
                        static_cast < const void* > ( &attack )
                      , sizeof attack );
    dest_data . append (
                        static_cast < const void* > ( &decay )
                      , sizeof decay );
    dest_data . append (
                        static_cast < const void* > ( &sustain )
                      , sizeof sustain );
    dest_data . append (
                        static_cast < const void* > ( &release )
                      , sizeof release );
}

void
    sEnvelope::loadState (
            MemoryInputStream&                              stream
          , const ReferenceCountedObjectPtr < SidProgram >& o
            )
{
    auto e = o -> GetEnvelope ();
    stream . read (
                   &e -> defaultAttack
                 , sizeof e -> defaultAttack );
    stream . read (
                   &e -> defaultDecay
                 , sizeof e -> defaultDecay );
    stream . read (
                   &e -> defaultSustain
                 , sizeof e -> defaultSustain );
    stream . read (
                   &e -> defaultRelease
                 , sizeof e -> defaultRelease );
}

void
    sEnvelope::loadCopyState (
            MemoryInputStream&                              stream
          , const ReferenceCountedObjectPtr < SidProgram >& o
            )
{
    auto e = o -> GetEnvelope ();
    stream . read (
                   &e -> attack
                 , sizeof e -> attack );
    stream . read (
                   &e -> decay
                 , sizeof e -> decay );
    stream . read (
                   &e -> sustain
                 , sizeof e -> sustain );
    stream . read (
                   &e -> release
                 , sizeof e -> release );
}

unsigned int
    sEnvelope::getAttack () const { return attack; }

void
    sEnvelope::setAttack (
            unsigned int value
            )
{
    if ( value <= 0xf )
        attack = value;
}

unsigned int
    sEnvelope::getDecay () const { return decay; }

void
    sEnvelope::setDecay (
            unsigned int value
            )
{
    if ( value <= 0xf )
        decay = value;
}

unsigned int
    sEnvelope::getSustain () const { return sustain; }

void
    sEnvelope::setSustain (
            unsigned int value
            )
{
    if ( value <= 0xf )
        sustain = value;
}

unsigned int
    sEnvelope::getRelease () const { return release; }

void
    sEnvelope::setRelease (
            unsigned int value
            )
{
    if ( value <= 0xf )
        release = value;
}

unsigned int
    sEnvelope::getDefaultAttack () const { return defaultAttack; }

void
    sEnvelope::setDefaultAttack (
            unsigned int value
            )
{
    if ( value <= 0xf )
        attack = defaultAttack = value;
}

unsigned int
    sEnvelope::getDefaultDecay () const { return defaultDecay; }

void
    sEnvelope::setDefaultDecay (
            unsigned int value
            )
{
    if ( value <= 0xf )
        decay = defaultDecay = value;
}

unsigned int
    sEnvelope::getDefaultSustain () const { return defaultSustain; }

void
    sEnvelope::setDefaultSustain (
            unsigned int value
            )
{
    if ( value <= 0xf )
        sustain = defaultSustain = value;
}

unsigned int
    sEnvelope::getDefaultRelease () const { return defaultRelease; }

void
    sEnvelope::setDefaultRelease (
            unsigned int value
            )
{
    if ( value <= 0xf )
        release = defaultRelease = value;
}

void
    sEnvelope::onPatchEditorAttackChanged (
            unsigned int value
            )
{
    setDefaultAttack (
                      value );
}

void
    sEnvelope::onPatchEditorDecayChanged (
            unsigned int value
            )
{
    setDefaultDecay (
                     value );
}

void
    sEnvelope::onPatchEditorSustainChanged (
            unsigned int value
            )
{
    setDefaultSustain (
                       value );
}

void
    sEnvelope::onPatchEditorReleaseChanged (
            unsigned int value
            )
{
    setDefaultRelease (
                       value );
}

void
    sEnvelope::onLiveAttackChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setAttack (
                   value );
}

void
    sEnvelope::onLiveDecayChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setDecay (
                  value );
}

void
    sEnvelope::onLiveSustainChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setSustain (
                    value );
}

void
    sEnvelope::onLiveReleaseChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setRelease (
                    value );
}

void
    sEnvelope::onAttackParameterChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setAttack (
                   value );
}

void
    sEnvelope::onDecayParameterChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setDecay (
                  value );
}

void
    sEnvelope::onSustainParameterChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setSustain (
                    value );
}

void
    sEnvelope::onReleaseParameterChanged (
            unsigned voice
          , unsigned value
            )
{
    if ( voice == forVoice )
        setRelease (
                    value );
}

void
    sEnvelope::SetForVoice (
            int value
            )
{
    if ( value > -1 && value < 3 )
    {
        dispatcher -> attackParameterChangedListeners -> call (
                                                               &AttackParameterChanged::onAttackParameterChanged
                                                             , value
                                                             , getAttack () );
        dispatcher -> decayParameterChangedListeners -> call (
                                                              &DecayParameterChanged::onDecayParameterChanged
                                                            , value
                                                            , getDecay () );
        dispatcher -> sustainParameterChangedListeners -> call (
                                                                &SustainParameterChanged::onSustainParameterChanged
                                                              , value
                                                              , getSustain () );
        dispatcher -> releaseParameterChangedListeners -> call (
                                                                &ReleaseParameterChanged::onReleaseParameterChanged
                                                              , value
                                                              , getRelease () );
    }
    forVoice = value;
}
