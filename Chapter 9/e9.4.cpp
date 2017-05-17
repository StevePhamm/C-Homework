#include <iostream>
#include <vector>
using namespace std;

bool dude(vector<int>::const_iterator v1, vector<int>::const_iterator v2, const int value)
{
	for (; v1 != v2; ++v1)
		if (*v1 == value) return true;
	return false;
}

int main()
{
	vector<int> v = { 1,3,5,7 };
	cout << dude(v.begin(), v.end(), 5) << endl;
	system("pause");
	return 0;
}