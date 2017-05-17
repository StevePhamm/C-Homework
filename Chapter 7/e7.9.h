#include <iostream>
using namespace std;

struct Person
{
    std::string Name;
    std::string address;
};

istream& read(istream& is, Person& item)
{
	is >> item.Name >> item.address;
	return is;
}

ostream& print(istream &os, const Person& item)
{
	os << item.Name << " " << item.address << endl;
	return os;
}

    