#pragma once
#include "fileworker.h"
#include "objects.h"

class SmallApi
{
public:
	SmallApi();
	~SmallApi();
	void add(std::string& name, std::string& x, std::string& y, std::string& type, std::string& time);
	void save(std::stringstream& stream);
	void load(std::stringstream& stream);
	void clear();

	int get_interval_xy0();
	int get_interval_xy1();
	int get_interval_xy2();
	int get_interval_xy3();
	int get_interval_time0();
	int get_interval_time1();
	int get_interval_time2();
	int get_interval_time3();
	int get_num();
	std::string& get_unsorted_str();

	void set_interval_xy0(int value);
	void set_interval_xy1(int value);
	void set_interval_xy2(int value);
	void set_interval_xy3(int value);
	void set_interval_time0(int value);
	void set_interval_time1(int value);
	void set_interval_time2(int value);
	void set_interval_time3(int value);
	void set_num(int value);
private:
	FileWorker* fileworker;
	ObjectsList* objlist;
};