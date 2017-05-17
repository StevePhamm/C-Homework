#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos x, pos y, char z): height(x), width(y), contents(x*y, z) {}
	Screen(pos x, pos y) : height(x), width(y), contents(x*y, ' ') {}

	inline Screen& move(pos r, pos c);
	inline Screen& set(pos r, pos c, char ch);
	inline Screen& set(char c);


	const Screen& display(std::ostream &os) const { do_display(os); return *this; }
	Screen& display(std::ostream &os) {do_display(os); return *this;	}
private:
	void do_display(ostream &os) const { os << contents; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r*width + c] = ch;
	return *this;
}

inline Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}
