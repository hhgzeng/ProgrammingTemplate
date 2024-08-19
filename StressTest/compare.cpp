#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    // MacOS
    system("g++ -std=c++2a stress__Generator.cpp -o stress__Generator");
    system("g++ -std=c++2a stress__Good.cpp -o stress__Good");
    system("g++ -std=c++2a stress.cpp -o stress");
    // Windows
    // system("g++ -std=c++2a stress__Generator.cpp -o stress__Generator.exe");
    // system("g++ -std=c++2a stress__Good.cpp -o stress__Good.exe");
    // system("g++ -std=c++2a stress.cpp -o stress.exe");
    for (int t = 1; t <= 100; t++) {
        // MacOS
        system("./stress__Generator");
        double start = clock();
        system("./stress__Good");
        double end = clock();
        system("./stress");
        // Windows
        // system("stress__Generator.exe");
        // double start = clock();
        // system("stress__Good");
        // double end = clock();
        // system("stress.exe")
        
        // system("fc good.txt bad.txt") Windows | system("diff good.txt bad.txt") MacOS
        if (system("diff good.txt bad.txt")) {
            std::cout << "\033[31m" << "Wrong Answer\n" << "\033[0m";
            std::cout << "test #" << t << ", time: "  << end - start << "ms\n";
            exit(0);
        } else {
            std::cout<< "\033[32m" << "Accept!\n"<< "\033[0m"; 
            std::cout << "test #" << t << ", time: "  << end - start << "ms\n";
        }
    }
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
