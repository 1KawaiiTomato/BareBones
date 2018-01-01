#include "Canvas.h"

void Canvas::addImage(Image image)
{
	Images.push_back(image);
	
}

void Canvas::setSelectionMenuPointer(SelectionMenu * selectionMenu)
{
	this->selectionMenu = selectionMenu;
}

std::vector<Image>* Canvas::getImages()
{
	return &Images;
}

void Canvas::addImages(std::vector<Image> AddingImages)
{
	for (auto it : AddingImages) {
		this->AddingImages.push_back(it);
	}
}

void Canvas::draw()
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	for (auto it : Images) {
		it.draw();
	}
	if (this->AddingImages.size() > 0) {
		timer--;
		ALLEGRO_MOUSE_STATE MS;
		ALLEGRO_KEYBOARD_STATE KS;
		al_get_keyboard_state(&KS);
		al_get_mouse_state(&MS);
		AddingImages.at(0).setLocation(MS.x - 20, MS.y - 20);
		AddingImages.at(0).draw();
		if (al_mouse_button_down(&MS, 1) && timer < 0) {
			timer = 10;
			Images.push_back(AddingImages.at(0));
			this->selectionMenu->addImageInfo(ImageInfo(&Images));
			if (!al_key_down(&KS, ALLEGRO_KEY_LCTRL)) {
				AddingImages.erase(AddingImages.begin());
			}
		}
	}
}
