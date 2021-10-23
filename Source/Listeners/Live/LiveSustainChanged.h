#ifndef LIVESUSTAINCHANGED_H_INCLUDED
#define LIVESUSTAINCHANGED_H_INCLUDED


class LiveSustainChanged {
public:
	virtual ~LiveSustainChanged() {}

	virtual void onLiveSustainChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVESUSTAINCHANGED_H_INCLUDED
