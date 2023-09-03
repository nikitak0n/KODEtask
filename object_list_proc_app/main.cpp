

/*using namespace std;

struct Keys
{
    Keys(DataObject obj)
    {
        name = obj.name[0];
        r = sqrt(obj.x * obj.x + obj.y * obj.y);
        type = obj.type;
        time_elapsed = obj.time_elapsed;
    }
    char name;
    int r;
    char type;
    int time_elapsed;
};

using namespace std;

int strStr(string haystack, string needle) {

    map<string, int> table = { {needle, 1} };
    string temp;

    for (int i = 0; i <= haystack.length() - needle.length(); i++)
    {
        temp = &haystack[i];
        temp.resize(needle.length());

        if (table[temp] == 1)
            return i;
    }
    return -1;
}


int main2()
{
    list<DataObject> objects;
    std::map<char, list<int>> group1;
    std::map<int, list<int>> group2;
    std::map<char, list<int>> group3;
    std::map<int, list<int>> group4;

    DataObject _1 = DataObject("A2", 12, 120, '2', 12);
    DataObject _2 = DataObject("B2", 40, 12, '2', 12);
    DataObject _3 = DataObject("G2", 12, 1, '2', 12);
    DataObject _4 = DataObject("B2", 40, 12, '2', 12);
    DataObject _5 = DataObject("B2", 38, 12, '2', 12);

    objects.push_back(_1);
    group1[_1.name[0]].push_back(objects.size());
    group2[sqrt(_1.x * _1.x + _1.y * _1.y)].push_back(objects.size());
    group3[_1.type].push_back(objects.size());
    group4[_1.time_elapsed].push_back(objects.size());

    objects.push_back(_2);
    group1[_2.name[0]].push_back(objects.size());
    group2[sqrt(_2.x * _2.x + _2.y * _2.y)].push_back(objects.size());
    group3[_2.type].push_back(objects.size());
    group4[_2.time_elapsed].push_back(objects.size());

    objects.push_back(_3);
    group1[_3.name[0]].push_back(objects.size());
    group2[sqrt(_3.x * _3.x + _3.y * _3.y)].push_back(objects.size());
    group3[_3.type].push_back(objects.size());
    group4[_3.time_elapsed].push_back(objects.size());

    objects.push_back(_4);
    group1[_4.name[0]].push_back(objects.size());
    group2[sqrt(_4.x * _4.x + _4.y * _4.y)].push_back(objects.size());
    group3[_4.type].push_back(objects.size());
    group4[_4.time_elapsed].push_back(objects.size());

    objects.push_back(_5);
    group1[_5.name[0]].push_back(objects.size());
    group2[sqrt(_5.x * _5.x + _5.y * _5.y)].push_back(objects.size());
    group3[_5.type].push_back(objects.size());
    group4[_5.time_elapsed].push_back(objects.size());

    for (auto it = group2.lower_bound(20); it != group2.upper_bound(100); it++)
    {
        for (auto i : it->second)
        {

            std::cout << i << endl;
        }
    }
}*/
