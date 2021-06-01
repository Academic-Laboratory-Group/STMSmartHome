#include "GUIBuilder.h"
#include "TextBox.h"
#include "Button.h"
#include "Shape.h"
#include "Circle.h"

#include <array>
#include <memory>


GUIBuilder::GUIBuilder()
{
}

void GUIBuilder::addButton( unsigned xCenter, unsigned yCenter, unsigned width,
		unsigned height, const std::string text, ButtonShape shape, Color color,
		unsigned textSize, Color textColor )
{
	m_gui.addButton(std::make_shared<Button>(
			xCenter, yCenter, width, height, text, shape, color, textSize, textColor));
}

void GUIBuilder::addTextBox(unsigned xCenter, unsigned yCenter, std::string text,
		unsigned size, Color color, unsigned width, unsigned height)
{
	m_gui.addTextBox(std::make_shared<TextBox>(
			xCenter, yCenter, text, size, color, width, height));
}

void GUIBuilder::addKeyboard(unsigned xCenter, unsigned yCenter,
		unsigned width, unsigned height, unsigned textSize,
		Color buttonsColor, Color textColor)
{
	const auto singleButtonAreaWidth = static_cast<float>(width) / 10.f;
	const auto singleButtonWidth = static_cast<unsigned>(0.9f * singleButtonAreaWidth);
	const auto halfOfSingleButtonAreaWidth = singleButtonAreaWidth / 2u;

	const auto singleButtonAreaHeight = static_cast<float>(height) / 3.f;
	const auto singleButtonHeight = static_cast<unsigned>(0.9f * singleButtonAreaHeight);
	const auto halfOfSingleButtonAreaHeight = static_cast<unsigned>(singleButtonAreaHeight / 2.f);

	auto leftBorder = xCenter - width / 2u;
	const auto topBorder = yCenter - height / 2u;

	const auto sdRowCenter = topBorder + static_cast<unsigned>(1.5f * singleButtonAreaHeight);
	const auto tdRowCenter = topBorder + static_cast<unsigned>(2.5f * singleButtonAreaHeight);

	const std::array<std::string, 26> letters {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P",
		"A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M"};

	for (auto i = 0.f; i < 10.f; ++i)
		addButton(static_cast<unsigned>(static_cast<float>(leftBorder) + static_cast<float>(i) *
				singleButtonAreaWidth + halfOfSingleButtonAreaWidth),
				topBorder + halfOfSingleButtonAreaHeight, singleButtonWidth, singleButtonHeight,
				letters.at(static_cast<size_t>(i)));

	leftBorder += static_cast<unsigned>(singleButtonAreaWidth / 2.0f);

	for (auto i = 0u; i < 9; ++i)
		addButton(static_cast<unsigned>(static_cast<float>(leftBorder) + static_cast<float>(i) *
				singleButtonAreaWidth + halfOfSingleButtonAreaWidth),
				sdRowCenter, singleButtonWidth, singleButtonHeight,
				letters.at(i + 10));

	leftBorder += static_cast<unsigned>(singleButtonAreaWidth);

	for (auto i = 0u; i < 7; ++i)
		addButton(static_cast<unsigned>(static_cast<float>(leftBorder) + static_cast<float>(i) *
				singleButtonAreaWidth + halfOfSingleButtonAreaWidth),
				tdRowCenter, singleButtonWidth, singleButtonHeight,
				letters.at(i + 19));

	const auto deleteMovement = static_cast<unsigned>(0.65f * static_cast<float>(singleButtonWidth));

	addButton(xCenter + width / 2u - deleteMovement,
			tdRowCenter, static_cast<unsigned>(singleButtonAreaWidth), singleButtonHeight, "<-");
}

void GUIBuilder::addCircle(int xCenter, int yCenter, int radius, Color color)
{
	m_gui.addShape(std::make_shared<Circle>(xCenter, yCenter, radius, color));
}

void GUIBuilder::setBackgroundColor(Color color)
{
	m_gui.setBackgroundColor(color);
}

void GUIBuilder::reset()
{
	m_gui = GUI();
}

GUI GUIBuilder::getResult()
{
	return m_gui;
}
