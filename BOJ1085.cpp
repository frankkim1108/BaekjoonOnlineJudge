#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min = 10000;

	if (x - 0 >= w - x)
	{
		min = w - x;
	}
	else min = x - 0;

	if (y - 0 >= h - y)
	{
		if (min > h - y)
			min = h - y;
	}
	else {
		if (min > y - 0)
			min = y - 0;
	}

	cout << min;
}
