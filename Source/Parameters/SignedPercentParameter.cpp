#include "SignedPercentParameter.h"

SignedPercentParameter::SignedPercentParameter(String name, float newValue, int steps): value(newValue), steps(steps),
                                                                                        name(name), dirty(false) {}

SignedPercentParameter::~SignedPercentParameter() {}

float SignedPercentParameter::getValue() const {
	return (value + 1.0f) / 2.0f;
}

void SignedPercentParameter::setValue(float newValue) {
	if (value < -1.0f || value > 1.0f) return;

	value = newValue * 2.0f - 1.0f;
	dirty = true;
}

float SignedPercentParameter::getDefaultValue() const {
	return 0.0f;
}

String SignedPercentParameter::getName(int maximumStringLength) const {
	return name.substring(0, maximumStringLength);
}

String SignedPercentParameter::getLabel() const {
	return "%";
}

int SignedPercentParameter::getNumSteps() const {
	return steps;
}

String SignedPercentParameter::getText(float newValue, int maximumStringLength) const {
	return String(static_cast<int>(newValue * 200.0f - 100.0f)).substring(maximumStringLength);
}

float SignedPercentParameter::getValueForText(const String &text) const {
	return static_cast<float>(text.getIntValue() + 100) / 200.0f;
}

bool SignedPercentParameter::isDirty() const {
	return dirty;
}

void SignedPercentParameter::setDirty(bool newValue) {
	dirty = newValue;
}

float SignedPercentParameter::getSignedPercent() const {
	return value;
}

void SignedPercentParameter::setSignedPercent(float newValue) {
	if (newValue < -1.0f || newValue > 1.0f) return;

	beginChangeGesture();
	setValueNotifyingHost((newValue + 1.0f) / 2.0f);
	endChangeGesture();
}
