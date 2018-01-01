#include "AddButton.h"
void AddButton::action()
{
	if (optionPad->getState() == 0) {
		ALLEGRO_FILECHOOSER *filechooser;
		filechooser = al_create_native_file_dialog("", "image", NULL, NULL);
		al_show_native_file_dialog(NULL, filechooser);
		std::vector<Image> addedImages;
		try {
			const int counter = al_get_native_file_dialog_count(filechooser);
			for (int i = 0; i < counter; i++) {
				std::cout << al_get_native_file_dialog_path(filechooser, i) << std::endl;
				addedImages.push_back(Image(al_get_native_file_dialog_path(filechooser, i)));
			}
		}
		catch (std::invalid_argument) {
			al_show_native_message_box(NULL, "Error", "Error", "Something went wrong", NULL, NULL);
		}
		canvas->addImages(addedImages);
	}
}

AddButton::AddButton(int x, int y, Canvas *canvas, OptionPad *optionPad)
{
	this->optionPad = optionPad;
	this->width = 85;
	this->height = 45;
	this->x = x;
	this->y = y;
	this->canvas = canvas;
	this->text = "Add";
}
