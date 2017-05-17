#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos x, pos y) : height(x), width(y), content(x*y, ' ') {}
	Screen(pos x, pos y, char ch) : height(x), width(y), content(x*y, ch) {}

	inline Screen &set(pos x, pos y, char c);
	inline Screen &set(char c);
	inline Screen &move(pos x, pos y);

	char get() const
	{
		return content[cursor];
	}

	inline char get(pos x, pos y) const;

	Screen &display(ostream &os) { do_display(os); return *this; }
private:
	void do_display(ostream &os) const { os << content; }
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string content;
};

inline Screen& Screen::set(char x)
{
	content[cursor] = x;
	return *this; // returns an lvalue, because a reference function returns an lvalue
}

inline Screen& Screen::set(pos x, pos y, char c)
{
	content[x*width + y] = c; 
	return *this; // returns an lvalue
}

inline Screen& Screen::move(pos x, pos y)
{
	cursor = x*width + y;
	return *this;
}