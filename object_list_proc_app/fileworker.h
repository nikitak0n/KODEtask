#pragma once
#include "inc.h";
#include <fstream>

class FileWorker
{
public:
	void save(std::stringstream& sstream);
	void load(std::stringstream& res);

private:
	const std::string filename_to_save = "CurrentSession.txt";
	const std::string filename_to_load = "Input.txt";
	std::fstream file;
};