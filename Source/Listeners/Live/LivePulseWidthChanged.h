#ifndef LIVEPULSEWIDTHCHANGED_H_INCLUDED
#define LIVEPULSEWIDTHCHANGED_H_INCLUDED


class LivePulseWidthChanged {
public:
	virtual ~LivePulseWidthChanged() {}

	virtual void onLivePulseWidthChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEPULSEWIDTHCHANGED_H_INCLUDED
