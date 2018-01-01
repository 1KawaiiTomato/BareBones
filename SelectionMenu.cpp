#include "SelectionMenu.h"

void SelectionMenu::clearBackground()
{ 
	al_draw_filled_rectangle(displayWidth - width, 0, displayWidth, displayHeight, backgroundColor);
}

void SelectionMenu::handleEvents()
{
	ALLEGRO_MOUSE_STATE MS;
	al_get_mouse_state(&MS);
	if (MS.z != mouseZ && MS.z != 0) {
		mouseZ = MS.z;
		al_set_mouse_z(0);
		for (unsigned int i = 0; i < imageBlocks.size(); i++) {
			imageBlocks[i].setLocation(imageBlocks[i].getX(), imageBlocks[i].getY() + 5 * mouseZ);
		}
		imageBlocksHeight += 5 * mouseZ;
	}
}

void SelectionMenu::addImageInfo(ImageInfo imageInfo)
{
	imageInfo.setLocation(850, imageBlocksHeight);
	imageBlocks.push_back(imageInfo);
	imageBlocksHeight += 50;
}

void SelectionMenu::tick()
{
	this->handleEvents();
	addButton->handleEvents();
	optionPad->handleEvents();
	optionPad->tick();
	if (optionPad->getState() == 0) {
		for (unsigned int i = 0; i < imageBlocks.size(); i++) {
			imageBlocks[i].handleEvents();
		}
	}
}

void SelectionMenu::draw()
{
	clearBackground();
	al_draw_line(displayWidth - width, 0, displayWidth - width, displayHeight, al_map_rgb(30, 30, 30), 0.5);
	if (optionPad->getState() == 0) {
		for (unsigned int i = 0; i < imageBlocks.size(); i++) {
			imageBlocks[i].draw();
		}
	}
	al_draw_filled_rectangle(displayWidth - width, 0, displayWidth, height, al_map_rgb(0, 0, 0));
	addButton->draw();
	optionPad->draw();
	
}

SelectionMenu::SelectionMenu(int red, int blue, int green, Canvas *canvas)
{
	mouseZ = 0;
	//EQ = al_create_event_queue();
	//al_register_event_source(EQ, al_get_mouse_event_source());
	width = 150;
	height = 100;
	imageBlocksHeight = 100;
	displayWidth = al_get_display_width(al_get_current_display());
	displayHeight = al_get_display_height(al_get_current_display());
	backgroundColor = al_map_rgb(red, blue, green);
	optionPad = new OptionPad(displayWidth - width + 88, 20);
	addButton = new AddButton(displayWidth - width, 20, canvas, optionPad);
	font = al_load_ttf_font("COOPBL.TTF", 10, 0);
}
