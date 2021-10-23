#ifndef LOADLIVEPATCH_H_INCLUDED
#define LOADLIVEPATCH_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include "../../Defines.h"


class SidProgram;

EVENT(LoadLivePatch, (unsigned int voice, ReferenceCountedObjectPtr<SidProgram> program))




#endif  // LOADLIVEPATCH_H_INCLUDED
