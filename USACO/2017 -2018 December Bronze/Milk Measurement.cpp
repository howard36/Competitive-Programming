#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> record;

vector<record> records;
int milk[3]{ 7,7,7 };

int main()
{
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int N, display = 7;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		record r;
		fin >> get<0>(r) >> name >> get<2>(r);
		if (name == "Bessie")
			get<1>(r) = 0;
		else if (name == "Elsie")
			get<1>(r) = 1;
		else
			get<1>(r) = 2;
		records.push_back(r);
	}
	sort(records.begin(), records.end());
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		record r = records[i];
		milk[get<1>(r)] += get<2>(r);
		int newdisplay = 0;
		int m = max(max(milk[0], milk[1]), milk[2]);
		for (int i = 0; i < 3; i++)
			if (milk[i] == m)
				newdisplay += 1 << i;
		if (newdisplay != display)
		{
			display = newdisplay;
			count++;
		}
	}
	fout << count;
	return 0;
}
