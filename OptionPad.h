#pragma once
#include "Button.h"
class Options;
#include "Options.h"
#include <string>


class OptionPad : 
	public Button{
private:
	int state; //0 = images;  1 = joints;  2 = bones//
	bool optionsVisible;
	Options *options[3];
public:
	int getState();
	void tick();
	void action();
	void draw();
	void setState(int state, std::string text);
	OptionPad(int x, int y);
};