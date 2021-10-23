#include "Tremolo.h"


#include "../SIDProgram.h"


Tremolo::Tremolo(): tremoloRange(7), tremoloSpeed(5), defaultTremoloAmount(0), defaultTremoloSpeed(1), 
					currentTremoloAmount(defaultTremoloAmount), currentTremoloSpeed(defaultTremoloSpeed), 
					tremoloCounter(0), forVoice(-1) {
	
	SharedResourcePointer<ListenerList<LiveTremoloAmountChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveTremoloSpeedChanged>>()->add(this);

	SharedResourcePointer<ListenerList<TremoloAmountParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<TremoloSpeedParameterChanged>>()->add(this);
}

Tremolo::Tremolo(XmlElement *e): tremoloRange(static_cast<unsigned int>(e->getIntAttribute("range"))),
									   tremoloSpeed(static_cast<unsigned int>(e->getIntAttribute("speed"))),
									   defaultTremoloAmount(static_cast<float>(e->getDoubleAttribute("default-amount"))),
									   defaultTremoloSpeed(static_cast<float>(e->getDoubleAttribute("default-speed"))),
									   currentTremoloAmount(defaultTremoloAmount), 
									   currentTremoloSpeed(defaultTremoloSpeed), tremoloCounter(0), forVoice(-1) {

	SharedResourcePointer<ListenerList<LiveTremoloAmountChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveTremoloSpeedChanged>>()->add(this);

	SharedResourcePointer<ListenerList<TremoloAmountParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<TremoloSpeedParameterChanged>>()->add(this);
}

Tremolo::Tremolo(Tremolo &original): tremoloRange(original.tremoloRange), tremoloSpeed(original.tremoloSpeed),
									 defaultTremoloAmount(original.defaultTremoloAmount),
									 defaultTremoloSpeed(original.defaultTremoloSpeed),
									 currentTremoloAmount(defaultTremoloAmount),
									 currentTremoloSpeed(defaultTremoloSpeed), tremoloCounter(0), forVoice(-1) {

	SharedResourcePointer<ListenerList<LiveTremoloAmountChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveTremoloSpeedChanged>>()->add(this);

	SharedResourcePointer<ListenerList<TremoloAmountParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<TremoloSpeedParameterChanged>>()->add(this);
}

Tremolo::~Tremolo() {
	SharedResourcePointer<ListenerList<LiveTremoloAmountChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<LiveTremoloSpeedChanged>>()->remove(this);

	SharedResourcePointer<ListenerList<TremoloAmountParameterChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<TremoloSpeedParameterChanged>>()->remove(this);
}

void Tremolo::select(bool value) {
	if (value) {
		SharedResourcePointer<ListenerList<PatchEditorTremoloRangeChanged>>()->add(this);
		SharedResourcePointer<ListenerList<PatchEditorTremoloSpeedChanged>>()->add(this);
		SharedResourcePointer<ListenerList<PatchEditorTremoloDefaultAmountChanged>>()->add(this);
		SharedResourcePointer<ListenerList<PatchEditorTremoloDefaultSpeedChanged>>()->add(this);
	} else {
		SharedResourcePointer<ListenerList<PatchEditorTremoloRangeChanged>>()->remove(this);
		SharedResourcePointer<ListenerList<PatchEditorTremoloSpeedChanged>>()->remove(this);
		SharedResourcePointer<ListenerList<PatchEditorTremoloDefaultAmountChanged>>()->remove(this);
		SharedResourcePointer<ListenerList<PatchEditorTremoloDefaultSpeedChanged>>()->remove(this);
	}
}

void Tremolo::write(XmlElement *e) const {
	XmlElement *t = e->getChildByName("tremolo");
	if (t == nullptr) {
		t = new XmlElement("tremolo");
		e->addChildElement(t);
	}

	t->setAttribute("range", String(tremoloRange));
	t->setAttribute("speed", String(tremoloSpeed));
	t->setAttribute("default-amount", String(defaultTremoloAmount));
	t->setAttribute("default-speed", String(defaultTremoloSpeed));
}

void Tremolo::writeState(MemoryBlock &destData) const {
	destData.append(static_cast<const void *>(&tremoloRange), sizeof(tremoloRange));
	destData.append(static_cast<const void *>(&tremoloSpeed), sizeof(tremoloSpeed));
	destData.append(static_cast<const void *>(&defaultTremoloAmount), sizeof(defaultTremoloAmount));
	destData.append(static_cast<const void *>(&defaultTremoloSpeed), sizeof(defaultTremoloSpeed));
}

void Tremolo::writeCopyState(MemoryBlock &destData) const {
	destData.append(static_cast<const void *>(&currentTremoloAmount), sizeof(currentTremoloAmount));
	destData.append(static_cast<const void *>(&currentTremoloSpeed), sizeof(currentTremoloSpeed));
}

