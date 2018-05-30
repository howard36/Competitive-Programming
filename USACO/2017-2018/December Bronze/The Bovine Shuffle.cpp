#include <iostream>
#include <fstream>
using namespace std;

int per[102], inv[102], ans[102];

int main()
{
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int N;
	fin >> N;
	for (int i = 1; i <= N; i++)
		fin >> per[i];
	for (int i = 1; i <= N; i++)
		inv[per[i]] = i;
	for (int i = 1; i <= N; i++)
		fin >> ans[inv[inv[inv[i]]]];
	for (int i = 1; i <= N; i++)
		fout << ans[i] << endl;
    return 0;
}
