#include <bits/stdc++.h>
using namespace std;

/*
BOJ 22289번 기준
아래 소스코드: 656ms
AtCoder Library convolution_ll: 832ms
*/

typedef double f_t;
typedef complex<f_t> C;

void fft(vector<C>& a) {
    // https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/FastFourierTransform.h
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<C> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar((f_t) 1.0, acos((f_t) -1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto x = (f_t *)&rt[j+k], y = (f_t *)&a[i+j+k];
                C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            } 
        }
    }
}

vector<f_t> conv(const vector<f_t>& a, const vector<f_t>& b) {
    if (a.empty() || b.empty()) return {};
    vector<f_t> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (size_t i = 0; i < b.size(); i++) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for (size_t i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    return res;
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b){
    auto&& A = vector<f_t>(all(a));
    auto&& B = vector<f_t>(all(b));
    auto&& tmp = conv(A, B);
    auto&& ret = vector<ll>(tmp.size());
    for(int i = 0; i < tmp.size(); i++) ret[i] = round(tmp[i]);
    return ret;
}

/*
------------------------------------------------------------
아래는 kks227님의 구현 참고, 위 소스보드 느림.
*/

const double PI = acos(-1);
typedef complex<double> cpx;

// non-recursive. slower than recursive function :(
void fft(vector<cpx> &f, cpx w_1){
	int n = 1, l = 0;
	while (n < f.size()) n <<= 1, l++;
	vector<cpx> ws(l); ws[0] = w_1;
	for(int i = 1; i < l; i++) ws[i] = ws[i - 1] * ws[i - 1];
	for(int i = 1; i <= l; i++){
		vector<cpx> ff(n);
		int bias = n >> i;
		for(int j = 0; j < bias; j++){
			int n = 1 << i;
			cpx wp = 1, w = ws[l - i];
			for(int k = 0; k < (n >> 1); k++){
				int l = k * bias;
				ff[j + l] = f[j + l * 2] + wp * f[j + l * 2 + bias];
				ff[j + l + bias * (n >> 1)] = f[j + l * 2] - wp * f[j + l * 2 + bias];
				wp *= w;
			}
		}
		f.swap(ff);
	}
}

vector<cpx> mul_fft(vector<cpx> a, vector<cpx> b) {
	int n = 1;
	while (n <= a.size() || n <= b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vector<cpx> c(n);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	fft(a, w); fft(b, w);
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
	fft(c, cpx(w.real(), -w.imag()));
	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b){
    auto&& A = vector<cpx>(all(a));
    auto&& B = vector<cpx>(all(b));
    auto&& tmp = conv(A, B);
    auto&& ret = vector<ll>(tmp.size());
    for(int i = 0; i < tmp.size(); i++) ret[i] = round(tmp[i].real());
    return ret;
}


// recursive version
void fft(vector<cpx> &f, cpx w) {
	int n = f.size();
	if (n == 1) return;
	vector<cpx> even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++) { (i & 1 ? odd : even)[i / 2] = f[i]; }
	fft(even, w * w); fft(odd, w * w);
	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}