#include <locale>
#include <iostream>
#include <ctime>

unsigned long long fibARRAY(int n) {
    unsigned long long F[1000];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    std::cout << "Введите значение n: ";
    std::cin >> n;
    clock_t st_time = clock();
    double tot_dur = 0.0;

    for (int i = 0; i <= n; ++i) {
        clock_t iter_st_time = clock();
        unsigned long long result = 0;
        for (int j = 0; j < 1000000; ++j) {
            result = fibARRAY(i);
        }

        clock_t iter_e_time = clock();
        double iter_dur = double(iter_e_time - iter_st_time) / CLOCKS_PER_SEC;
        tot_dur += iter_dur;

        std::cout << "F(" << i << ") = " << result << " (время выполнения: " << iter_dur << " сек, общее время: " << tot_dur << " сек)" << std::endl;
    }

    clock_t tot_e_time = clock();
    tot_dur = double(tot_e_time - st_time) / CLOCKS_PER_SEC;
    std::cout << "Общее время выполнения программы: " << tot_dur << " сек" << std::endl;

    return 0;
}