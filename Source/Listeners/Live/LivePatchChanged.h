#ifndef LIVEPATCHCHANGED_H_INCLUDED
#define LIVEPATCHCHANGED_H_INCLUDED


class LivePatchChanged {
public:
	virtual ~LivePatchChanged() {}

	virtual void onLivePatchChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVEPATCHCHANGED_H_INCLUDED
