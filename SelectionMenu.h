#pragma once
#include "allegro5\allegro_primitives.h"
class AddButton;
class Canvas;
#include "AddButton.h"
#include "OptionPad.h"
#include "ImageInfo.h"
#include <vector>

class SelectionMenu {
private:
	ALLEGRO_COLOR backgroundColor;
	ALLEGRO_EVENT_QUEUE *EQ;
	ALLEGRO_FONT *font;
	AddButton *addButton;
	OptionPad *optionPad;
	Canvas *canvas;
	int mouseZ;
	std::vector<ImageInfo> imageBlocks;
	int imageBlocksHeight;
	int width, height, displayWidth, displayHeight;
	void clearBackground();
public:
	void handleEvents();
	void addImageInfo(ImageInfo imageInfo);
	void tick();
	void draw();
	SelectionMenu(int red, int blue, int green, Canvas *canvas);


};