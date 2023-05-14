#include"src/head/String.h"
#include <utility>
#include <cstring>
#include <iostream>
#include <list>
using namespace std;

bool equal_for_sort(const String& first, const String& second)
{
    return !std::lexicographical_compare(
        first.get_data(), first.get_data() + first.get_lenght(),
        second.get_data(), second.get_data() + second.get_lenght(),
        [](char left, char right) { return tolower(left) < tolower(right); });
}

int main()
{
    int count;
    const int max_count = 256;

    cout << "_______________________________" << endl;
    cout << endl;
    cout << "Castom string Nanber:9999999999" << endl;
    cout << "_______________________________" << endl;
    cout << endl;
    cout << "Write count strings for sort:";
    cin >> count;

	list<String> lines;
    char line[max_count];

    cin.ignore();
    for(int i = 0; i < count; i++)
    {
        cin.getline(line, max_count);
        lines.emplace_back(line);
    }

    lines.sort(equal_for_sort);
    cout << "_______________________________" << endl;

    cout << "Write:"<< endl;
    int i = 0;
    for (String s : lines) 
    {
        i++;
        std::cout << s <<endl;
    }

    cout << "_______________________________" << endl;

    std::cout << "exit - enter" << endl;
    getchar();
	return 0;
}