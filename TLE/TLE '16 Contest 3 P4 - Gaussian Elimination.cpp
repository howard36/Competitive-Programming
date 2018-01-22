#include <iostream>
//#include <string>
int main()
{
    int n,m;
    std::cin >> n >> m;
    if (n==1 || m==1) std::cout << "First";
    else std::cout << (((n+m)%2) ? "First" : "Second");
}