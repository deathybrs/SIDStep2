#ifndef LIVETREMOLOSPEEDCHANGED_H_INCLUDED
#define LIVETREMOLOSPEEDCHANGED_H_INCLUDED


class LiveTremoloSpeedChanged {
public:
	virtual ~LiveTremoloSpeedChanged() {}

	virtual void onLiveTremoloSpeedChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVETREMOLOSPEEDCHANGED_H_INCLUDED
