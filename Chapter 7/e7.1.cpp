#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (trans.bookNo == total.bookNo) // if the total's isbn is still the same as trans
			{
				total.units_sold += trans.units_sold; // adds units sold to the total
				total.revenue += trans.revenue; // adds revenue to the total
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