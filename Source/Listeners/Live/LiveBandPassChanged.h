#ifndef LIVEBANDPASSCHANGED_H_INCLUDED
#define LIVEBANDPASSCHANGED_H_INCLUDED


class LiveBandPassChanged {
public:
	virtual ~LiveBandPassChanged() {}

	virtual void onLiveBandPassChanged(bool value) = 0;
};


#endif  // LIVEBANDPASSCHANGED_H_INCLUDED
