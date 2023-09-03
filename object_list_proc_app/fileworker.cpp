#include "fileworker.h"

void FileWorker::save(std::stringstream& sstream)
{
	file.open(filename_to_save, std::ios::out);
	file << sstream.rdbuf();
	file.flush();
	file.close();
}
void FileWorker::load(std::stringstream& res)
{
	file.open(filename_to_load, std::ios::in);
	res << file.rdbuf();
	file.flush();
	file.close();
}