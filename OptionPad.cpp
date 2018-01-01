#include "OptionPad.h"

int OptionPad::getState()
{
	return state;
}

void OptionPad::tick()
{
	if (optionsVisible) {
		for (int i = 0; i < 3; i++) {
			try {
				options[i]->handleEvents();
				options[i]->draw();
			}
			catch (std::invalid_argument) {}
		}
	}
}

void OptionPad::action()
{
	optionsVisible = !optionsVisible;
	if (optionsVisible) {
		for (int i = 0; i < 3; i++) {
			options[i]->startEventQueue();
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			options[i]->stopEventQueue();
		}
	}
}

void OptionPad::draw()
{
	al_draw_filled_rectangle(this->x, this->y, x + width, y + height, al_map_rgb(0, 50, 50));
	if (pressed) {
		al_draw_filled_rectangle(x + 5, y + 5, x + (width - 5), y + (height - 5), al_map_rgb(0, 30, 30));
	}
	al_draw_text(font, fontColor, this->x + 15, this->y + 15, 0, text.c_str());
}

void OptionPad::setState(int state, std::string text)
{
	this->state = state;
	this->text = text;
}

OptionPad::OptionPad(int x, int y)
{
	optionsVisible = false;
	options[0] = new Options(0, "Images", this);
	options[1] = new Options(1, "Joints", this);
	options[2] = new Options(2, "Bones", this);
	this->font = al_load_ttf_font("COOPBL.TTF", 10, 0);
	this->width = 60;
	this->height = 45;
	this->x = x;
	this->y = y;
	this->text = "Images";
}
