#ifndef UNSIGNEDINTPARAMETER_H_INCLUDED
#define UNSIGNEDINTPARAMETER_H_INCLUDED


#include "JuceHeader.h"


class UnsignedIntParameter : public juce::AudioProcessorParameter {
public:
	UnsignedIntParameter(String name, unsigned int newValue, unsigned int newMax);
	~UnsignedIntParameter();

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

	unsigned int getUnsignedInt() const;
	void setUnsignedInt(unsigned int newValue);

private:
	unsigned int value;
	unsigned int max;
	String name;
	bool dirty;
};



#endif  // UNSIGNEDINTPARAMETER_H_INCLUDED
