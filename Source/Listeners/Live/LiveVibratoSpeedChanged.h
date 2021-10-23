#ifndef LIVEVIBRATOSPEEDCHANGED_H_INCLUDED
#define LIVEVIBRATOSPEEDCHANGED_H_INCLUDED


class LiveVibratoSpeedChanged {
public:
	virtual ~LiveVibratoSpeedChanged() {}

	virtual void onLiveVibratoSpeedChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEVIBRATOSPEEDCHANGED_H_INCLUDED
