#include <locale>
#include <iostream>
#include <ctime>

unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    std::cout << "������� �������� n: ";
    std::cin >> n;

    clock_t st_time = clock();
    double tot_dur = 0.0;

    for (int i = 0; i <= n; ++i) {
        clock_t iter_st_time = clock();
        unsigned long long result = fibonacci(i);
        clock_t iter_e_time = clock();
        double iter_dur = double(iter_e_time - iter_st_time) / CLOCKS_PER_SEC;
        tot_dur += iter_dur;

        std::cout << "F(" << i << ") = " << result << " (����� ����������: " << iter_dur << " ���, ����� �����: " << tot_dur << " ���)" << std::endl;
    }

    clock_t tot_e_time = clock();
    tot_dur = double(tot_e_time - st_time) / CLOCKS_PER_SEC;
    std::cout << "����� ����� ���������� ���������: " << tot_dur << " ���" << std::endl;

    return 0;
}