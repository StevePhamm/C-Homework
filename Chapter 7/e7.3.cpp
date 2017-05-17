#include <iostream>
#include <string>
#include "Header2.h"
using namespace std;


int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (trans.isbn() == total.isbn()) // if the total's isbn is still the same as trans
			{
				total.combine(trans);
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl; //prints data for total
				total = trans; // resets total to the new trans' isbn
			}
		}
	}
	else
	{
		cout << "No data " << endl;
		return -1;
	}
	return 0;
}