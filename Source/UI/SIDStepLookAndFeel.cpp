#include "../../JuceLibraryCode/JuceHeader.h"
#include "SIDStepLookAndFeel.h"

SIDStepLookAndFeel::SIDStepLookAndFeel() {}

SIDStepLookAndFeel::~SIDStepLookAndFeel() {}

void SIDStepLookAndFeel::drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle,
                                          float rotaryEndAngle, Slider &) {

	Colour black(0xff000000);
	Colour white(0xffffffff);
	float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
	float centerX = x + width / 2.0f;
	float centerY = y + width / 2.0f;

	float outerSize = float(width > height ? height : width);
	Rectangle<float> outer(outerSize, outerSize);
	if (width > height) outer.setX(float(x + width - height));
	else outer.setY(float(y + height - width));

	float innerSize = (width > height ? height : width) * 2.0f / 3.0f;
	Rectangle<float> inner(x + (width - innerSize) / 2.0f, y + (height - innerSize) / 2.0f, innerSize, innerSize);

	g.setColour(black);
	g.fillEllipse(outer);

	g.setColour(white);
	g.drawEllipse(inner, 4.0f);
	g.setColour(black);
	g.fillEllipse(inner);

	g.setColour(white);
	Path p;
	p.addTriangle(
		-outerSize / 12.0f, -outerSize / 6.0f,
		0, -outerSize / 3.0f,
		outerSize / 12.0f, -outerSize / 6.0f
	);
	g.fillPath(p, AffineTransform::rotation(angle).translated(centerX, centerY));
}

void SIDStepLookAndFeel::drawToggleButton(Graphics &g, ToggleButton &button, bool, bool) {

	if (!button.getToggleState()) return;

	Image image;
	if (jmin(button.getWidth(), button.getHeight()) > 20)
		image = ImageCache::getFromMemory(bigCheck_png, bigCheck_pngSize);
	else
		image = ImageCache::getFromMemory(smallCheck_png, smallCheck_pngSize);

	g.drawImage(image, 0, 0, button.getWidth(), button.getHeight(), 0, 0, image.getWidth(),
	            image.getHeight());
}

void SIDStepLookAndFeel::drawScrollbarButton(Graphics &g, ScrollBar &, int width, int height, int buttonDirection,
                                             bool, bool, bool) {

	Colour ltBlue(0xff5090d0);
	Path p;

	if (buttonDirection == 0)
		p.addTriangle(width * 0.5f, height * 0.125f,
		              width * 0.0625f, height * 0.875f,
		              width * 0.875f, height * 0.875f);
	else if (buttonDirection == 2)
		p.addTriangle(width * 0.5f, height * 0.875f,
		              width * 0.0625f, height * 0.125f,
		              width * 0.875f, height * 0.125f);

	g.setColour(ltBlue);

	g.fillPath(p);
}

void SIDStepLookAndFeel::drawScrollbar(Graphics &g, ScrollBar &, int x, int, int width, int,
                                       bool isScrollbarVertical, int thumbStartPosition, int thumbSize, bool, bool) {

	Colour ltBlue(0xff5090d0);

	if (isScrollbarVertical && thumbSize > 0) {
		g.setColour(ltBlue);
		g.fillRect(x + width * 0.0625f, float(thumbStartPosition), width * 0.8125f, float(thumbSize));
	}
}

bool SIDStepLookAndFeel::areScrollbarButtonsVisible() {
	return true;
}

int SIDStepLookAndFeel::getScrollbarButtonSize(ScrollBar &scrollbar) {
	return jmin(scrollbar.getWidth(), scrollbar.getHeight());
}

juce::Font SIDStepLookAndFeel::getComboBoxFont(juce::ComboBox&) {
	return Font("C64 Pro", 14.00f, Font::plain);
}

void SIDStepLookAndFeel::drawComboBox(Graphics &g, int width, int height, bool, int buttonX, int buttonY, 
									  int buttonW, int buttonH, ComboBox &) {
	
	Colour blue(0xff181090);
	Colour ltBlue(0xff5090d0);

	g.setColour(ltBlue);
	g.fillRoundedRectangle(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height), 4.0f);

	const float arrowX = 0.3f;
	const float arrowH = 0.2f;

	g.setColour(blue);
	g.fillRect(static_cast<float>(buttonX - buttonW * 0.16666666666666666666666666666667f), static_cast<float>(buttonY),
		static_cast<float>(buttonW * 0.125f), static_cast<float>(buttonH));

	Path p;

	p.addTriangle(
		buttonX + buttonW * 0.5f, buttonY + buttonH * 0.75f,
		buttonX + buttonW * 0.08333333333333333333333333333333f, buttonY + buttonH * 0.25f,
		buttonX + buttonW * 0.875f, buttonY + buttonH * 0.25f);

	//g.setColour(blue);

	g.fillPath(p);
}

