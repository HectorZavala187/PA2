#include <stdio.h>
#include <filesystem>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

int fileCounter = 0;
int directoryCounter = 0;
int byteSize = 0;
const std::filesystem::path absolutePath=argv[1];

for(auto itEntry = std::filesystem::recursive_directory_iterator(absolutePath);
	itEntry != std::filesystem::recursive_directory_iterator();
	++itEntry ) {

	const auto filePs = itEntry->status().permissions();


bool readable = (filePs & std::filesystem::perms::owner_read) != std::filesystem::perms::none || (filePs & std::filesystem::perms::group_read) != std::filesystem::perms::none ||(filePs & std::filesystem::perms::others_read) != std::filesystem::perms::none;


	if(itEntry->is_directory() && !itEntry->is_symlink() && readable)
		directoryCounter++;

	else if(itEntry->is_regular_file() && !itEntry->is_symlink() && readable){
		fileCounter++;
		byteSize+=itEntry->file_size(); 

	}
}


cout<<"The total number of directories in directory "<<absolutePath.string()<<" is: "<<directoryCounter<<endl;
cout<<"The total number of files in directory "<<absolutePath.string()<<" is: "<<fileCounter<<endl;
cout<<"The total number of bytes occupied by all files in directory "<<absolutePath.string()<<" is: "<<byteSize<<endl;
return 0;
}











