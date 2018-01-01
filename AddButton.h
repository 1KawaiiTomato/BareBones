#pragma once
class OptionPad;
#include "Canvas.h"
#include "Button.h"

class AddButton
	:public Button{
private:
	Canvas *canvas;
	OptionPad *optionPad;
public:
	void action();
	AddButton(int x, int y, Canvas *canvas, OptionPad * optionPad);
};