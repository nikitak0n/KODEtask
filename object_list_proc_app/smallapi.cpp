#include "smallapi.h"

using namespace std;
using utils::is_double;
using utils::is_integer;

SmallApi::SmallApi()
{
	fileworker = new FileWorker();
	objlist = new ObjectsList();
}
SmallApi::~SmallApi() 
{
	delete fileworker;
	delete objlist;
}

void SmallApi::add(std::string& name, std::string& x, std::string& y, std::string& type, std::string& stime)
{
	if (!is_double(x) || !is_double(y) || !is_integer(stime))
	{
		return;
	}
	if (x.empty() || y.empty() || name.empty() || type.empty())
	{
		return;
	}

	double dx = stod(x);
	double dy = stod(y);
	time_t now;

	if (stime.empty())
	{
		now = time(0);
	}
	else
	{
		now = stoll(stime);
	}

	RawObject tmp = RawObject(name, dx, dy, type, now);
	objlist->add(tmp);
}
void SmallApi::save(std::stringstream& stream)
{
	objlist->to_str(stream);
	fileworker->save(stream);
}
void SmallApi::load(std::stringstream& stream)
{
	fileworker->load(stream);
	objlist->add(stream);
}
void SmallApi::clear()
{
	objlist->clear();
}


int SmallApi::get_interval_xy0() 
{
	return objlist->intervals_xy[0];
}
int SmallApi::get_interval_xy1()
{
	return objlist->intervals_xy[1];
}
int SmallApi::get_interval_xy2()
{
	return objlist->intervals_xy[2];
}
int SmallApi::get_interval_xy3()
{
	return objlist->intervals_xy[3];
}
int SmallApi::get_interval_time0()
{
	return objlist->intervals_time[0];
}
int SmallApi::get_interval_time1()
{
	return objlist->intervals_time[1];
}
int SmallApi::get_interval_time2()
{
	return objlist->intervals_time[2];
}
int SmallApi::get_interval_time3()
{
	return objlist->intervals_time[3];
}
int SmallApi::get_num()
{
	return objlist->num_obj_for_new_type;
}
string& SmallApi::get_unsorted_str()
{
	return objlist->unsorted_str_for_UI;
}

void SmallApi::set_interval_xy0(int value)
{
	objlist->intervals_xy[0]=value;
}
void SmallApi::set_interval_xy1(int value)
{
	objlist->intervals_xy[1]=value;
}
void SmallApi::set_interval_xy2(int value)
{
	objlist->intervals_xy[2]=value;
}
void SmallApi::set_interval_xy3(int value)
{
	objlist->intervals_xy[3]=value;
}
void SmallApi::set_interval_time0(int value)
{
	objlist->intervals_time[0]=value;
}
void SmallApi::set_interval_time1(int value)
{
	objlist->intervals_time[1]=value;
}
void SmallApi::set_interval_time2(int value)
{
	objlist->intervals_time[2]=value;
}
void SmallApi::set_interval_time3(int value)
{
	objlist->intervals_time[3]=value;
}
void SmallApi::set_num(int value)
{
	objlist->num_obj_for_new_type=value;
}

