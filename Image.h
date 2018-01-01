#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_native_dialog.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_primitives.h"
#include <iostream>

class Image {
private:
	ALLEGRO_BITMAP *Texture;
	std::string name;
	int x, y;
	bool selected;
public:
	std::string getName();
	void draw();
	void setSelected(bool selected);
	bool isSelected();
	void setLocation(int x, int y);
	Image(std::string location);
	Image();
	~Image();


};