#ifndef LIVELOWPASSCHANGED_H_INCLUDED
#define LIVELOWPASSCHANGED_H_INCLUDED


class LiveLowPassChanged {
public:
	virtual ~LiveLowPassChanged() {}

	virtual void onLiveLowPassChanged(bool value) = 0;
};


#endif  // LIVELOWPASSCHANGED_H_INCLUDED
