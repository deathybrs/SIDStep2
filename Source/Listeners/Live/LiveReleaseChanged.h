#ifndef LIVERELEASECHANGED_H_INCLUDED
#define LIVERELEASECHANGED_H_INCLUDED


class LiveReleaseChanged {
public:
	virtual ~LiveReleaseChanged() {}

	virtual void onLiveReleaseChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVERELEASECHANGED_H_INCLUDED
