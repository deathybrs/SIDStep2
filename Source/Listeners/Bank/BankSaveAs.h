#ifndef BANKSAVEAS_H_INCLUDED
#define BANKSAVEAS_H_INCLUDED


#include "../Programs/Categories.h"


class BankSaveAs {
public:
	virtual ~BankSaveAs() {}

	virtual void onBankSaveAs(Category category) = 0;
};


#endif  // BANKSAVEAS_H_INCLUDED
