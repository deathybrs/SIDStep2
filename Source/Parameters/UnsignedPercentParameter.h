#ifndef UNSIGNEDPERCENTPARAMETER_H_INCLUDED
#define UNSIGNEDPERCENTPARAMETER_H_INCLUDED


#include "JuceHeader.h"


class SidProgram;

class UnsignedPercentParameter : public juce::AudioProcessorParameter {
public:
	UnsignedPercentParameter(String name, float newValue, int steps);
	~UnsignedPercentParameter();

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

	float getUnsignedPercent() const;
	void setUnsignedPercent(float newValue);

private:
	float value;
	// TODO: allow changing steps after construction
	int steps;
	String name;
	bool dirty;
};



#endif  // UNSIGNEDPERCENTPARAMETER_H_INCLUDED
