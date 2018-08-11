#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int
#define ll long long

int primes[20000000];

// write n − 1 as 2r·d with d odd by factoring powers of 2 from n − 1
// WitnessLoop: repeat k times:
//    pick a random integer a in the range [2, n − 2]
//    x ← ad mod n
//    if x = 1 or x = n − 1 then
//       continue WitnessLoop
//    repeat r − 1 times:
//       x ← x2 mod n
//       if x = 1 then
//          return composite
//       if x = n − 1 then
//          continue WitnessLoop
//    return composite
// return probably prime

bool isPrime(int n) {
}

int main() {
    int n = 300000000;
    ui A, B, C, D;
    // scanf("%d", &n);
    // scanf("%u %u %u %d", &A, &B, &C, &D);
    // primes.push_back(2);
    // primes.push_back(3);
    // primes.push_back(5);
    printf("Starting\n");
    int p = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 6; i <= n; i += 6) {
        if (i % 1000000 == 0)
            printf("%d\n", i);
        bool prime1 = true, prime2 = true;
        // for (int j = 2; j < primes.size() && j * j <= i + 1; j++) {
        //     if ((i + 1) % j == 0) {
        //         prime1 = false;
        //         break;
        //     }
        // }
        // for (int j = 2; j < primes.size() && j * j <= i + 5; j++) {
        //     if ((i + 5) % j == 0) {
        //         prime2 = false;
        //         break;
        //     }
        // }
        if (prime1) {
            primes[p++] = i + 1;
        }
        if (prime2) {
            primes[p++] = i + 5;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Solved in " << duration.count() << " seconds\n";
    ui ans = 0;
    for (int i = 0; i < primes.size(); i++) {
        ui a = 0, p = primes[i], N = n;
        while (N) {
            N /= p;
            a += N;
        }
        ans += a * (A * p * p * p + B * p * p + C * p + D);
    }
    printf("%u", ans);
}