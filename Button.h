#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_ttf.h"
#include "allegro5\allegro_font.h"
#include <string>
#include <iostream>

class Button {
protected:
	int x, y;
	int width, height;
	bool pressed, clicked, hover, didHover;
	std::string text;
	ALLEGRO_COLOR fontColor;
	ALLEGRO_FONT *font;
	ALLEGRO_EVENT_QUEUE *EQ;
public:
	virtual void setText(std::string text);
	virtual void tick();
	virtual void setLocation(int x, int y);
	virtual void handleEvents();
	virtual void action();
	virtual void onHoverStop();
	virtual void onHoverStart();
	virtual void draw();
	Button();




};