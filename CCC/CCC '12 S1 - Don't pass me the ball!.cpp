#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j;
    cin >> j;
    int counter = 0;
    for(int a = 1; a < j; a++){
        for(int b = a+1; b < j; b++){
            for(int c = b+1; c < j; c++){
                counter++;
            }
        }
    }
    cout << counter;
}
