#include "BooleanParameter.h"

BooleanParameter::BooleanParameter(String name, bool newValue) :
	value(newValue), name(name), dirty(false) {}

BooleanParameter::~BooleanParameter() {}

float BooleanParameter::getValue() const { return value ? 1.0f : 0.0f; }

void BooleanParameter::setValue(float newValue) {
	value = newValue < 0.5f ? false : true;
	dirty = true;
}

float BooleanParameter::getDefaultValue() const { return 1.0f; }

String BooleanParameter::getName(int maximumStringLength) const { return name.substring(0, maximumStringLength); }

String BooleanParameter::getLabel() const { return ""; }

int BooleanParameter::getNumSteps() const { return 2; }

String BooleanParameter::getText(float newValue, int maximumStringLength) const {
	return String(newValue ? "On" : "Off").substring(maximumStringLength);
}

float BooleanParameter::getValueForText(const String &text) const {
	if (text == "On") return 1.0f;

	return 0.0f ;
}

bool BooleanParameter::isDirty() const { return dirty; }

void BooleanParameter::setDirty(bool newValue) { dirty = newValue; }

bool BooleanParameter::getBoolean() const { return value; }

void BooleanParameter::setBoolean(bool newValue) {
	beginChangeGesture();
	setValueNotifyingHost(newValue ? 1.0f : 0.0f);
	endChangeGesture();
}
