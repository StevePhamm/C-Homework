#include <iostream>
#include <string>
#include "Header2.h"
using namespace std;


int main()
{
	Sales_data item1;
		print(cout, item1) << endl;

	Sales_data item2("0213123-X");
	print(cout, item2) << endl;

	Sales_data item3("023123-X", 2, 3.0);
	print(cout, item3) << endl;

	Sales_data item4(cin);
	print(cout, item4);

	system("pause");
	return 0;
