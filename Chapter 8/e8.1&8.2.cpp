#include <iostream>
#include <string>
using namespace std;

istream &func(istream &is)
{
	string buff; 
	while(is >> buff)
		cout << buff << endl;
	is.clear();
	return is;
}


int main()
{
	istream &hello = func(cin);
	cout << hello.rdstate() << endl;
	return 0;
}