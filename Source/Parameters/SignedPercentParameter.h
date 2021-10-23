#ifndef SIGNEDPERCENTPARAMETER_H_INCLUDED
#define SIGNEDPERCENTPARAMETER_H_INCLUDED


#include "JuceHeader.h"


class SidProgram;

class SignedPercentParameter : public juce::AudioProcessorParameter {
public:
	SignedPercentParameter(String name, float newValue, int steps);
	~SignedPercentParameter();

	float getValue() const override;
	void setValue(float newValue) override;
	float getDefaultValue() const override;
	String getName(int maximumStringLength) const override;
	String getLabel() const override;
	int getNumSteps() const override;
	String getText(float newValue, int maximumStringLength) const override;
	float getValueForText(const String& text) const override;

	bool isDirty() const;
	void setDirty(bool newValue);

	float getSignedPercent() const;
	void setSignedPercent(float newValue);

private:
	float value;
	// TODO: allow changing steps after construction
	int steps;
	String name;
	bool dirty;
};



#endif  // SIGNEDPERCENTPARAMETER_H_INCLUDED
