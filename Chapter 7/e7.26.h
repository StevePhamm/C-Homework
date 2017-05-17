#include <iostream>
using namespace std;

struct Sales_data;
istream &read(istream &is, Sales_data&);

struct Sales_data
{
	friend Sales_data& add(const Sales_data& lhs, const Sales_data& rhs);
	friend istream& read(istream &is, Sales_data& item);
	friend ostream& print(ostream &os, const Sales_data& item);

public:
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) { }
	Sales_data(istream &is) { read(is, *this); }

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
private:
	inline double avg_price() const;
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this; // Returns object that was called, lhs value
}

istream& read(istream &is, Sales_data& item) // not constant since we're changing the object
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream &os, const Sales_data& item) // constant since we're not changing the object
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

double Sales_data::avg_price() const
{
	return units_sold ? revenue/units_sold : 0;
}