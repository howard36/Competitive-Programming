#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	int x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	int a1 = (x2 - x1)*(y2 - y1);
	int a2 = (x4 - x3)*(y4 - y3);
	int a3 = 0, a4 = 0;
	if (x5 < x2 && x6 > x1 && y5 < y2 && y6 > y1)
		a3 = (min(x2, x6) - max(x1, x5))*(min(y2, y6) - max(y1, y5));
	if (x5 < x4 && x6 > x3 && y5 < y4 && y6 > y3)
		a4 = (min(x4, x6) - max(x3, x5))*(min(y4, y6) - max(y3, y5));
	fout << a1 + a2 - a3 - a4 << endl;
    return 0;
}
