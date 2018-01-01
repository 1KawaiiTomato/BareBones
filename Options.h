#pragma once
#include "Button.h"
class OptionPad;
#include "OptionPad.h"



class Options
	:public Button {
private:
	int state;
	OptionPad *optionPad;
public:
	void stopEventQueue();
	void startEventQueue();
	void action();
	Options(int state, std::string text, OptionPad * optionPad);
	Options();

};