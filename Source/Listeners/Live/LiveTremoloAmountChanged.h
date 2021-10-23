#ifndef LIVETREMOLOAMOUNTCHANGED_H_INCLUDED
#define LIVETREMOLOAMOUNTCHANGED_H_INCLUDED


class LiveTremoloAmountChanged {
public:
	virtual ~LiveTremoloAmountChanged() {}

	virtual void onLiveTremoloAmountChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVETREMOLOAMOUNTCHANGED_H_INCLUDED
