#include <stdio.h>
// Time Complexity O(logn)

int customPow(int a, int power) {
    if (power == 0) {
        return 1;
    }

    int halfpower = customPow(a, power / 2);
    int halfpowersq = halfpower * halfpower;

    if (power % 2 != 0) {
        return a * halfpowersq;
    }

    return halfpowersq;
}

int main() {
    printf("%d", customPow(3, 3));
    return 0;
}
