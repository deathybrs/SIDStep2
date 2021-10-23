#ifndef LIVEVOICEFILTERCHANGED_H_INCLUDED
#define LIVEVOICEFILTERCHANGED_H_INCLUDED


class LiveVoiceFilterChanged {
public:
	virtual ~LiveVoiceFilterChanged() {}

	virtual void onLiveVoiceFilterChanged(unsigned int voice, bool value) = 0;
};


#endif  // LIVEVOICEFILTERCHANGED_H_INCLUDED
