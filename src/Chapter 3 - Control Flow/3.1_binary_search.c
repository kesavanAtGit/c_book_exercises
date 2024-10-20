#include <stdio.h>

// the shittiest binary search you could ever find
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    mid = (low+high)/2;
    int mid_value = v[mid];

    if(x == mid_value) {
        return v[mid];
    }
    
    // I don't know why I named this var weight, I just did
    int weight;
    if(x < mid_value) {
        weight = 0;
    }else {
        weight = 1;
    }

    while (low <= high) {
        if(x == mid_value) {
            return mid_value;
        }

        // you less 1 if the mid is larger 
        if(weight) {
            high = mid - 1;
        // you add 1 if the mid is smaller
        }else {
            low = mid + 1;
        }

        mid = (low+high)/2;
        mid_value = v[mid];
    }
    return -1;
}

int main() {
    int num[] = {10, 20, 30, 40, 23, 12};

    int n = sizeof(num) / sizeof(num[0]);
    printf("%d\n", binsearch(12, num, n));

    return 0;
}
