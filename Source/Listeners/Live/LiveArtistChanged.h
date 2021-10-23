#ifndef LIVEARTISTCHANGED_H_INCLUDED
#define LIVEARTISTCHANGED_H_INCLUDED


class LiveArtistChanged {
public:
	virtual ~LiveArtistChanged() {}
	
	virtual void onLiveArtistChanged(String value) = 0;
};


#endif  // LIVEARTISTCHANGED_H_INCLUDED
