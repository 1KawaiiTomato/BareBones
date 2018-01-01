#pragma once
#include "Image.h"
class SelectionMenu;
#include "SelectionMenu.h"
#include <vector>

class Canvas {
private:
	std::vector<Image> Images;
	std::vector<Image> AddingImages;
	SelectionMenu *selectionMenu;
	void addImage(Image image);
	int timer = 0;
public:
	void setSelectionMenuPointer(SelectionMenu *selectionMenu);
	std::vector<Image> *getImages();
	void addImages(std::vector<Image> AddingImages);
	void draw();

};