void SIDStepLookAndFeel::positionComboBoxText(ComboBox &box, Label &label) {
	label.setFont(getComboBoxFont(box));
	label.setJustificationType(Justification::centredLeft);
	label.setBounds(8, 0, box.getWidth() - 32, box.getHeight());
}

Font SIDStepLookAndFeel::getPopupMenuFont() {
	return Font("C64 Pro", 14.00f, Font::plain);
}

void SIDStepLookAndFeel::drawPopupMenuBackground(Graphics &g, int width, int height) {
	Colour ltBlue(0xff5090d0);

	g.setColour(ltBlue);
	g.fillRect(0, 0, width, height);
}

void SIDStepLookAndFeel::drawPopupMenuItem(Graphics &g, const Rectangle<int> &area, bool isSeparator, bool isActive, 
	bool isHighlighted, bool isTicked, bool hasSubMenu, const String &text, const String &shortcutKeyText, 
	const Drawable *icon, const Colour *) {

	Colour blue(0xff181090);
	Colour ltBlue(0xff5090d0);

	if (isSeparator)
	{
		Rectangle<int> r(area.reduced(5, 0));
		r.removeFromTop(r.getHeight() / 2 - 1);

		g.setColour(Colour(0x33000000));
		g.fillRect(r.removeFromTop(1));

		g.setColour(Colour(0x66ffffff));
		g.fillRect(r.removeFromTop(1));
	}
	else
	{
		Rectangle<int> r(area.reduced(1));

		if (isHighlighted)
		{
			g.setColour(blue);
			g.fillRect(r);

			g.setColour(ltBlue);
		}
		else
		{
			g.setColour(blue);
		}

		if (!isActive)
			g.setOpacity(0.3f);

		Font font(getPopupMenuFont());

		const float maxFontHeight = area.getHeight() / 1.3f;

		if (font.getHeight() > maxFontHeight)
			font.setHeight(maxFontHeight);

		g.setFont(font);

		Rectangle<float> iconArea(r.removeFromLeft((r.getHeight() * 5) / 4).reduced(3).toFloat());

		if (icon != nullptr)
		{
			icon->drawWithin(g, iconArea, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, 1.0f);
		}
		else if (isTicked)
		{
			Image image = isHighlighted ?  
				ImageCache::getFromMemory(smallCheck_png, smallCheck_pngSize) :
				ImageCache::getFromMemory(bigCheck_png, bigCheck_pngSize);

			if (iconArea.getWidth() < iconArea.getHeight()) {
				g.drawImage(image, static_cast<int>(2 + (iconArea.getHeight() - iconArea.getWidth() - 4) / 2), 2, 
					static_cast<int>(iconArea.getHeight() - 4), static_cast<int>(iconArea.getHeight() - 4), 0, 0, 
					static_cast<int>(image.getWidth()), static_cast<int>(image.getHeight()));
			} else {
				g.drawImage(image, 2, static_cast<int>(2 + (iconArea.getWidth() - iconArea.getHeight() - 4) / 2), 
					static_cast<int>(iconArea.getWidth() - 4), static_cast<int>(iconArea.getWidth() - 4), 
					0, 0, static_cast<int>(image.getWidth()), static_cast<int>(image.getHeight()));
			}
		}

		if (hasSubMenu)
		{
			const float arrowH = 0.6f * getPopupMenuFont().getAscent();

			const float x = (float)r.removeFromRight((int)arrowH).getX();
			const float halfH = (float)r.getCentreY();

			Path p;
			p.addTriangle(x, halfH - arrowH * 0.5f,
				x, halfH + arrowH * 0.5f,
				x + arrowH * 0.6f, halfH);

			g.fillPath(p);
		}

		r.removeFromRight(3);
		g.drawFittedText(text, r, Justification::centredLeft, 1);

		if (shortcutKeyText.isNotEmpty())
		{
			Font f2(font);
			f2.setHeight(f2.getHeight() * 0.75f);
			f2.setHorizontalScale(0.95f);
			g.setFont(f2);

			g.drawText(shortcutKeyText, r, Justification::centredRight, true);
		}
	}
}

