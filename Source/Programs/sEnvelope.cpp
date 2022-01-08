#include "Envelope.h"


#include "../JuceLibraryCode/JuceHeader.h"
#include "../SIDProgram.h"


sEnvelope::sEnvelope(): defaultAttack(0), defaultDecay(0), defaultSustain(15), defaultRelease(0), attack(defaultAttack),
	decay(defaultDecay), sustain(defaultSustain), release(defaultRelease), forVoice(-1) {
	
	SharedResourcePointer<ListenerList<LiveAttackChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveDecayChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveSustainChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveReleaseChanged>>()->add(this);

	SharedResourcePointer<ListenerList<AttackParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<DecayParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<SustainParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<ReleaseParameterChanged>>()->add(this);
}

sEnvelope::sEnvelope(XmlElement *e): defaultAttack(static_cast<unsigned int>(e->getIntAttribute("attack"))),
										 defaultDecay(static_cast<unsigned int>(e->getIntAttribute("decay"))),
										 defaultSustain(static_cast<unsigned int>(e->getIntAttribute("sustain"))),
										 defaultRelease(static_cast<unsigned int>(e->getIntAttribute("release"))),
										 attack(defaultAttack), decay(defaultDecay), sustain(defaultSustain), 
										 release(defaultRelease), forVoice(-1) {

	SharedResourcePointer<ListenerList<LiveAttackChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveDecayChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveSustainChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveReleaseChanged>>()->add(this);

	SharedResourcePointer<ListenerList<AttackParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<DecayParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<SustainParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<ReleaseParameterChanged>>()->add(this);
}

sEnvelope::sEnvelope(sEnvelope &original): defaultAttack(original.defaultAttack), defaultDecay(original.defaultDecay),
										defaultSustain(original.defaultSustain), defaultRelease(original.defaultRelease),
										attack(defaultAttack), decay(defaultDecay), sustain(defaultSustain),
										release(defaultRelease), forVoice(-1) {

	SharedResourcePointer<ListenerList<LiveAttackChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveDecayChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveSustainChanged>>()->add(this);
	SharedResourcePointer<ListenerList<LiveReleaseChanged>>()->add(this);

	SharedResourcePointer<ListenerList<AttackParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<DecayParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<SustainParameterChanged>>()->add(this);
	SharedResourcePointer<ListenerList<ReleaseParameterChanged>>()->add(this);
}

sEnvelope::~sEnvelope() {
	SharedResourcePointer<ListenerList<LiveAttackChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<LiveDecayChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<LiveSustainChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<LiveReleaseChanged>>()->remove(this);

	SharedResourcePointer<ListenerList<AttackParameterChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<DecayParameterChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<SustainParameterChanged>>()->remove(this);
	SharedResourcePointer<ListenerList<ReleaseParameterChanged>>()->remove(this);
}

void sEnvelope::select(bool value) {
	if (value) {
		SharedResourcePointer<ListenerList<PatchEditorAttackChanged>>()->add(this);
		SharedResourcePointer<ListenerList<PatchEditorDecayChanged>>()->add(this);
		SharedResourcePointer<ListenerList<PatchEditorSustainChanged>>()->add(this);
		SharedResourcePointer<ListenerList<PatchEditorReleaseChanged>>()->add(this);
	} else {
		SharedResourcePointer<ListenerList<PatchEditorAttackChanged>>()->remove(this);
		SharedResourcePointer<ListenerList<PatchEditorDecayChanged>>()->remove(this);
		SharedResourcePointer<ListenerList<PatchEditorSustainChanged>>()->remove(this);
		SharedResourcePointer<ListenerList<PatchEditorReleaseChanged>>()->remove(this);
	}
}

void sEnvelope::write(XmlElement *e) const {
	XmlElement *env = e->getChildByName("envelope");
	if (env == nullptr) {
		env = new XmlElement("envelope");
		e->addChildElement(env);
	}

	env->setAttribute("attack", String(defaultAttack));
	env->setAttribute("decay", String(defaultDecay));
	env->setAttribute("sustain", String(defaultSustain));
	env->setAttribute("release", String(defaultRelease));
}

void sEnvelope::writeState(MemoryBlock &destData) const {
	destData.append(static_cast<const void *>(&defaultAttack), sizeof(defaultAttack));
	destData.append(static_cast<const void *>(&defaultDecay), sizeof(defaultDecay));
	destData.append(static_cast<const void *>(&defaultSustain), sizeof(defaultSustain));
	destData.append(static_cast<const void *>(&defaultRelease), sizeof(defaultRelease));
}

void sEnvelope::writeCopyState(MemoryBlock &destData) const {
	destData.append(static_cast<const void *>(&attack), sizeof(attack));
	destData.append(static_cast<const void *>(&decay), sizeof(decay));
	destData.append(static_cast<const void *>(&sustain), sizeof(sustain));
	destData.append(static_cast<const void *>(&release), sizeof(release));
}

