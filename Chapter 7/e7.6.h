#include <iostream>
using namespace std;

struct Sales_data
{
	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
}; 


Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this; // Returns object that was called
}

istream& read(istream &is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream &os, Sales_data& item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue << " ";
	return os; 
}

Sales_data& add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs; // copy data members from lhs into sum
	sum.combine(rhs); // add data members from rhs into sum
	return sum;
}
