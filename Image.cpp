#include "Image.h"

std::string Image::getName()
{
	return name;
}

void Image::draw()
{
	if (selected) {
		al_draw_filled_rectangle(x-5, y-5, x + al_get_bitmap_width(Texture)+5, y + al_get_bitmap_height(Texture)+5, al_map_rgb(255,255,0));
	}
	al_draw_bitmap(Texture, x, y, 0);
}

void Image::setSelected(bool selected)
{
	this->selected = selected;
}

bool Image::isSelected()
{
	return this->selected;
}

void Image::setLocation(int x, int y)
{
	this->x = x;
	this->y = y;
}

Image::Image(std::string location)
{
	selected = false;
	for (int i = location.size() - 1; i >= 0; i--) {
		if (location.at(i) == '\\') {
			break;
		}
		name.push_back(location.at(i));
	}
	std::reverse(name.begin(), name.end());
	this->Texture = al_load_bitmap(location.c_str());
	if (!Texture) {
		al_show_native_message_box(NULL, "Error", "Error", "Failed to load texture", NULL, NULL);
		delete this;
	}
}

Image::Image()
{
}

Image::~Image()
{
	//al_destroy_bitmap(Texture);
}