void sEnvelope::loadState(MemoryInputStream &stream, ReferenceCountedObjectPtr<SidProgram> o) {
	ReferenceCountedObjectPtr<sEnvelope> e = o->GetEnvelope();

	stream.read(&e->defaultAttack, sizeof(e->defaultAttack));
	stream.read(&e->defaultDecay, sizeof(e->defaultDecay));
	stream.read(&e->defaultSustain, sizeof(e->defaultSustain));
	stream.read(&e->defaultRelease, sizeof(e->defaultRelease));
}

void sEnvelope::loadCopyState(MemoryInputStream &stream, ReferenceCountedObjectPtr<SidProgram> o) {
	ReferenceCountedObjectPtr<sEnvelope> e = o->GetEnvelope();

	stream.read(&e->attack, sizeof(e->attack));
	stream.read(&e->decay, sizeof(e->decay));
	stream.read(&e->sustain, sizeof(e->sustain));
	stream.read(&e->release, sizeof(e->release));
}

unsigned int sEnvelope::getAttack() const { return attack; }
void sEnvelope::setAttack(unsigned int value) {
	if (value <= 0xf) 
		attack = value;
}
unsigned int sEnvelope::getDecay() const { return decay; }
void sEnvelope::setDecay(unsigned int value) { if (value <= 0xf) decay = value; }
unsigned int sEnvelope::getSustain() const { return sustain; }
void sEnvelope::setSustain(unsigned int value) { if (value <= 0xf) sustain = value; }
unsigned int sEnvelope::getRelease() const { return release; }
void sEnvelope::setRelease(unsigned int value) { if (value <= 0xf) release = value; }

unsigned int sEnvelope::getDefaultAttack() const { return defaultAttack; }
void sEnvelope::setDefaultAttack(unsigned int value) { if (value <= 0xf) attack = defaultAttack = value; }
unsigned int sEnvelope::getDefaultDecay() const { return defaultDecay; }
void sEnvelope::setDefaultDecay(unsigned int value) { if (value <= 0xf) decay = defaultDecay = value; }
unsigned int sEnvelope::getDefaultSustain() const { return defaultSustain; }
void sEnvelope::setDefaultSustain(unsigned int value) { if (value <= 0xf) sustain = defaultSustain = value; }
unsigned int sEnvelope::getDefaultRelease() const { return defaultRelease; }
void sEnvelope::setDefaultRelease(unsigned int value) { if (value <= 0xf) release = defaultRelease = value; }

void sEnvelope::onPatchEditorAttackChanged(unsigned int value) { setDefaultAttack(value); }
void sEnvelope::onPatchEditorDecayChanged(unsigned int value) { setDefaultDecay(value); }
void sEnvelope::onPatchEditorSustainChanged(unsigned int value) { setDefaultSustain(value); }
void sEnvelope::onPatchEditorReleaseChanged(unsigned int value) { setDefaultRelease(value); }

void sEnvelope::onLiveAttackChanged(unsigned voice, unsigned value) { if (voice == forVoice) setAttack(value); }
void sEnvelope::onLiveDecayChanged(unsigned voice, unsigned value) { if (voice == forVoice) setDecay(value); }
void sEnvelope::onLiveSustainChanged(unsigned voice, unsigned value) { if (voice == forVoice) setSustain(value); }
void sEnvelope::onLiveReleaseChanged(unsigned voice, unsigned value) { if (voice == forVoice) setRelease(value); }

void sEnvelope::onAttackParameterChanged(unsigned voice, unsigned value) { if (voice == forVoice) setAttack(value); }
void sEnvelope::onDecayParameterChanged(unsigned voice, unsigned value) { if (voice == forVoice) setDecay(value); }
void sEnvelope::onSustainParameterChanged(unsigned voice, unsigned value) { if (voice == forVoice) setSustain(value); }
void sEnvelope::onReleaseParameterChanged(unsigned voice, unsigned value) { if (voice == forVoice) setRelease(value); }

void sEnvelope::SetForVoice(int value) {
	if (value > -1 && value < 3) {
		SharedResourcePointer<ListenerList<AttackParameterChanged>>()->call(&AttackParameterChanged::onAttackParameterChanged,
			value, getAttack());
		SharedResourcePointer<ListenerList<DecayParameterChanged>>()->call(&DecayParameterChanged::onDecayParameterChanged,
			value, getDecay());
		SharedResourcePointer<ListenerList<SustainParameterChanged>>()->call(&SustainParameterChanged::onSustainParameterChanged,
			value, getSustain());
		SharedResourcePointer<ListenerList<ReleaseParameterChanged>>()->call(&ReleaseParameterChanged::onReleaseParameterChanged,
			value, getRelease());
	}

	forVoice = value;
}
