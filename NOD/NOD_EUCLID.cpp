#include <iostream>
#include <ctime>

int EuclidGCD(int a, int b) {
    if (a < b) {
        int d = a;
        a = b;
        b = d;
    }

    while (b != 0) {
        int d = b;
        b = a % b;
        a = d;
    }
    return a;
}


int main() {
    int a = 3918848, res;
    int b = 1653264;
    for (int i = 1; i <= 11; i++) {
        clock_t st_time = clock();
        for (int i = 0; i <= 100000000; i++) {
            res = EuclidGCD(a, b);
        }
        clock_t e_time = clock();
        double time = double(e_time - st_time) / CLOCKS_PER_SEC;
        std::cout << "ITER " << i << ": Gcd(" << a << ", " << b << ") = " << res << ", time: " << time << " sec" << std::endl;
        b *= 2;
    }

    return 0;
}