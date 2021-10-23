#ifndef LIVEPITCHBENDCHANGED_H_INCLUDED
#define LIVEPITCHBENDCHANGED_H_INCLUDED


class LivePitchBendChanged {
public:
	virtual ~LivePitchBendChanged() {}

	virtual void onLivePitchBendChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEPITCHBENDCHANGED_H_INCLUDED
