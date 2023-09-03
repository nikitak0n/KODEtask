#pragma once
#include "inc.h"

	//Ётот класс состоит из вектора обьектов, добавленных в пор€дке очереди
	//и map'ов.  лючом map выбраны те параметры обьектов по которым задаетс€ сортировка, 
	//«начением map - лист индексов тех обьектов параметры которых совпадают с ключом 
	//вектор обьектов и map'ы заполн€ютс€ методом add
	//функции ***_grouping задают правило группировки и достают из map'ов соответствующие элементы
class ObjectsList
{
	//This class consists of a vector of objects added in order
	//and maps. The map key selects those parameters of objects by which sorting is specified,
	//The map value is a list of indices of those objects whose parameters match the key
	//vector of objects and maps are filled with the add method
	//functions ***_grouping set the grouping rule and get the corresponding elements from maps	
public:		
	void add(RawObject &obj);
	void add(std::stringstream &filedata);
	void to_str(std::stringstream &res);
	void clear();

	int intervals_xy[4] = { 10,100,1000,10000 };
	time_t intervals_time[4] = { 24, 30, 12, 10 };
	int num_obj_for_new_type = 1;

	std::string unsorted_str_for_UI;

private:
	template<typename Type>
	std::string range_groupung(std::map<Type, std::vector<int>>* hash_table, int min, int max);

	template<typename Type>
	std::string simple_groupung(std::map<Type, std::vector<int>>* hash_table);

	template<typename Type>
	std::string limit_groupung(std::map<Type, std::vector<int>>* hash_table);


	std::vector<RawObject> objects_list;

	std::map<char,		std::vector<int>> grouping_by_name;
	std::map<double,		std::vector<int>> grouping_by_xy;
	std::map<std::string,	std::vector<int>> grouping_by_type;
	std::map<time_t,		std::vector<int>> grouping_by_time;

	//Utils
	bool is_coment(std::string& symbols);
	char is_letter(char letter);
	std::vector<std::string> split(std::string& str, char separator);
};
