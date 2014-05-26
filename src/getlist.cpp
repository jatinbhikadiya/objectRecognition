/*
 * getlist.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: bhikadiy
 */

#include "getlist.h"
#include <algorithm>
getlist::getlist() {
	// TODO Auto-generated constructor stub

}


std::vector<std::string> getlist::get_file_list(std::string a)
{

	boost::progress_timer t( std::clog );

	fs::path full_path( fs::initial_path<fs::path>() );
	int err_count;

	full_path = fs::system_complete( fs::path( a ) );


	std::vector<std::string> list;
	if ( !fs::exists( full_path ) )
	{
		std::cout << "\nNot found: " << full_path.string() << std::endl;
		exit (1);
	}

	if ( fs::is_directory( full_path ) )
	{
		std::cout << "\nIn directory: "
				<< full_path.string() << "\n\n";
		fs::directory_iterator end_iter;
		for ( fs::directory_iterator dir_itr( full_path );dir_itr != end_iter;++dir_itr )
		{
			try
			{
				if ( fs::is_regular_file( dir_itr->status() ) )
				{
					if(dir_itr->path().extension() == ".png" || dir_itr->path().extension() == ".jpg" || dir_itr->path().extension() == ".pgm")
					{
					//	std::std::cout<<"here";
						list.push_back(dir_itr->path().filename().string());
					}
				}

			}
			catch ( const std::exception & ex )
			{
				++err_count;
				std::cout << dir_itr->path().filename() << " " <<  ex.what() << std::endl;
			}

		}
	/*	std::std::cout << "\n" << file_count << " files\n"
				<< dir_count << " directories\n"
				<< other_count << " others\n"
				<< err_count << " errors\n";*/

		for(unsigned int i=0;i<list.size();i++)
		{
			std::string temp = full_path.string();
			temp = temp.append("/");
			list.at(i)= temp.append(list.at(i));
			sort(list.begin(),list.end());
		}

		return list;
	}
	else // must be a file
	{
		std::cout << "\nFound: " << full_path.string() << "\n";
	}
	exit(1);
}
getlist::~getlist() {
	// TODO Auto-generated destructor stub
}

