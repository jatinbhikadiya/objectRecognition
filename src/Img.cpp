/*
 * Img.cpp
 *
 *  Created on: Feb 5, 2013
 *      Author: bhikadiy
 */

#include "Img.h"
#include "include_boost.h"

Img::Img()
{
	// TODO Auto-generated constructor stub
}

Img::Img(cv::Mat a)
{
	d=a.clone();
	name = "default";
	d.copyTo(display);

}
Img::Img(cv::Mat a,std::string n)
{
	d=a.clone();
	name = n;
	d.copyTo(display);

}

void Img::readme(std::string path)
{
	d = cv::imread(path,CV_LOAD_IMAGE_GRAYSCALE);
	name = path;
	if (!d.data)
	{
		std::cout << "Image data not loaded properly" << std::endl;
	    std::cin.get();
	}
	d.copyTo(display);
	img_mean = mean(d);

	//std::cout<<fs::path(path).stem();
	name = fs::path(path).stem().string();
	//std::cout<<name<<std::endl;
}

cv::Mat Img::getme() const
{
	return d;
}
std::string const Img::getname() const
{
	return name;
}

void Img::showme() const
{
	imshow(name, display);
	cv::waitKey(0);
	cv::destroyWindow(name);
}

Img::~Img() {
	// TODO Auto-generated destructor stub
}

