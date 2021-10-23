#ifndef LIVEVIBRATOAMOUNTCHANGED_H_INCLUDED
#define LIVEVIBRATOAMOUNTCHANGED_H_INCLUDED


class LiveVibratoAmountChanged {
public:
	virtual ~LiveVibratoAmountChanged() {}

	virtual void onLiveVibratoAmountChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEVIBRATOAMOUNTCHANGED_H_INCLUDED
