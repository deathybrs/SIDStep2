#ifndef BANKPROGRAMCHANGED_H_INCLUDED
#define BANKPROGRAMCHANGED_H_INCLUDED


#include "../../JuceLibraryCode/JuceHeader.h"


class SidProgram;


class BankProgramChanged
{
public:
    virtual ~BankProgramChanged () {}

    virtual void
        onBankProgramChanged (
                String                                   oldID
              , ReferenceCountedObjectPtr < SidProgram > program
                ) = 0;
};


#endif  // BANKPROGRAMCHANGED_H_INCLUDED
