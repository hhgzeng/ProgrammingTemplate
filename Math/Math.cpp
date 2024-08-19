struct Z {
    const int P = 1e9 + 7;
    std::vector<int> primes, isprime, phi;
    std::vector<int> f, inv1, inv2;
    std::vector<int> a, b;
    int plen, n;

    Z() {};
    Z(int n) {
        init(n);
    }

    void init(int n) {
        primes.assign(n + 1, 0);
        isprime.assign(n + 1, 0);
        phi.assign(n + 1, 0);
        f.assign(n + 1, 0);
        inv1.assign(n + 1, 0);
        inv2.assign(n + 1, 0);
        a.assign(n + 1, 0);
        b.assign(n + 1, 0);
        sieve();
        getinv1();
        getinv2();
    }   

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    int qpow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            a = a * a % P;
            b >>= 1;
        }    
        return res;
    }

    int exgcd(int b, int p, int &a, int &k) {
        if (p == 0) {
            a = 1, k = 0;
            return b;
        }
        int g = exgcd(p, b % p, k, a);
        k -= b / p * a;
        return g;
    }

    void getinv1() {
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i % P;
        }
        inv1[n - 1] = qpow(f[n - 1], P - 2);
        for (int i = n - 1; i >= 0; i--) {
            inv1[i] = inv1[i + 1] * (i + 1) % P;
        }
    }

    void getinv2() {
        inv2[1] = 1;
        for (int i = 2; i <= n; i++) {
            inv2[i] = (P - P / i) * inv2[P % i] % P;
        }
    }

    int C(int n, int m) {
        return f[n] * inv1[m] % P * inv1[n - m] % P;
    }

    int A(int n, int m) {
        return f[n] * inv1[n - m] % P;
    }

    int Lucas(int n, int m) {
        if (m == 0) return 1;
        return C(n % P, m % P) * Lucas(n / P, m / P) % P;
    }

    void sieve() {
        phi[1] = 1;
        isprime[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (isprime[i]) {
                primes[++plen] = i;
                phi[i] = i - 1;
            }
            for (int j = 1; j <= plen && i * primes[j] <= n; j++) {
                isprime[i * primes[j]] = 1;
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
                if (i % primes[j] == 0) {
                    phi[i * primes[j]] = phi[i] * primes[j];
                    break;
                }
            }
        }
    }

    int excrt() {
        int A = a[1], B = b[1];
        for (int i = 2; i <= n; i++) {
            int p, q;
            int g = exgcd(A, a[i], p, q);
            if ((B - b[i]) % g != 0) {
                return -1;
            }
            int t = a[i] / g;
            p = (p * ((b[i] - B) / g) % t + t) % t;
            B = A * p + B;
            A = A / g * a[i];
        }
        return B;
    }

    int Stirling(int n, int m) {
        int res = 0;
        for (int i = 0; i <= m; i++) {
            if ((m - i) & 1) {
                res = (res - qpow(i, n) * inv1[i] % P * inv1[m - i] % P + P) % P;
            } else {
                res = (res + qpow(i, n) * inv1[i] % P * inv1[m - i] % P) % P;
            }
        }
        return res;
    }
};