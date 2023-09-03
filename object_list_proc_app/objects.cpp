#include "objects.h"

using namespace std;
using utils::is_double;
using utils::is_integer;

void ObjectsList::clear()
{
	objects_list.clear();
	grouping_by_name.clear();
	grouping_by_xy.clear();
	grouping_by_type.clear();
	grouping_by_time.clear();
	unsorted_str_for_UI.clear();
}

void ObjectsList::add(RawObject &obj)
{
	int index = objects_list.size();

    objects_list.push_back(obj);

    grouping_by_name			  [is_letter(obj.name[0])].push_back(index);
    grouping_by_xy	 [sqrt(obj.x * obj.x + obj.y * obj.y)].push_back(index);
    grouping_by_type							[obj.type].push_back(index);
    grouping_by_time					[obj.time_elapsed].push_back(index);
	
	unsorted_str_for_UI += obj.name + ' ' + to_string(obj.x) + ' ' \
						 + to_string(obj.y) + ' ' + obj.type + ' ' \
						 + to_string(obj.time_elapsed) + '\n';
}

void ObjectsList::add(stringstream &filedata)
{
	std::string buffer;
	while (getline(filedata, buffer))
	{
		if (is_coment(buffer))
			continue;

		vector<std::string> tmp = split(buffer,' ');

		if(tmp.size() < 5)
			continue;

		for(int i=0;i< tmp.size();i++)
			if (tmp[i].empty())
				continue;
		
		if(!is_double(tmp[1]) || !is_double(tmp[2]) || !is_integer(tmp[4]))
			continue;

		RawObject obj = RawObject(tmp[0], stod(tmp[1]), stod(tmp[2]), tmp[3], stoll(tmp[4]));
		this->add(obj);
	}
}

void ObjectsList::to_str(stringstream &res)
{
	std::string buf;

	res << "// Сортировка по имени:\n";
	res << simple_groupung<char>(&grouping_by_name);
	res << '\n' << '\n';

	res << "// Сортировка по расстоянию:\n";
	res << ("// менее " + to_string(intervals_xy[0]) + " едениц\n");
	res << range_groupung<double>(&grouping_by_xy, 0, intervals_xy[0]);
	res <<  '\n';

	res << "// от " + to_string(intervals_xy[0]) + " до " + to_string(intervals_xy[1]) + " едениц\n";
	res << range_groupung<double>(&grouping_by_xy, intervals_xy[0], intervals_xy[1]);
	res <<  '\n';

	res << "// от " + to_string(intervals_xy[1]) + " до " + to_string(intervals_xy[2]) + " едениц\n";
	res << range_groupung<double>(&grouping_by_xy, intervals_xy[1], intervals_xy[2]);
	res <<  '\n';

	res << "// от " + to_string(intervals_xy[2]) + " до " + to_string(intervals_xy[3]) + " едениц\n";
	res << range_groupung<double>(&grouping_by_xy, intervals_xy[2], intervals_xy[3]);
	res << '\n';

	res << "// более " + to_string(intervals_xy[3]) + " едениц\n";
	res << range_groupung<double>(&grouping_by_xy, intervals_xy[3], 0);
	res << '\n' << '\n';

	res << "// Сортировка по типу:\n";
	res << limit_groupung<std::string>(&grouping_by_type);
	res << '\n' << '\n';

	time_t now = time(0);

	res << "// Сортировка по времени:\n";
	res << "// менее " + to_string(intervals_time[0]) + " часов\n";
	res << range_groupung<time_t>(&grouping_by_time, now - intervals_time[0] * NUM_SECs_IN_HOUR, now);
	res << '\n';

	res << "// до " + to_string(intervals_time[1]) + " суток\n";
	res << range_groupung<time_t>(&grouping_by_time, now - intervals_time[1] * NUM_SECs_IN_DAY, now - NUM_SECs_IN_DAY);
	res << '\n';

	res << "// до " + to_string(intervals_time[2]) + " месяцев\n";
	res << range_groupung<time_t>(&grouping_by_time, now - intervals_time[2] * NUM_SECs_IN_MONTH, now - NUM_SECs_IN_MONTH);
	res << '\n';

	res << "// до " + to_string(intervals_time[3]) + " лет\n";
	res << range_groupung<time_t>(&grouping_by_time, now - intervals_time[3] * NUM_SECs_IN_YEAR, now - NUM_SECs_IN_YEAR);
	res << '\n';

	res << "// ранее \n";
	res << range_groupung<time_t>(&grouping_by_time, 0, now - intervals_time[3] * NUM_SECs_IN_YEAR);
	res << '\n' << '\n';

}

