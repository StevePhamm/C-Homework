#include <iostream>
#include <string>
#include "Header.h"
using namespace std;


int main()
{
	Sales_data total(cin);
	if (!total.isbn().empty()) {
		istream &is = cin;
		while (is)
		{
			Sales_data trans(cin);
			if (trans.isbn() == total.isbn()) // if the total's isbn is still the same as trans
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans; // resets total to the new trans' isbn
			}
			print(cout, total) << endl;
		}
	}
	else
	{
		cout << "No data " << endl;
		return -1;
	}
	return 0;
}