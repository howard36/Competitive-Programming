#include <iostream>
using namespace std;
int main()
{
	int g, e, p;
	double prob = 1.0;
	cin >> g;
	while (g--)
	{
		cin >> e >> p;
		prob *= 1 - (double)e / p;
	}
	cout << prob;
    return 0;
}