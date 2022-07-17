#include "UnsignedPercentParameter.h"

UnsignedPercentParameter::UnsignedPercentParameter(String name, float newValue, int steps) : value(newValue), steps(steps),
name(name), dirty(false) {}

UnsignedPercentParameter::~UnsignedPercentParameter() {}

float UnsignedPercentParameter::getValue() const {
	return value;
}

void UnsignedPercentParameter::setValue(float newValue) {
	if (newValue < 0.0f || newValue > 1.0f) return;

	value = newValue;
	dirty = true;
}

float UnsignedPercentParameter::getDefaultValue() const {
	return 0.0f;
}

String UnsignedPercentParameter::getName(int maximumStringLength) const {
	return name.substring(0, maximumStringLength);
}

String UnsignedPercentParameter::getLabel() const {
	return "%";
}

int UnsignedPercentParameter::getNumSteps() const {
	return steps;
}

String UnsignedPercentParameter::getText(float newValue, int maximumStringLength) const {
	return String(static_cast<int>(newValue)).substring(maximumStringLength);
}

float UnsignedPercentParameter::getValueForText(const String &text) const {
	return static_cast<float>(text.getIntValue()) / 100.0f;
}

bool UnsignedPercentParameter::isDirty() const {
	return dirty;
}

void UnsignedPercentParameter::setDirty(bool newValue) {
	dirty = newValue;
}

float UnsignedPercentParameter::getUnsignedPercent() const {
	return value;
}

void UnsignedPercentParameter::setUnsignedPercent(float newValue) {
	if (newValue < 0.0f || newValue > 1.0f) return;

	beginChangeGesture();
	setValueNotifyingHost(newValue);
	endChangeGesture();
}
