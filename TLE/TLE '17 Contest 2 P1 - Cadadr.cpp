#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 2; i <= str.length() - 2; i++)
	{
		if (str[i] == 'a')
			cout << "(car ";
		else
			cout << "(cdr ";
	}
	cout << "x";
	for (int i = 2; i <= str.length() - 2; i++)
		cout << ")";
    return 0;
}