#include <iostream>

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
void insertion(Item a[], int l, int r) {
    int i;
    for(i = r; i > l; i--) {
        compexch(a[i - 1], a[i]);
    }
    for(i = l + 2; i <= r; i++) {
        int j = i;
        Item v = a[i];
        while(v < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
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
    insertion(a, 0, N - 1);
    for(i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}