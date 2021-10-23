#include "UnsignedIntParameter.h"

UnsignedIntParameter::UnsignedIntParameter(String name, unsigned int newValue, unsigned int newMax) : 
	value(newValue), max(newMax), name(name), dirty(false) {}

UnsignedIntParameter::~UnsignedIntParameter() {}

float UnsignedIntParameter::getValue() const { return static_cast<float>(value) / static_cast<float>(max); }

void UnsignedIntParameter::setValue(float newValue) {
	value = static_cast<unsigned int>(newValue * static_cast<float>(max));
	dirty = true;
}

float UnsignedIntParameter::getDefaultValue() const { return 1.0f; }

String UnsignedIntParameter::getName(int maximumStringLength) const { return name.substring(0, maximumStringLength); }

String UnsignedIntParameter::getLabel() const { return ""; }

int UnsignedIntParameter::getNumSteps() const { return max; }

String UnsignedIntParameter::getText(float newValue, int maximumStringLength) const {
	return String(static_cast<unsigned int>(newValue * static_cast<float>(max))).substring(maximumStringLength);
}

float UnsignedIntParameter::getValueForText(const String &text) const { return static_cast<float>(text.getIntValue()) / static_cast<float>(max); }

bool UnsignedIntParameter::isDirty() const { return dirty; }

void UnsignedIntParameter::setDirty(bool newValue) { dirty = newValue; }

unsigned int UnsignedIntParameter::getUnsignedInt() const { return value; }

void UnsignedIntParameter::setUnsignedInt(unsigned int newValue) {
	if (newValue < 0 || newValue > max) return;

	beginChangeGesture();
	setValueNotifyingHost(static_cast<float>(newValue) / static_cast<float>(max));
	endChangeGesture();
}
