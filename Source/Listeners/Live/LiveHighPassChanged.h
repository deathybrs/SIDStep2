#ifndef LIVEHIGHPASSCHANGED_H_INCLUDED
#define LIVEHIGHPASSCHANGED_H_INCLUDED


class LiveHighPassChanged {
public:
	virtual ~LiveHighPassChanged() {}

	virtual void onLiveHighPassChanged(bool value) = 0;
};


#endif  // LIVEHIGHPASSCHANGED_H_INCLUDED
