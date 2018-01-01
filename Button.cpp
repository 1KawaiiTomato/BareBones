#include "Button.h"

void Button::setText(std::string text)
{
	this->text = text;
}

void Button::tick()
{
}

void Button::setLocation(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Button::handleEvents()
{
	while (!al_is_event_queue_empty(EQ)) {
		ALLEGRO_EVENT E;
		al_get_next_event(EQ, &E);
		if (E.mouse.x >= x && E.mouse.x < x + width && E.mouse.y >= y && E.mouse.y < y + height) {
			hover = true;
			if (E.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				pressed = true;
				std::cout << this->text << " press" << std::endl;
			}
			if (E.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				pressed = false;
				clicked = true;
				std::cout << this->text << " released" << std::endl;
			}
		}
		else { hover = false; }
		}
	if (clicked) {
		action();
		clicked = false;
		pressed = false;
	}
	if (hover && !didHover) {
		didHover = true;
		std::cout << "hover" << std::endl;
		onHoverStart();
	}
	if (!hover && didHover) {
		std::cout << "ended hover" << std::endl;
		pressed = false;
		didHover = false;
		onHoverStop();
	}
}

void Button::action()
{
	std::cout << this->text << " clicked!" << std::endl;
}

void Button::onHoverStop()
{
}

void Button::onHoverStart()
{
}

void Button::draw()
{
	al_draw_filled_rectangle(this->x, this->y, x + width, y + height, al_map_rgb(0, 50, 50));
	if (pressed) {
		al_draw_filled_rectangle(x + 5, y + 5, x + (width-5), y + (height-5), al_map_rgb(0, 30, 30));
	}
	al_draw_text(font, fontColor, this->x + 25, this->y + 15, 0, text.c_str());
}

Button::Button()
{
	didHover = false;
	hover = false;
	fontColor = al_map_rgb(255, 255, 255);
	font = al_load_ttf_font("COOPBL.TTF", 16, 0);
	pressed = false;
	clicked = false;
	this->width = 100;
	this->height = 40;
	EQ = al_create_event_queue();
	al_register_event_source(EQ, al_get_mouse_event_source());
}