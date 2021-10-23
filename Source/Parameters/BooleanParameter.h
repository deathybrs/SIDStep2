#ifndef BOOLEANPARAMETER_H_INCLUDED
#define BOOLEANPARAMETER_H_INCLUDED


#include "JuceHeader.h"


class BooleanParameter : public juce::AudioProcessorParameter {
public:
	BooleanParameter(String name, bool newValue);
	~BooleanParameter();

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

	bool getBoolean() const;
	void setBoolean(bool newValue);

private:
	bool value;
	String name;
	bool dirty;
};



#endif  // BOOLEANPARAMETER_H_INCLUDED
