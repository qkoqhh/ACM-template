#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;

struct Mod64 {
    Mod64() :n_(0) {}
    Mod64(u64 n) :n_(init(n)) {}
    static u64 init(u64 w) { return reduce(u128(w) * r2); }
    static void set_mod(u64 m) {
        mod = m; assert(mod & 1);
        inv = m; for (int i = 0; i < 5; ++i) inv *= 2 - inv * m;
        r2 = -u128(m) % m;
    }
    static u64 reduce(u128 x) {
        u64 y = u64(x >> 64) - u64((u128(u64(x)*inv)*mod) >> 64);
        return ll(y)<0 ? y + mod : y;
    }
    Mod64& operator += (Mod64 rhs) { n_ += rhs.n_ - mod; if (ll(n_)<0) n_ += mod; return *this; }
    Mod64 operator + (Mod64 rhs) const { return Mod64(*this) += rhs; }
    Mod64& operator -= (Mod64 rhs) { n_ -= rhs.n_; if (ll(n_)<0) n_ += mod; return *this; }
    Mod64 operator - (Mod64 rhs) const { return Mod64(*this) -= rhs; }
    Mod64& operator *= (Mod64 rhs) { n_ = reduce(u128(n_)*rhs.n_); return *this; }
    Mod64 operator * (Mod64 rhs) const { return Mod64(*this) *= rhs; }
    u64 get() const { return reduce(n_); }
    static u64 mod, inv, r2;
    u64 n_;
};

u64 Mod64::mod, Mod64::inv, Mod64::r2;


int t, k;
u64 A0, A1, M0, M1, C, M;

void Run()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%llu%llu%llu%llu%llu%llu%d", &A0, &A1, &M0, &M1, &C, &M, &k);
        Mod64::set_mod(M);
        Mod64 a0(A0), a1(A1), m0(M0), m1(M1), c(C), ans(1), a2(0);
        ans *= a0; ans *= a1;
        for (int i = 2; i <= k; ++i)
        {
            a2 = a1;
            a1 = m0 * a1 + m1 * a0 + c;
            a0 = a2;
            ans *= a1;
        }
        printf("%llu\n", ans.get());
    }
}

int main()
{
    Run();
    return 0;
}

