#include <iostream>
using namespace std;

class Screen
{
public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos x, pos y) : height(x), width(y), content(x*y, ' ') {}
	Screen(pos x, pos y, char ch) : height(x), width(y), content(x*y, ch) {}

	char get() const
	{
		return content[cursor];
	}

	inline char get(pos x, pos y) const;
	Screen &move(pos x, pos y);
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string content;
};
