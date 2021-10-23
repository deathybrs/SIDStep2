#ifndef BANKSAVE_H_INCLUDED
#define BANKSAVE_H_INCLUDED


class BankSave {
public:
	virtual ~BankSave() {}

	virtual void onBankSave() = 0;
};


#endif  // BANKSAVE_H_INCLUDED
