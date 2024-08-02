#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    freopen("in.txt", "r", stdin);
    freopen("bad.txt", "w", stdout);
    i64 a, b;
    std::cin >> a >> b;

    std::cout << a + b << "\n";
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