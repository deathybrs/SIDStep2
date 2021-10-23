#ifndef LIVERESONANCECHANGED_H_INCLUDED
#define LIVERESONANCECHANGED_H_INCLUDED


class LiveResonanceChanged {
public:
	virtual ~LiveResonanceChanged() {}

	virtual void onLiveResonanceChanged(unsigned int value) = 0;
};


#endif  // LIVERESONANCECHANGED_H_INCLUDED
