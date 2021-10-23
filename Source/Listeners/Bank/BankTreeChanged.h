#ifndef BANKTREECHANGED_H_INCLUDED
#define BANKTREECHANGED_H_INCLUDED


class BankTreeChanged {
public:
	virtual ~BankTreeChanged() {}

	virtual void onBankTreeChanged() = 0;
};


#endif  // BANKTREECHANGED_H_INCLUDED
