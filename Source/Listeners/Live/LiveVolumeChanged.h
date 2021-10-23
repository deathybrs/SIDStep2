#ifndef LIVEVOLUMECHANGED_H_INCLUDED
#define LIVEVOLUMECHANGED_H_INCLUDED


class LiveVolumeChanged {
public:
	virtual ~LiveVolumeChanged() {}

	virtual void onLiveVolumeChanged(unsigned int value) = 0;
};


#endif  // LIVEVOLUMECHANGED_H_INCLUDED