template<typename Type>
string ObjectsList::simple_groupung(map<Type, vector<int>>* hash_table)
{
	string res;

	for (auto it = (*hash_table).begin(); it != (*hash_table).end(); it++)
	{
		res += "// "; 
		res += is_letter(objects_list[*it->second.begin()].name[0]);
		res += '\n';

		for (auto i : it->second)
		{
			res += objects_list[i].name + ' ';
			res += to_string(objects_list[i].x) + ' ';
			res += to_string(objects_list[i].y) + ' ';
			res += objects_list[i].type + ' ';
			res += to_string(objects_list[i].time_elapsed) + ' ';
			res += ctime(&(objects_list[i].time_elapsed));
		}
	}

	return res;
}

template<typename Type>
string ObjectsList::limit_groupung(map<Type, vector<int>>* hash_table)
{
	string res;
	
	vector<int> list_raznogo;

	for (auto it = (*hash_table).begin(); it != (*hash_table).end(); it++)
	{

		if(it->second.size()< num_obj_for_new_type)
			list_raznogo.insert(list_raznogo.end(), it->second.begin(), it->second.end());
		else
		{ 
			res += "//";
			res += objects_list[*it->second.begin()].type;
			res += '\n';

			for (auto i : it->second)
			{
				res += objects_list[i].name + ' ';
				res += to_string(objects_list[i].x) + ' ';
				res += to_string(objects_list[i].y) + ' ';
				res += objects_list[i].type + ' ';
				res += to_string(objects_list[i].time_elapsed) + ' ';
				res += ctime(&(objects_list[i].time_elapsed));
			}
		}
	}
	res += "//Разное:\n";
	for (auto i = list_raznogo.begin(); i != list_raznogo.end(); i++)
	{
		res += objects_list[*i].name + ' ';
		res += to_string(objects_list[*i].x) + ' ';
		res += to_string(objects_list[*i].y) + ' ';
		res += objects_list[*i].type + ' ';
		res += to_string(objects_list[*i].time_elapsed) + ' ';
		res += ctime(&(objects_list[*i].time_elapsed));
	}
	return res;
}

template<typename Type>
string ObjectsList::range_groupung(map<Type, vector<int>>* hash_table, int min, int max)
{
	string res;
	int time;

	auto beg = min == 0 ? (*hash_table).begin() : (*hash_table).lower_bound(min);
	auto end = max == 0 ? (*hash_table).end() : (*hash_table).upper_bound(max);


	for (auto it = beg; it != end; it++)
	{
		for (auto i : it->second)
		{
			res += objects_list[i].name + ' ';
			res += to_string(objects_list[i].x) + ' ';
			res += to_string(objects_list[i].y) + ' ';
			res += objects_list[i].type + ' ';
			res += to_string(objects_list[i].time_elapsed) + ' ';
			res += ctime(&(objects_list[i].time_elapsed));
		}
	}
	return res;
}

//Utils
char ObjectsList::is_letter(char letter)
{
	if (letter >= (char)0xc0 && letter <= (char)0xff)
		return letter;

	return (char)0x23;
}

bool ObjectsList::is_coment(string& symbols)
{
	if (symbols.size() < 2)
		return true;

	return (symbols[0] == '/' && symbols[1] == '/');
}

vector<std::string> ObjectsList::split(std::string& str, char separator)
{
	vector<std::string> res;
	std::string param;
	stringstream s(str);
	while (getline(s, param, separator))
	{
		if (!param.empty())
			res.push_back(param);
	}
	return res;
}