void SIDStepLookAndFeel::drawTreeviewPlusMinusBox(Graphics &g, const Rectangle<float> &area, Colour backgroundColour, 
	bool isItemOpen, bool) {
	
	Colour ltBlue(0xff5090d0);

	float width = area.getWidth();
	float height = area.getHeight();

	Path p;
	if (isItemOpen) {
		p.addTriangle(width * 0.5f, height * 0.875f,
			width * 0.0625f, height * 0.125f,
			width * 0.875f, height * 0.125f);
	} else {
		p.addTriangle(width * 0.875f, height * 0.5f,
			width * 0.125f, height *0.0625f,
			width * 0.125f, height * 0.875f);
	}

	g.setColour(ltBlue);
	g.fillPath(p);
}

static const unsigned char resource_LiveMode_bigCheck_png[] = {137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,45,0,0,0,47,8,6,0,0,0,119,210,67,145,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
	0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,7,137,73,68,
	65,84,104,129,205,154,105,108,84,215,21,199,127,231,189,153,241,110,207,24,47,128,1,111,216,44,38,140,161,208,32,154,180,9,66,21,13,97,49,97,137,146,20,69,180,165,18,9,96,72,80,69,219,72,86,65,173,26,
	42,176,73,91,53,164,164,74,213,180,137,40,241,18,10,36,13,33,95,162,146,196,4,47,49,212,198,96,199,128,49,198,198,43,96,143,231,189,219,15,3,4,195,188,193,216,99,211,255,135,209,140,222,255,222,243,211,
	213,189,231,158,119,52,194,255,145,114,118,148,39,152,118,22,136,98,158,136,57,67,33,113,10,98,5,20,80,135,146,191,101,119,76,255,173,60,104,80,128,69,191,43,141,179,233,250,207,148,200,58,32,60,144,87,
	80,191,126,224,208,139,118,150,101,233,26,135,129,113,40,232,56,115,133,182,51,87,232,62,215,137,167,171,23,227,186,23,16,162,38,68,51,249,185,233,128,52,216,30,36,240,210,130,138,111,161,204,127,3,174,
	174,175,219,169,59,84,203,181,166,110,191,94,101,170,155,223,46,62,48,232,197,249,149,137,40,163,8,112,181,126,117,153,218,194,83,40,195,244,235,213,29,58,41,11,51,125,63,148,122,71,27,57,204,111,180,
	246,245,82,187,38,198,62,96,92,215,185,142,128,192,0,41,79,100,18,54,42,12,224,75,123,135,227,143,15,4,186,249,186,61,31,197,163,158,206,30,106,222,169,10,8,60,102,238,120,226,179,19,1,58,77,228,153,125,
	121,89,158,17,135,94,146,95,190,26,212,58,179,207,164,230,221,42,250,174,122,44,189,209,169,78,38,204,79,3,80,32,107,74,114,221,213,0,35,10,189,108,119,249,28,65,237,1,168,63,120,154,238,11,93,150,94,
	71,116,40,25,203,179,16,77,64,177,189,40,215,189,255,230,179,17,131,206,217,81,158,96,154,106,63,16,210,116,236,60,205,39,46,90,122,53,155,70,230,170,44,236,17,118,64,14,102,119,184,243,250,61,31,94,212,
	27,82,74,148,93,237,5,198,118,214,183,243,245,135,103,2,218,83,23,102,18,153,20,5,80,47,182,158,213,121,121,210,111,211,143,8,116,78,65,217,203,192,147,125,87,251,168,253,231,201,219,114,238,221,26,61,
	59,137,248,25,163,1,174,138,200,162,194,23,31,110,189,211,51,236,121,122,241,206,47,103,41,100,59,10,206,22,87,227,233,182,62,120,81,227,162,73,94,144,14,160,20,252,168,104,163,251,43,127,190,97,93,233,
	21,127,168,138,212,116,237,109,192,113,241,63,231,104,171,105,177,244,58,34,29,100,174,202,66,116,13,20,59,138,115,179,223,181,242,14,43,180,199,219,247,39,20,153,87,27,187,104,56,82,103,233,19,77,200,
	88,153,133,61,42,4,224,72,123,71,219,47,2,205,59,108,208,57,187,202,214,136,226,89,195,99,112,122,127,224,27,111,220,188,20,162,38,196,0,210,96,120,189,79,127,146,247,184,55,208,220,195,2,253,84,193,137,
	12,37,236,6,168,59,80,67,79,235,53,75,111,116,170,147,177,115,147,1,188,154,50,159,121,255,229,89,214,123,232,134,130,14,157,151,167,52,3,217,11,68,180,148,55,209,82,113,201,210,235,136,116,144,177,124,
	42,162,129,8,175,188,183,105,198,167,3,137,17,116,232,114,103,217,75,40,30,237,235,234,165,238,112,173,165,79,68,72,95,54,5,123,132,3,224,3,119,155,251,213,129,198,8,42,116,206,174,227,83,76,228,87,40,
	56,83,92,125,163,128,247,175,164,239,37,19,147,230,2,184,100,183,219,159,191,243,2,9,164,160,65,63,150,119,212,166,68,127,75,32,244,210,241,11,180,215,94,177,244,70,37,59,73,250,110,10,128,169,148,249,
	220,190,23,178,154,238,39,86,208,160,93,78,215,207,129,217,189,109,61,52,124,104,157,222,236,17,118,50,151,79,65,52,64,169,109,197,155,102,126,116,191,177,130,2,189,116,215,137,108,5,191,84,74,113,166,
	248,20,134,199,98,91,8,164,45,153,116,51,31,127,98,79,58,189,109,48,241,134,12,189,34,175,202,33,194,91,128,253,210,103,23,232,172,239,176,244,142,253,206,120,92,153,113,0,151,77,221,124,118,223,202,149,
	198,96,98,14,25,186,207,229,221,170,144,233,61,45,215,104,248,232,172,165,47,124,76,36,227,31,79,5,48,69,100,117,201,250,153,141,131,141,121,87,193,244,212,174,138,52,67,51,95,0,30,65,145,166,160,22,97,
	79,241,198,236,191,220,229,125,173,98,178,97,152,91,125,219,162,26,211,235,63,1,104,54,141,140,101,83,125,117,5,178,187,112,163,251,240,96,129,225,182,149,94,177,179,42,54,39,191,236,77,67,204,26,20,155,
	81,124,27,136,19,152,35,138,55,151,20,148,111,239,55,82,41,49,13,227,117,32,164,249,120,35,93,231,172,183,197,248,249,105,132,197,135,35,80,229,140,137,222,58,20,96,0,1,95,195,196,166,241,129,130,36,229,
	53,105,169,108,166,185,172,137,222,214,107,68,167,58,73,95,58,25,209,53,211,52,205,135,75,54,207,44,5,88,178,171,252,199,34,234,13,79,183,135,138,215,62,199,219,235,255,240,197,164,185,152,242,67,55,8,
	30,83,99,78,201,134,236,19,67,133,182,229,236,40,79,80,154,58,170,32,190,171,161,131,179,197,255,229,122,235,245,91,134,150,202,102,194,18,35,72,122,36,89,211,68,127,17,120,126,113,126,101,162,96,188,
	10,80,127,176,214,18,88,15,179,145,190,116,178,111,105,148,228,149,108,112,15,25,24,64,83,54,181,13,136,239,168,109,227,228,95,203,251,1,223,212,165,47,26,81,74,129,168,21,63,216,125,44,90,48,242,1,87,
	91,77,11,87,78,54,91,78,158,250,68,38,142,232,16,20,124,106,79,170,30,240,53,125,79,104,132,249,0,245,135,106,80,22,7,201,211,209,75,199,217,118,128,240,16,51,116,143,192,211,134,199,75,221,1,235,218,
	34,110,90,2,113,15,37,0,116,217,148,182,122,176,233,205,63,52,196,162,192,211,213,23,208,216,82,118,235,166,93,5,112,254,72,61,158,206,30,191,94,123,84,8,169,55,219,88,200,166,253,155,166,91,231,194,65,
	72,67,168,68,32,60,49,34,160,241,202,169,203,24,61,190,189,219,125,161,139,166,47,206,251,55,10,164,47,201,68,15,179,129,146,226,162,92,247,222,96,2,3,104,10,42,0,34,198,68,6,52,154,94,147,166,210,70,
	12,143,193,217,146,106,148,69,77,54,122,118,18,206,137,163,0,154,197,203,218,32,243,2,96,19,83,149,34,66,76,186,139,166,207,47,4,52,159,63,90,79,115,105,35,189,237,254,183,69,136,51,148,241,190,54,22,
	38,242,147,146,45,110,235,83,58,4,105,226,213,14,2,70,76,122,44,154,93,15,104,86,134,105,9,12,144,246,228,36,116,135,142,18,222,46,201,117,151,4,153,245,150,180,194,45,238,102,5,199,52,155,134,51,221,
	57,232,137,18,102,140,33,102,162,11,224,178,217,231,205,13,26,161,31,105,190,15,85,12,224,156,20,55,168,73,28,145,14,146,191,159,14,128,130,245,3,121,57,29,138,124,181,135,33,197,0,174,204,81,190,226,
	252,62,149,186,208,151,45,4,85,18,168,201,18,44,105,0,133,47,101,215,8,84,217,35,28,68,167,184,238,107,130,81,211,226,113,77,137,3,161,163,207,148,117,195,66,121,135,110,173,171,137,252,29,32,110,122,
	226,128,7,219,194,236,164,44,200,0,64,148,218,114,96,115,118,224,244,19,36,125,3,173,243,15,64,197,78,141,71,15,29,88,95,50,101,65,58,246,72,7,192,199,133,27,179,255,60,60,136,119,235,22,244,251,235,221,
	117,32,135,116,135,78,226,172,49,247,28,232,156,24,75,156,123,52,192,53,52,125,45,34,214,253,219,32,171,255,177,19,118,2,140,157,59,1,91,184,221,114,144,45,220,70,218,162,73,190,33,138,87,138,54,60,20,
	184,75,30,100,245,131,46,218,232,62,162,132,127,217,194,237,100,174,204,34,124,116,36,122,152,13,221,161,35,186,134,35,58,132,184,105,137,100,173,153,137,35,198,87,114,218,146,106,10,70,18,24,110,188,
	185,220,174,69,5,165,19,116,165,127,12,146,126,143,145,149,70,159,119,222,112,231,100,255,161,253,40,231,247,159,141,50,189,161,191,209,80,115,21,140,5,98,240,253,19,160,21,168,84,168,247,18,195,140,55,
	246,252,116,86,224,122,118,152,244,63,182,79,196,73,153,18,101,111,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char *SIDStepLookAndFeel::bigCheck_png = reinterpret_cast<const char*>(resource_LiveMode_bigCheck_png);
const int SIDStepLookAndFeel::bigCheck_pngSize = 2060;

static const unsigned char resource_WavetableRow_smallCheck_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,12,0,0,0,13,8,6,0,0,0,157,41,143,66,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,163,73,
68,65,84,40,145,133,144,207,75,20,113,24,135,159,247,59,227,174,237,150,211,208,202,72,5,182,81,186,144,44,4,221,250,7,162,162,91,88,32,94,10,139,46,22,133,120,41,182,91,16,101,6,29,34,163,67,132,29,59,
8,5,209,193,147,135,68,16,19,201,245,87,254,96,119,75,220,153,93,209,118,103,119,190,29,34,16,153,234,61,63,207,251,126,62,175,240,159,113,172,39,157,34,220,3,90,5,25,150,127,195,3,87,99,205,241,23,71,
47,180,131,18,166,135,38,230,213,95,97,123,176,195,140,154,79,219,47,117,16,63,212,196,242,135,57,180,214,15,66,133,35,188,106,20,173,223,36,207,183,237,105,76,196,88,249,180,64,121,181,52,82,240,110,
190,12,21,126,90,165,199,205,39,91,210,137,180,131,155,221,32,55,182,250,45,162,35,221,32,218,220,13,31,180,7,78,155,123,27,174,181,158,57,134,95,174,48,255,110,198,15,36,184,188,236,221,40,2,152,144,
81,142,109,117,138,150,148,82,245,161,32,144,231,201,115,109,202,136,24,204,12,127,193,223,244,239,126,247,110,141,253,89,104,182,88,251,159,237,59,108,93,143,57,113,10,227,185,94,59,117,192,178,83,9,
242,159,215,40,45,21,71,243,158,247,112,103,2,19,197,197,84,87,26,213,96,80,90,44,90,201,179,199,169,122,21,86,62,46,110,27,245,160,7,50,193,78,65,161,153,218,42,148,17,5,39,122,78,17,105,138,178,48,242,
149,122,165,118,127,173,124,123,118,119,71,5,122,212,205,22,127,159,139,26,172,79,21,112,179,27,19,121,207,125,20,246,65,165,12,243,237,143,201,188,174,110,86,217,94,223,98,233,253,92,205,64,95,129,76,
45,76,16,0,199,30,236,23,173,251,0,95,144,59,57,183,247,117,24,12,240,11,188,142,153,119,91,153,76,51,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* SIDStepLookAndFeel::smallCheck_png = reinterpret_cast<const char*>(resource_WavetableRow_smallCheck_png);
const int SIDStepLookAndFeel::smallCheck_pngSize = 550;
