/*
 * Img.h
 *
 *  Created on: Feb 5, 2013
 *      Author: bhikadiy
 */

#ifndef IMG_H_
#define IMG_H_
#include "includes.h"
class Img {

	cv::Mat d;
	std::string name;
	cv::Mat display;
	cv::Scalar img_mean;
public:
	Img();
	Img(cv::Mat);
	Img(cv::Mat a,std::string );
	void readme(std::string);
	void showme() const;
	std::string const getname() const;
	cv::Mat getme() const;

	virtual ~Img();
};

#endif /* IMG_H_ */
