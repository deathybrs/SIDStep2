#ifndef LIVEDECAYCHANGED_H_INCLUDED
#define LIVEDECAYCHANGED_H_INCLUDED


class LiveDecayChanged {
public:
	virtual ~LiveDecayChanged() {}

	virtual void onLiveDecayChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVEDECAYCHANGED_H_INCLUDED
