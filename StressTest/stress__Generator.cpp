#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    freopen("in.txt", "w", stdout);
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    
    i64 a, b;
    a = rng() % 1000000 + 1;
    b = rng() % 1000000 + 1;
    std::cout << a << " " << b << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
    	solve();
    }

    return 0;
}