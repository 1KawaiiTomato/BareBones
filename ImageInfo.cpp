#include "ImageInfo.h"

void ImageInfo::action()
{
}

void ImageInfo::onHoverStart()
{
	Image *img;
	img = &images->at(index);
	img->setSelected(true);
}

void ImageInfo::onHoverStop()
{
	Image *img;
	img = &images->at(index);
	img->setSelected(false);
}

int ImageInfo::getX()
{
	return this->x;
}

int ImageInfo::getY()
{
	return this->y;
}

ImageInfo::ImageInfo(std::vector<Image> *images)
{
	this->images = images;
	this->index = images->size()-1;
	Image img = images->at(index);
	this->text = img.getName();
	width = 150;
	height = 40;
	font = al_load_ttf_font("COOPBL.TTF", 10, 0);
}

ImageInfo::ImageInfo()
{
}
