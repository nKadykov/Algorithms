#include <iostream>

template<typename Item>
void exch(Item &A, Item &B) {
    Item t = A;
    A = B;
    B = t;
}

template<typename Item>
void selection(Item a[], int l, int r) {
    for(int i = l; i < r; i++) {
        int min = i;
        for(int j = i + 1; j <= r; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        exch(a[i], a[min]);
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
    selection(a, 0, N - 1);
    for(i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}