#pragma once
#include "Button.h"
#include "Image.h"
#include <vector>

class ImageInfo :
	public Button {

private:
	std::vector<Image> *images;
	int index;
public:
	void action();
	void onHoverStart();
	void onHoverStop();
	int getX();
	int getY();
	ImageInfo(std::vector<Image> *images);
	ImageInfo();


};