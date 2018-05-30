#include <iostream>
#include <string>
using namespace std;

int main()
{
	int B, P;
	string S;
	cin >> B >> P >> S;
	if (B >= 5 * P) {
		if (S == "Y")
			cout << "B";
		else
			cout << "A";
	}
	else if (B >= 2*P) {
		if (S == "Y")
			cout << "D";
		else
			cout << "C";
	}
	else {
		cout << "NO PIZZA";
	}
    return 0;
}