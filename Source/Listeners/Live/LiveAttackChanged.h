#ifndef LIVEATTACKCHANGED_H_INCLUDED
#define LIVEATTACKCHANGED_H_INCLUDED


class LiveAttackChanged {
public:
	virtual ~LiveAttackChanged() {}

	virtual void onLiveAttackChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVEATTACKCHANGED_H_INCLUDED
