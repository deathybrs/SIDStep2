#ifndef LIVETITLECHANGED_H_INCLUDED
#define LIVETITLECHANGED_H_INCLUDED


class LiveTitleChanged {
public:
	virtual ~LiveTitleChanged() {}

	virtual void onLiveTitleChanged(String value) = 0;
};


#endif  // LIVETITLECHANGED_H_INCLUDED
