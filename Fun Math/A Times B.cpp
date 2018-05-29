#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")

#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
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

//cd temp[1 << 21];

// a is a list of polynomial's coefficients - a[k] is the coefficient of x^k
// N must be a power of 2
void FFT(cd* a, int N, bool inverse) {
	//base cases
	if (N == 4) {
		double sign = inverse ? 1.0 : -1.0;
		cd a0 = a[0] + a[2] + a[1] + a[3];
		cd a1 = a[0] - a[2] + cd(0, sign)*(a[1] - a[3]);
		cd a2 = a[0] + a[2] - (a[1] + a[3]);
		cd a3 = a[0] - a[2] - cd(0, sign)*(a[1] - a[3]);
		a[0] = a0, a[1] = a1, a[2] = a2, a[3] = a3;
		return;
	}
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
	cd wk(1, 0); // wk = w^k
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

int read(cd* a)
{
	int c, i = 0;
	while ((c = getchar()) < '0');
	do a[i++] = cd(c - '0', 0);
	while ((c = getchar()) >= '0');
	return i;
}

cd a[1 << 21], b[1 << 21], c[1 << 21];
ll ans[1 << 21];

int main() {
	int asz, bsz; // size of arrays
	asz = read(a);
	bsz = read(b);
	// if a = 0 or b = 0
	if ((asz == 1 && a[0].r() == 0) || (bsz == 1 && b[0].r() == 0)) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < asz / 2; i++)
		swap(a[i], a[asz - 1 - i]);
	for (int i = 0; i < bsz / 2; i++)
		swap(b[i], b[bsz - 1 - i]);

	int D = (int)ceil(log2(max(asz, bsz)) + 1);
	multiply(a, b, c, 1 << D);
	for (int i = 0; i < (1 << D); i++)
		ans[i] = (ll)round(c[i].r());
	for (int i = 0; i < (1 << D) - 1; i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	int d = (1 << D) - 1;
	while (ans[d] == 0) --d;
	while (d >= 0) printf("%lld", ans[d--]);
	return 0;
}