void Tremolo::loadState(MemoryInputStream &stream, ReferenceCountedObjectPtr<SidProgram> o) {
	ReferenceCountedObjectPtr<Tremolo> t = o->GetExpression()->getTremolo();

	stream.read(&t->tremoloRange, sizeof(t->tremoloRange));
	stream.read(&t->tremoloSpeed, sizeof(t->tremoloSpeed));
	stream.read(&t->defaultTremoloAmount, sizeof(t->defaultTremoloAmount));
	stream.read(&t->defaultTremoloSpeed, sizeof(t->defaultTremoloSpeed));
}

void Tremolo::loadCopyState(MemoryInputStream &stream, ReferenceCountedObjectPtr<SidProgram> o) {
	ReferenceCountedObjectPtr<Tremolo> t = o->GetExpression()->getTremolo();

	stream.read(&t->currentTremoloAmount, sizeof(t->currentTremoloAmount));
	stream.read(&t->currentTremoloSpeed, sizeof(t->currentTremoloSpeed));
}

unsigned int Tremolo::getTremoloRange() const { return tremoloRange; }
void Tremolo::setTremoloRange(unsigned int value) { if (value < 8) tremoloRange = value; }
unsigned int Tremolo::getTremoloSpeed() const { return tremoloSpeed; }
void Tremolo::setTremoloSpeed(unsigned int value) { tremoloSpeed = value; }
float Tremolo::getDefaultTremoloAmount() const { return defaultTremoloAmount; }
float Tremolo::getDefaultTremoloSpeed() const { return defaultTremoloSpeed; }
float Tremolo::getCurrentTremoloAmount() const { return currentTremoloAmount; }
float Tremolo::getCurrentTremoloSpeed() const { return currentTremoloSpeed; }

void Tremolo::setCurrentTremoloAmount(float value) {
	if (value < 0.0f || value > 1.0f) return;
	if ((currentTremoloAmount == 0 && value != 0) || (currentTremoloAmount != 0 && value == 0)) tremoloCounter = 0;

	currentTremoloAmount = value;
}

void Tremolo::setDefaultTremoloAmount(float value) {
	if (value >= -1.0f && value <= 1.0f) currentTremoloAmount = defaultTremoloAmount = value;
}

void Tremolo::setCurrentTremoloSpeed(float value) {
	if (value < 0.0f || value > 1.0f) return;

	currentTremoloSpeed = value;
}

void Tremolo::setDefaultTremoloSpeed(float value) {
	if (value >= -1.0f && value <= 1.0f) currentTremoloSpeed = defaultTremoloSpeed = value;
}

int Tremolo::getCurrentTremoloValue() const {
	if (currentTremoloAmount == 0 || currentTremoloSpeed == 0) return 0;

	double A = currentTremoloAmount * tremoloRange;
	double t = static_cast<float>(tremoloCounter) /
		(static_cast<float>(tremoloSpeed) * static_cast<float>(currentTremoloSpeed));
	const double PI = 3.1415926535897932384626433832795;

	return static_cast<int>(A * sin(2.0 * PI * t));
}

void Tremolo::Start() {
	tremoloCounter = 0;
}

void Tremolo::Step() {
	if (currentTremoloAmount != 0) tremoloCounter++;
}

void Tremolo::Release() {}

void Tremolo::onPatchEditorTremoloRangeChanged(unsigned int value) { setTremoloRange(value); }
void Tremolo::onPatchEditorTremoloSpeedChanged(unsigned int value) { setTremoloSpeed(value); }
void Tremolo::onPatchEditorTremoloDefaultAmountChanged(float value) { setDefaultTremoloAmount(value); }
void Tremolo::onPatchEditorTremoloDefaultSpeedChanged(float value) { setDefaultTremoloSpeed(value); }

void Tremolo::onLiveTremoloAmountChanged(unsigned int voice, float value) { if (voice == forVoice) setCurrentTremoloAmount(value); }
void Tremolo::onLiveTremoloSpeedChanged(unsigned int voice, float value) { if (voice == forVoice) setCurrentTremoloSpeed(value); }

void Tremolo::onTremoloAmountParameterChanged(unsigned int voice, float value) { if (voice == forVoice) setCurrentTremoloAmount(value); }
void Tremolo::onTremoloSpeedParameterChanged(unsigned int voice, float value) { if (voice == forVoice) setCurrentTremoloSpeed(value); }

void Tremolo::setForVoice(int value) {
	if (value > -1 && value < 3) {
		SharedResourcePointer<ListenerList<TremoloAmountParameterChanged>>()->call(&TremoloAmountParameterChanged::onTremoloAmountParameterChanged,
			value, getCurrentTremoloAmount());
		SharedResourcePointer<ListenerList<TremoloSpeedParameterChanged>>()->call(&TremoloSpeedParameterChanged::onTremoloSpeedParameterChanged,
			value, getCurrentTremoloSpeed());
	}
	forVoice = value;
}
