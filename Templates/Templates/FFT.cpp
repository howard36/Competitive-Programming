#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#define ll long long
using namespace std;

class cd {

private:
	double x, y;

public:
	cd(double _x = 0.0, double _y = 0.0) {
		x = _x;
		y = _y;
	}
	double r() const { return x; }
	double i() const { return y; }
	double norm() const { return x * x + y * y; }
	cd conj() const { return cd(this->x, -(this->y)); }
	cd operator= (const cd& o) { this->x = o.x; this->y = o.y; return *this; }
	cd operator+ (const cd& o) const { return cd(this->x + o.x, this->y + o.y); }
	cd operator- (const cd& o) const { return cd(this->x - o.x, this->y - o.y); }
	cd operator* (const cd& o) const { return cd(this->x*o.x - this->y*o.y, this->x*o.y + this->y*o.x); }
	cd operator/ (const double& o) const { return cd(this->x / o, this->y / o); }
	cd operator/ (const cd& o) const { return (*this)*(o.conj()) / (o.norm()); }
	static cd exp(double theta) { return cd(cos(theta), sin(theta)); } // returns e^(i*theta)
};

#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;

const double pi = 4 * atan(1.0);

// a is a list of polynomial's coefficients - a[k] is the coefficient of x^k
// N must be a power of 2
void FFT(cd* a, int N, bool inverse) {
	if (N == 1) //base case
		return;
	vector<cd> temp;
	temp.reserve(N / 2);
	for (int i = 0; i < N / 2; i++) {
		temp[i] = a[2 * i + 1];
		a[i] = a[2 * i];
	}
	for (int i = 0; i < N / 2; i++)
		a[i + N / 2] = temp[i];
	// even-indexed elements get moved to the front half, odd to the back 
	FFT(a, N / 2, inverse);
	FFT(a + N / 2, N / 2, inverse);
	cd w = cd::exp(-2 * pi / N); // primitive N-th root of unity
	if (inverse)
		w = w.conj();
	cd wk = 1.0; // wk = w^k
	for (int k = 0; k < N / 2; k++, wk = wk * w) {
		cd even = a[k];
		cd odd = a[k + N / 2];
		a[k] = even + wk * odd;
		a[k + N / 2] = even - wk * odd;
	}
}

// a, b, c are arrays of size N
// N is a power of 2
// a and b are polynomial coefficients, degree at most N/2
// second half of a and b must be zeros
void multiply(cd* a, cd* b, cd* c, int N) {
	FFT(a, N, false);
	FFT(b, N, false);
	for (int i = 0; i < N; i++)
		c[i] = a[i] * b[i];
	FFT(c, N, true);
	for (int i = 0; i < N; i++) {
		c[i] = c[i] / N;
	}
}

int main() {
	const int N = 4;
	cd a[N] = { 1.0, 2.0, 0, 0 };// , 0, 0, 0, 0
	cd b[N] = { 5.0, 6.0, 0, 0 };//, 0, 0, 0, 0 };
	cd c[N];
	multiply(a, b, c, N);
	for (int i = 0; i < N; i++) {
		cout << c[i].r() << ', ' << c[i].i() << endl;
	}
}