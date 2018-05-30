#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
int freq[2000006];
ll totalcost, numcones;

int main()
{
	scanf("%d", &N);
	string op;
	while (N--) {
		cin >> op;
		if (op == "ADD") {
			int K, P;
			scanf("%d%d", &K, &P);
			freq[P] += K;
			totalcost += 1LL * K*P;
			numcones += K;
		}
		else if (op == "ADDRANGE") {
			int A, B;
			scanf("%d%d", &A, &B);
			for (int i = A; i <= B; i++)
				++freq[i];
			totalcost += 1LL * B*(B + 1) / 2 - 1LL * A*(A - 1) / 2;
			numcones += B - A + 1;
		}
		else if (op == "BUYAMT") {
			int Q;
			scanf("%d", &Q);
			ll count = 0;
			for (int i = 1; i < 2000006; i++) {
				if (freq[i] * i <= Q) {
					Q -= freq[i] * i;
					count += freq[i];
					totalcost -= freq[i] * i;
					freq[i] = 0;
				}
				else {
					count += Q / i;
					totalcost -= (Q / i)*i;
					freq[i] -= (Q / i);
					break;
				}
			}
			printf("%lld\n", count);
			numcones -= count;
		}
		else if (op == "BUYLOW") {
			ll L;
			scanf("%lld", &L);
			if (L > numcones) {
				printf("%lld\n", totalcost);
				numcones = 0;
				totalcost = 0;
				continue;
			}
			ll oldL = L;
			ll cost = 0;
			for (int i = 1; i < 2000006; i++) {
				if (freq[i] <= L) {
					L -= freq[i];
					cost += freq[i] * i;
					freq[i] = 0;
				}
				else {
					cost += L * i;
					freq[i] -= L;
					break;
				}
			}
			printf("%lld\n", cost);
			numcones -= oldL;
			totalcost -= cost;
		}
		else if (op == "BUYHIGH") {
			ll L;
			scanf("%lld", &L);
			if (L > numcones) {
				printf("%lld\n", totalcost);
				numcones = 0;
				totalcost = 0;
				continue;
			}
			ll oldL = L;
			ll cost = 0;
			for (int i = 2000000; i > 0; i--) {
				if (freq[i] <= L) {
					L -= freq[i];
					cost += freq[i] * i;
					freq[i] = 0;
				}
				else {
					cost += L * i;
					freq[i] -= L;
					break;
				}
			}
			printf("%lld\n", cost);
			numcones -= oldL;
			totalcost -= cost;
		}
		else if (op == "COST") {
			ll L;
			scanf("%lld", &L);
			if (L > numcones) {
				printf("-1\n");
				continue;
			}
			for (int i = 1; i < 2000006; i++) {
				if (freq[i] < L) {
					L -= freq[i];
				}
				else {
					printf("%d\n", i);
					break;
				}
			}
		}
		else if (op == "NUMCONES") {
			printf("%lld\n", numcones);
		}
		else if (op == "TOTALCOST") {
			printf("%lld\n", totalcost);
		}
	}
	return 0;
}