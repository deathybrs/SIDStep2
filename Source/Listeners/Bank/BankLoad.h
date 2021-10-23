#ifndef BANKLOAD_H_INCLUDED
#define BANKLOAD_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"


class BankLoad {
public:
	virtual ~BankLoad() {}

	virtual void onBankLoad(String id) = 0;
};


#endif  // BANKLOAD_H_INCLUDED
