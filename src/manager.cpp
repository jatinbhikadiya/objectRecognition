/*
 * manager.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: bhikadiy
 */

#include "manager.h"

manager::manager() {
	// TODO Auto-generated constructor stub

}

void manager::read_data(char **argv,int argc)
{
	if(argc<2)
	{
		std::cout<<"please provide Test Images directory paths\n";
		exit(0);
	}
	if(argc<3)
	{	TEST = 0;
		std::cout<<"There is only training directory.. Please provide test directory.";
	}
	reader r(img_data, test_data);


	data_path_list = mylist.get_file_list(argv[1]);

	r.image_read(data_path_list);
	for(unsigned int i=0 ; i <img_data.size();i++)
	{
		std::cout<<img_data.at(i).getname()<<std::endl;
	}

	if(TEST)
	{
	test_path_list = mylist.get_file_list(argv[2]);
	r.test_read(test_path_list);

	}
	//r.template_read(template_path_list);
	std::cout<<"Total "<<data_path_list.size()<<" Training Images are loaded \n";
	classifynames();
}


void manager::train()
{
	BOF b(img_data,set_name_index);
	b.trainvocab();
	std::cout<<"TEst is "<<TEST;
	if(TEST)
	{
		b.test(test_data);
	}
	//b.trainknn();
	//b.testknn(test_data);

}

void manager:: classifynames()
{
	int checkz,checkl,checkai,checkau;


	for(unsigned int i=0 ; i <img_data.size();i++)
	{

		checkz=img_data.at(i).getname().find("zebra");
		checkl=img_data.at(i).getname().find("leopards");
		checkai=img_data.at(i).getname().find("airplane");
		checkau=img_data.at(i).getname().find("automobile");
		if(checkz>0)
		{
			zebra.push_back(img_data.at(i));
		}
		if(checkai>0)
		{
			airplane.push_back(img_data.at(i));
		}
		if(checkl>0)
		{
			leopards.push_back(img_data.at(i));
		}
		if(checkau>0)
		{
			automobiles.push_back(img_data.at(i));
		}
	}
	std::cout<<"zebra size is "<<zebra.size()<<std::endl;
	std::cout<<"airplanes size is "<<airplane.size()<<std::endl;
	std::cout<<"leopards size is "<<leopards.size()<<std::endl;
	std::cout<<"automobile size is "<<automobiles.size()<<std::endl;

	img_data.erase(img_data.begin(),img_data.end());

	std::cout<< "\nimg_data size is"<<img_data.size();
	for(unsigned int i=0 ; i <airplane.size();i++)
	{
		img_data.push_back(airplane.at(i));
	}
	for(unsigned int i=0 ; i <automobiles.size();i++)
	{
		img_data.push_back(automobiles.at(i));
	}
	for(unsigned int i=0 ; i <leopards.size();i++)
	{
		img_data.push_back(leopards.at(i));
	}
	for(unsigned int i=0 ; i <zebra.size();i++)
	{
		img_data.push_back(zebra.at(i));
	}

	std::pair<std::string,int> temp;
	temp.first="airplane";
	temp.second = airplane.size();
	set_name_index.push_back(temp);

	temp.first="automobiles";
	temp.second = automobiles.size();
	set_name_index.push_back(temp);

	temp.first="leopards";
	temp.second = leopards.size();
	set_name_index.push_back(temp);

	temp.first="zebra";
	temp.second = zebra.size();
	set_name_index.push_back(temp);


	std::cout<< "\nimg_data size is"<<img_data.size();


}


manager::~manager()
{
	// TODO Auto-generated destructor stub
}

