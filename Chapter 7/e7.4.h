#include <iostream>
#include <string>
using namespace std;

struct Person;
istream &read(istream& is, Person&);

struct Person
{
	friend istream& read(istream& is, Person& item);
	friend ostream& print(istream &os, const Person& item);
public:
	Person() = default;
	Person(const string& x, const string& y) : Name(x), address(y) {};
	Person(istream &is) { read(is, *this); }
private:
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

    