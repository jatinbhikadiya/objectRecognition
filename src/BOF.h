/*
 * BOF.h
 *
 *  Created on: Apr 25, 2013
 *      Author: bhikadiy
 */

#ifndef BOF_H_
#define BOF_H_
#include "includes.h"
#include "Img.h"
class BOF {

	std::vector<Img> &set;
	std::vector<std::pair<std::string,int> >set_list;
	Mat vocabulary;
	SIFT detector;
	Ptr<DescriptorExtractor > extractor; //  extractor;
	Ptr<DescriptorMatcher> matcher=  DescriptorMatcher:: create( "BruteForce" );
	std::map<string,CvSVM> classifiers;
	CvKNearest knn;

public:
	BOF();
	BOF(std::vector<Img>&i,std::vector<std::pair<std::string,int> >s):set(i),set_list(s){};
	void trainvocab();
	void trainknn();
	void test(std::vector<Img>&);
	void testknn(std::vector<Img>&);
	std::string find_detected_class(std::vector<int>,Mat);
	void confusinmatrix(std::vector<std::string>,std::vector<std::string>);
	virtual ~BOF();
};

#endif /* BOF_H_ */
