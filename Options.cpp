#include "Options.h"

void Options::stopEventQueue()
{
	al_pause_event_queue(EQ, true);
	al_flush_event_queue(EQ);
}

void Options::startEventQueue()
{
	al_pause_event_queue(EQ, false);
}

void Options::action()
{
	this->optionPad->setState(state, text);
	this->optionPad->action();
}

Options::Options(int state, std::string text, OptionPad * optionPad)
{
	this->optionPad = optionPad;
	this->state = state;
	this->x = 0;
	this->y = al_get_display_height(al_get_current_display())/3 + 50*state;
	this->width = al_get_display_width(al_get_current_display());
	this->height = 50;
	this->text = text;
	al_pause_event_queue(EQ, true);
}

Options::Options()
{
}
