#ifndef SIDSTEPLOOKANDFEEL_H_INCLUDED
#define SIDSTEPLOOKANDFEEL_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

class JUCE_API  SIDStepLookAndFeel:	public juce::LookAndFeel_V3 {
public:
    static const char *bigCheck_png;
    static const int bigCheck_pngSize;
	static const char *smallCheck_png;
	static const int smallCheck_pngSize;

    SIDStepLookAndFeel();
    ~SIDStepLookAndFeel();

	void drawRotarySlider(Graphics&, int x, int y, int width, int height,
		float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle,
		Slider&) override;

	void drawToggleButton(Graphics&, ToggleButton&, bool isMouseOverButton, bool isButtonDown) override;

	void drawScrollbarButton(Graphics&, ScrollBar&, int width, int height, int buttonDirection,
		bool isScrollbarVertical, bool isMouseOverButton, bool isButtonDown) override;

	void drawScrollbar(Graphics&, ScrollBar&, int x, int y, int width, int height, bool isScrollbarVertical,
		int thumbStartPosition, int thumbSize, bool isMouseOver, bool isMouseDown) override;

	bool areScrollbarButtonsVisible() override;

	int getScrollbarButtonSize(ScrollBar& scrollbar) override;

	juce::Font getComboBoxFont(juce::ComboBox& comboBox) override;

	void drawComboBox(Graphics&g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, 
					  int buttonH, ComboBox&box) override;

	void positionComboBoxText(ComboBox &box, Label &label) override;

	Font getPopupMenuFont() override;

	void drawPopupMenuBackground(Graphics&g, int width, int height) override;

	void drawPopupMenuItem(Graphics &g, const Rectangle<int>& area,
		bool isSeparator, bool isActive, bool isHighlighted,
		bool isTicked, bool hasSubMenu,
		const String& text,
		const String& shortcutKeyText,
		const Drawable* icon,
		const Colour* textColour) override;

	void drawTreeviewPlusMinusBox(Graphics &g, const Rectangle<float> &area,
		Colour backgroundColour, bool isItemOpen, bool isMouseOver) override;
};


#endif  // SIDSTEPLOOKANDFEEL_H_INCLUDED
