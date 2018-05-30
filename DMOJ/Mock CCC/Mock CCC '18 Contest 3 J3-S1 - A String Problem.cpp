#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int freq[26];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		freq[s[i] - 'a']++;
	}
	sort(freq, freq + 26);
	int sum = 0;
	for (int i = 0; i < 24; i++) {
		sum += freq[i];
	}
	cout << sum;
    return 0;
}