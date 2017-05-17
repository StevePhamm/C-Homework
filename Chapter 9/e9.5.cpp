#include <iostream>
#include <vector>
using namespace std;

auto dude(vector<int>::const_iterator v1, vector<int>::const_iterator v2, const int value)
{
	for (; v1 != v2; ++v1)
		if (*v1 == value) return v1;
	return v2;
}

int main()
{
	vector<int> v = { 1,3,5,7 };
	dude(v.begin(), v.end(), 5);
	system("pause");
	return 0;
}