#ifndef LIVECUTOFFCHANGED_H_INCLUDED
#define LIVECUTOFFCHANGED_H_INCLUDED


class LiveCutoffChanged {
public:
	virtual ~LiveCutoffChanged() {}

	virtual void onLiveCutoffChanged(unsigned int value) = 0;
};


#endif  // LIVECUTOFFCHANGED_H_INCLUDED
