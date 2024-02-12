#include <iostream>
#include <ctime>

int Naivegcd(int a, int b) {
    int gcd = 1;
    int MAX = std::max(a, b);

    for (int d = 2; d <= MAX; d++) {
        if (a % d == 0 && b % d == 0) {
            gcd = d;
        }
    }

    return gcd;
}

int main() {
    int a = 3918848;
    long int b = 1653264;
    for (int i = 1; i <= 11; i++) {
        clock_t st_time = clock();
        long int res = Naivegcd(a, b);
        clock_t e_time = clock();
        double time = double(e_time - st_time) / CLOCKS_PER_SEC;
        std::cout << "ITER " << i << ": Gcd(" << a << ", " << b << ") = " << res << ", time: " << time << " sec" << std::endl;
        b *= 2;
    }

    return 0;
}