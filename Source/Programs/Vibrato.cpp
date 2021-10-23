#include "Vibrato.h"


#include "../SIDProgram.h"


Vibrato::Vibrato ()
    :
    currentVibratoAmount (
                          defaultVibratoAmount
                         )
  , currentVibratoSpeed (
                         defaultVibratoSpeed
                        )
  , currentVibratoDelay (
                         vibratoDelay
                        )
{
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> add (
                                                                                   this
                                                                                  );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> add (
                                                                                  this
                                                                                 );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> add (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> add (
                                                                                       this
                                                                                      );
}


Vibrato::Vibrato (
        XmlElement* e
        )
    :
    vibratoRange (
                  static_cast < unsigned int > ( e -> getIntAttribute (
                                                                       "range"
                                                                      ) )
                 )
  , vibratoSpeed (
                  static_cast < unsigned int > ( e -> getIntAttribute (
                                                                       "speed"
                                                                      ) )
                 )
  , vibratoDelay (
                  static_cast < unsigned int > ( e -> getIntAttribute (
                                                                       "delay"
                                                                      ) )
                 )
  , defaultVibratoAmount (
                          static_cast < float > ( e -> getDoubleAttribute (
                                                                           "default-amount"
                                                                          ) )
                         )
  , defaultVibratoSpeed (
                         static_cast < float > ( e -> getDoubleAttribute (
                                                                          "default-speed"
                                                                         ) )
                        )
  , currentVibratoAmount (
                          defaultVibratoAmount
                         )
  , currentVibratoSpeed (
                         defaultVibratoSpeed
                        )
  , currentVibratoDelay (
                         vibratoDelay
                        )
{
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> add (
                                                                                   this
                                                                                  );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> add (
                                                                                  this
                                                                                 );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> add (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> add (
                                                                                       this
                                                                                      );
}


Vibrato::Vibrato (
        const Vibrato& other
        )
    :
    vibratoRange {
            other . vibratoRange
    }
  , vibratoSpeed {
            other . vibratoSpeed
    }
  , vibratoDelay {
            other . vibratoDelay
    }
  , defaultVibratoAmount {
            other . defaultVibratoAmount
    }
  , defaultVibratoSpeed {
            other . defaultVibratoSpeed
    }
  , currentVibratoAmount {
            other . currentVibratoAmount
    }
  , currentVibratoSpeed {
            other . currentVibratoSpeed
    }
  , currentVibratoDelay {
            other . currentVibratoDelay
    }
  , vibratoCounter {
            other . vibratoCounter
    }
  , forVoice {
            other . forVoice
    }
{
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> add (
                                                                                   this
                                                                                  );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> add (
                                                                                  this
                                                                                 );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> add (
                                                                                  this
                                                                                 );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> add (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> add (
                                                                                       this
                                                                                      );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> add (
                                                                                       this
                                                                                      );
}


Vibrato::Vibrato (
        Vibrato&& other
        ) noexcept
    :
    vibratoRange {
            other . vibratoRange
    }
  , vibratoSpeed {
            other . vibratoSpeed
    }
  , vibratoDelay {
            other . vibratoDelay
    }
  , defaultVibratoAmount {
            other . defaultVibratoAmount
    }
  , defaultVibratoSpeed {
            other . defaultVibratoSpeed
    }
  , currentVibratoAmount {
            other . currentVibratoAmount
    }
  , currentVibratoSpeed {
            other . currentVibratoSpeed
    }
  , currentVibratoDelay {
            other . currentVibratoDelay
    }
  , vibratoCounter {
            other . vibratoCounter
    }
  , forVoice {
            other . forVoice
    }
{
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> remove (
                                                                                      &other
                                                                                     );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> remove (
                                                                                     &other
                                                                                    );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> remove (
                                                                                     &other
                                                                                    );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> remove (
                                                                                           &other
                                                                                          );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> remove (
                                                                                          &other
                                                                                         );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> remove (
                                                                                          &other
                                                                                         );
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> add (
                                                                                   this
                                                                                  );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> add (
                                                                                  this
                                                                                 );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> add (
                                                                                  this
                                                                                 );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> add (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> add (
                                                                                       this
                                                                                      );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> add (
                                                                                       this
                                                                                      );
}


Vibrato::~Vibrato ()
{
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> remove (
                                                                                      this
                                                                                     );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> remove (
                                                                                     this
                                                                                    );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> remove (
                                                                                     this
                                                                                    );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> remove (
                                                                                           this
                                                                                          );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> remove (
                                                                                          this
                                                                                         );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> remove (
                                                                                          this
                                                                                         );
}


auto
    Vibrato::operator= (
            const Vibrato& other
            ) -> Vibrato&
{
    if ( &other == this )
    {
        return *this;
    }

    vibratoRange         = other . vibratoRange;
    vibratoSpeed         = other . vibratoSpeed;
    vibratoDelay         = other . vibratoDelay;
    defaultVibratoAmount = other . defaultVibratoAmount;
    defaultVibratoSpeed  = other . defaultVibratoSpeed;
    currentVibratoAmount = other . currentVibratoAmount;
    currentVibratoSpeed  = other . currentVibratoSpeed;
    currentVibratoDelay  = other . currentVibratoDelay;
    vibratoCounter       = other . vibratoCounter;
    forVoice             = other . forVoice;

    return *this;
}


auto
    Vibrato::operator= (
            Vibrato&& other
            ) noexcept -> Vibrato&
{
    if ( &other == this )
    {
        return *this;
    }

    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> remove (
                                                                                      &other
                                                                                     );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> remove (
                                                                                     &other
                                                                                    );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> remove (
                                                                                     &other
                                                                                    );

    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> remove (
                                                                                           &other
                                                                                          );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> remove (
                                                                                          &other
                                                                                         );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> remove (
                                                                                          &other
                                                                                         );

    vibratoRange         = other . vibratoRange;
    vibratoSpeed         = other . vibratoSpeed;
    vibratoDelay         = other . vibratoDelay;
    defaultVibratoAmount = other . defaultVibratoAmount;
    defaultVibratoSpeed  = other . defaultVibratoSpeed;
    currentVibratoAmount = other . currentVibratoAmount;
    currentVibratoSpeed  = other . currentVibratoSpeed;
    currentVibratoDelay  = other . currentVibratoDelay;
    vibratoCounter       = other . vibratoCounter;
    forVoice             = other . forVoice;

    return *this;
}


void
    Vibrato::Select (
            const bool value
            )
{
    if ( value )
    {
        SharedResourcePointer < ListenerList < PatchEditorVibratoRangeChanged > > () -> add (
                                                                                             this
                                                                                            );
        SharedResourcePointer < ListenerList < PatchEditorVibratoDelayChanged > > () -> add (
                                                                                             this
                                                                                            );
        SharedResourcePointer < ListenerList < PatchEditorVibratoSpeedChanged > > () -> add (
                                                                                             this
                                                                                            );
        SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultAmountChanged > > () -> add (
                                                                                                     this
                                                                                                    );
        SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultSpeedChanged > > () -> add (
                                                                                                    this
                                                                                                   );
    }
    else
    {
        SharedResourcePointer < ListenerList < PatchEditorVibratoRangeChanged > > () -> remove (
                                                                                                this
                                                                                               );
        SharedResourcePointer < ListenerList < PatchEditorVibratoDelayChanged > > () -> remove (
                                                                                                this
                                                                                               );
        SharedResourcePointer < ListenerList < PatchEditorVibratoSpeedChanged > > () -> remove (
                                                                                                this
                                                                                               );
        SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultAmountChanged > > () -> remove (
                                                                                                        this
                                                                                                       );
        SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultSpeedChanged > > () -> remove (
                                                                                                       this
                                                                                                      );
    }
}


void
    Vibrato::Write (
            XmlElement* e
            ) const
{
    auto v = e -> getChildByName (
                                  "vibrato"
                                 );
    if ( v == nullptr )
    {
        v = new XmlElement (
                            "vibrato"
                           );
        e -> addChildElement (
                              v
                             );
    }

    v -> setAttribute (
                       "range"
                     , String (
                               vibratoRange
                              )
                      );
    v -> setAttribute (
                       "speed"
                     , String (
                               vibratoSpeed
                              )
                      );
    v -> setAttribute (
                       "delay"
                     , String (
                               vibratoDelay
                              )
                      );
    v -> setAttribute (
                       "default-amount"
                     , String (
                               defaultVibratoAmount
                              )
                      );
    v -> setAttribute (
                       "default-speed"
                     , String (
                               defaultVibratoSpeed
                              )
                      );
}


void
    Vibrato::WriteState (
            MemoryBlock& dest_data
            ) const
{
    dest_data . append (
                        static_cast < const void* > ( &vibratoRange )
                      , sizeof vibratoRange
                       );
    dest_data . append (
                        static_cast < const void* > ( &vibratoSpeed )
                      , sizeof vibratoSpeed
                       );
    dest_data . append (
                        static_cast < const void* > ( &vibratoDelay )
                      , sizeof vibratoDelay
                       );
    dest_data . append (
                        static_cast < const void* > ( &defaultVibratoAmount )
                      , sizeof defaultVibratoAmount
                       );
    dest_data . append (
                        static_cast < const void* > ( &defaultVibratoSpeed )
                      , sizeof defaultVibratoSpeed
                       );
}


void
    Vibrato::WriteCopyState (
            MemoryBlock& dest_data
            ) const
{
    dest_data . append (
                        static_cast < const void* > ( &currentVibratoAmount )
                      , sizeof currentVibratoAmount
                       );
    dest_data . append (
                        static_cast < const void* > ( &currentVibratoSpeed )
                      , sizeof currentVibratoSpeed
                       );
    dest_data . append (
                        static_cast < const void* > ( &currentVibratoDelay )
                      , sizeof currentVibratoDelay
                       );
}


void
    Vibrato::LoadState (
            MemoryInputStream&                             stream
          , const ReferenceCountedObjectPtr < SidProgram > o
            )
{
    auto v = o -> GetExpression () -> getVibrato ();

    stream . read (
                   &v -> vibratoRange
                 , sizeof v -> vibratoRange
                  );
    stream . read (
                   &v -> vibratoSpeed
                 , sizeof v -> vibratoSpeed
                  );
    stream . read (
                   &v -> vibratoDelay
                 , sizeof v -> vibratoDelay
                  );
    stream . read (
                   &v -> defaultVibratoAmount
                 , sizeof v -> defaultVibratoAmount
                  );
    stream . read (
                   &v -> defaultVibratoSpeed
                 , sizeof v -> defaultVibratoSpeed
                  );
}


void
    Vibrato::LoadCopyState (
            MemoryInputStream&                             stream
          , const ReferenceCountedObjectPtr < SidProgram > o
            )
{
    auto v = o -> GetExpression () -> getVibrato ();

    stream . read (
                   &v -> currentVibratoAmount
                 , sizeof v -> currentVibratoAmount
                  );
    stream . read (
                   &v -> currentVibratoSpeed
                 , sizeof v -> currentVibratoSpeed
                  );
    stream . read (
                   &v -> currentVibratoDelay
                 , sizeof v -> currentVibratoDelay
                  );
}


auto
    Vibrato::GetVibratoRange () const -> unsigned int
{
    return vibratoRange;
}


void
    Vibrato::SetVibratoRange (
            const unsigned int value
            )
{
    static const auto RANGE_MAX = 8193;
    if ( value < RANGE_MAX )
    {
        vibratoRange = value;
    }
}


auto
    Vibrato::GetVibratoSpeed () const -> unsigned int
{
    return vibratoSpeed;
}


void
    Vibrato::SetVibratoSpeed (
            const unsigned int value
            )
{
    vibratoSpeed = value;
}


auto
    Vibrato::GetVibratoDelay () const -> unsigned
{
    return vibratoDelay;
}


void
    Vibrato::SetVibratoDelay (
            const unsigned value
            )
{
    if ( value >= 0 && value < 16 )
    {
        vibratoDelay = value;
    }

    SetCurrentVibratoDelay (
                            value
                           );
}


auto
    Vibrato::GetDefaultVibratoAmount () const -> float
{
    return defaultVibratoAmount;
}


auto
    Vibrato::GetDefaultVibratoSpeed () const -> float
{
    return defaultVibratoSpeed;
}


auto
    Vibrato::GetCurrentVibratoAmount () const -> float
{
    return currentVibratoAmount;
}


auto
    Vibrato::GetCurrentVibratoSpeed () const -> float
{
    return currentVibratoSpeed;
}


void
    Vibrato::SetDefaultVibratoAmount (
            const float value
            )
{
    if ( value >= -1 && value <= 1 )
    {
        defaultVibratoAmount = value;
    }

    SetCurrentVibratoAmount (
                             value
                            );
}


void
    Vibrato::SetDefaultVibratoSpeed (
            const float value
            )
{
    if ( value >= -1 && value <= 1 )
    {
        defaultVibratoSpeed = value;
    }

    SetCurrentVibratoSpeed (
                            value
                           );
}


void
    Vibrato::SetCurrentVibratoAmount (
            const float value
            )
{
    if ( value < 0 || value > 1 )
    {
        return;
    }
    if ( currentVibratoAmount == 0 && value != 0 || currentVibratoAmount != 0 && value == 0 )
    {
        vibratoCounter = 0;
    }

    currentVibratoAmount = value;
}


void
    Vibrato::SetCurrentVibratoSpeed (
            const float value
            )
{
    if ( value < 0 || value > 1 )
    {
        return;
    }

    currentVibratoSpeed = value;
}


auto
    Vibrato::GetCurrentVibratoDelay () const -> unsigned
{
    return currentVibratoDelay;
}


void
    Vibrato::SetCurrentVibratoDelay (
            const unsigned value
            )
{
    if ( value >= 0 && value < 16 )
    {
        currentVibratoDelay = value;
    }
}


auto
    Vibrato::GetCurrentVibratoValue () const -> int
{
    if ( currentVibratoAmount == 0 || currentVibratoSpeed == 0 || vibratoCounter < currentVibratoDelay )
    {
        return 0;
    }

    // ReSharper disable once CppInconsistentNaming
    const auto A = currentVibratoAmount * static_cast < double > ( vibratoRange );
    const auto t = static_cast < double > ( vibratoCounter - currentVibratoDelay ) /
            ( static_cast < double > ( vibratoSpeed ) * static_cast < double > ( currentVibratoSpeed ) );
    // ReSharper disable once CppInconsistentNaming
    const auto _2PI = 3.1415926535897932384626433832795 * 2.0;

    return static_cast < int > ( A * sin (
                                          _2PI * t
                                         ) );
}


void
    Vibrato::Start ()
{
    vibratoCounter      = 0;
    currentVibratoDelay = vibratoDelay;
}


void
    Vibrato::Step ()
{
    if ( currentVibratoAmount != 0 )
    {
        vibratoCounter++;
    }
}


void
// ReSharper disable once CppMemberFunctionMayBeStatic
    Vibrato::Release () {}


void
    Vibrato::onPatchEditorVibratoRangeChanged (
            const unsigned int value
            )
{
    SetVibratoRange (
                     value
                    );
}


void
    Vibrato::onPatchEditorVibratoSpeedChanged (
            const unsigned int value
            )
{
    SetVibratoSpeed (
                     value
                    );
}


void
    Vibrato::onPatchEditorVibratoDefaultAmountChanged (
            const float value
            )
{
    SetDefaultVibratoAmount (
                             value
                            );
}


void
    Vibrato::onPatchEditorVibratoDefaultSpeedChanged (
            const float value
            )
{
    SetDefaultVibratoSpeed (
                            value
                           );
}


void
    Vibrato::onLiveVibratoAmountChanged (
            const unsigned voice
          , const float    value
            )
{
    if ( voice == forVoice )
    {
        SetCurrentVibratoAmount (
                                 value
                                );
    }
}


void
    Vibrato::onLiveVibratoSpeedChanged (
            const unsigned int voice
          , const float        value
            )
{
    if ( voice == forVoice )
    {
        SetCurrentVibratoSpeed (
                                value
                               );
    }
}


void
    Vibrato::onVibratoAmountParameterChanged (
            const unsigned voice
          , const float    value
            )
{
    if ( voice == forVoice )
    {
        SetCurrentVibratoAmount (
                                 value
                                );
    }
}


void
    Vibrato::onVibratoSpeedParameterChanged (
            const unsigned int voice
          , const float        value
            )
{
    if ( voice == forVoice )
    {
        SetCurrentVibratoSpeed (
                                value
                               );
    }
}


void
    Vibrato::onLiveVibratoDelayChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( voice == forVoice )
    {
        SetCurrentVibratoDelay (
                                value
                               );
    }
}


void
    Vibrato::onVibratoDelayParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( voice == forVoice )
    {
        SetCurrentVibratoDelay (
                                value
                               );
    }
}


void
    Vibrato::onPatchEditorVibratoDelayChanged (
            const unsigned value
            )
{
    SetVibratoDelay (
                     value
                    );
}


void
    Vibrato::SetForVoice (
            const int value
            )
{
    if ( value > -1 && value < 3 )
    {
        SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> call (
                                                                                             &VibratoAmountParameterChanged::
                                                                                             onVibratoAmountParameterChanged
                                                                                           , value
                                                                                           , GetCurrentVibratoAmount ()
                                                                                            );
        SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> call (
                                                                                            &VibratoSpeedParameterChanged::onVibratoSpeedParameterChanged
                                                                                          , value
                                                                                          , GetCurrentVibratoSpeed ()
                                                                                           );
    }
    forVoice = value;
}
