#include <iostream>
#include <cstdlib>

template<typename Item>
void exch(Item &A, Item &B) {
    Item t = A;
    A = B;
    B = t;
}

template<typename Item>
void compexch(Item &A, Item &B) {
    if(B < A) {
        exch(A, B);
    }
}

template<typename Item>
void sort(Item a[], int l, int r) {
    for(int i = l + 1; i <= r; i++) {
        for(int j = i; j > l; j--) {
            compexch(a[j - 1], a[j]);
        }
    }
}

int main() {
    int i, N, sw;
    std::cout << "N: ";
    std::cin >> N;
    std::cout << "sw: ";
    std::cin >> sw;
    int *a = new int[N];
    if(sw) {
        for(i = 0; i < N; i++) {
            a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        }
    }
    else {
        N = 0;
        while(std::cin >> a[N]) {
            N++;
        }
    }
    sort(a, 0, N - 1);
    for(i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}