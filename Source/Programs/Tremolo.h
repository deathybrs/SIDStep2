#ifndef TREMOLO_H_INCLUDED
#define TREMOLO_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"


#include "../Listeners/ListenerInitializer.h"


class SidProgram;

class Tremolo: public ReferenceCountedObject,
			   public PatchEditorTremoloRangeChanged,
			   public PatchEditorTremoloSpeedChanged,
			   public PatchEditorTremoloDefaultAmountChanged,
			   public PatchEditorTremoloDefaultSpeedChanged,
			   public LiveTremoloAmountChanged,
			   public LiveTremoloSpeedChanged,
			   public TremoloAmountParameterChanged,
			   public TremoloSpeedParameterChanged
			   {
public:
	Tremolo();
	Tremolo(XmlElement *e);
	Tremolo(Tremolo &original);
	~Tremolo();

	void select(bool value);

	void write(XmlElement *e) const;
	void writeState(MemoryBlock &destData) const;
	void writeCopyState(MemoryBlock &destData) const;

	static void loadState(MemoryInputStream &stream, ReferenceCountedObjectPtr<SidProgram> o);
	static void loadCopyState(MemoryInputStream &stream, ReferenceCountedObjectPtr<SidProgram> o);

	unsigned int getTremoloRange() const;
	void setTremoloRange(unsigned int value);
	unsigned int getTremoloSpeed() const;
	void setTremoloSpeed(unsigned int value);

	float getDefaultTremoloAmount() const;
	void setDefaultTremoloAmount(float value);
	float getDefaultTremoloSpeed() const;
	void setDefaultTremoloSpeed(float value);

	float getCurrentTremoloAmount() const;
	void setCurrentTremoloAmount(float value);
	float getCurrentTremoloSpeed() const;
	void setCurrentTremoloSpeed(float value);

	int getCurrentTremoloValue() const;

	void Start();
	void Step();
	void Release();

	void onPatchEditorTremoloRangeChanged(unsigned int value) override;
	void onPatchEditorTremoloSpeedChanged(unsigned int value) override;
	void onPatchEditorTremoloDefaultAmountChanged(float value) override;
	void onPatchEditorTremoloDefaultSpeedChanged(float value) override;

	void onLiveTremoloAmountChanged(unsigned int voice, float value) override;
	void onLiveTremoloSpeedChanged(unsigned int voice, float value) override;

	void onTremoloAmountParameterChanged(unsigned int voice, float value) override;
	void onTremoloSpeedParameterChanged(unsigned int voice, float value) override;

	void setForVoice(int value);

private:
	unsigned int tremoloRange;
	unsigned int tremoloSpeed;

	float defaultTremoloAmount;
	float defaultTremoloSpeed;

	float currentTremoloAmount;
	float currentTremoloSpeed;

	unsigned int tremoloCounter;
	int forVoice;
};


#endif  // TREMOLO_H_INCLUDED
