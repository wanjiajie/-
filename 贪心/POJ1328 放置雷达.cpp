#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
	double left;
	double right;
};


bool compare(Interval a, Interval b)
{
	return a.left <= b.left;
}


int solve(Interval *intervals, int size)
{
	sort(intervals, intervals + size, compare);
	int minpoint = 1;
	double right = intervals[0].right;
	for (int i = 1; i < size; i++)
	{
		if (intervals[i].left > right)
		{
			minpoint++;
			right = intervals[i].right;
		}
		else if (intervals[i].right < right)
		{
			right = intervals[i].right;
		}
		else{}
	}
	return minpoint;
}



int main()
{
	int island, radius, testcase = 0;
	while ((cin >> island >> radius) && island && radius)
	{
		const double R2 = radius * radius;
		Interval *intervals = new Interval[island];

		bool isSolvable = true;
		for (int i = 0; i < island; i++)
		{
			double x, y;
			cin >> x >> y;
			if (y > radius) isSolvable = false;
			double offset = sqrt(R2 - y * y);
			intervals[i].left = x - offset;
			intervals[i].right = x + offset;
		}
		int minradar = (isSolvable ? solve(intervals, island) : -1);
		cout << "Case" << ++testcase << ":" << minradar << endl;
		delete[] intervals;
	}
	return 0;

}