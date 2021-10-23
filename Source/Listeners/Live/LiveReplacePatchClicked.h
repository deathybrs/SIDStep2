#ifndef LIVEREPLACEPATCHCLICKED_H_INCLUDED
#define LIVEREPLACEPATCHCLICKED_H_INCLUDED


class LiveReplacePatchClicked {
public:
	virtual ~LiveReplacePatchClicked() {}

	virtual void onLiveReplacePatchClicked(unsigned int row) = 0;
};


#endif  // LIVEREPLACEPATCHCLICKED_H_INCLUDED
