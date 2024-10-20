#include <stdio.h>

void swap(int v[], int i, int j);
void qSort(int v[], int left, int right);

// get a pivot value do partition and sort it
void qSort(int v[], int left, int right) {
    int i, last;
    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }

    /*
       [12, 10, 14, 20, 8]
       left = 0, right = 4
       mid = 2 (14)

       swap it
       do last = left;

       [14, 12, 10, 20, 8] last = 0
       [14, 12, 10, 20, 8]
       [14, 10, 12, 20, 8]
       [14, 10, 12, 20, 8]
       [14, 10, 12, 8, 20]
       [8, 10, 12, 14, 20]

       [8, (go from here)10, 12, 14, 20(to here)]
    */

    swap(v, left, last);
    qSort(v, left, last-1);
    qSort(v, last+1, right);
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main() {
    int arr[] = {21, 3, 4, 24};
    qSort(arr, 0, 3);

    for(int i = 0; i < 4; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
