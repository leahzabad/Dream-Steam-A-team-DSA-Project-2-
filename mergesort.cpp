#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> lv(n1), rv(n2);

    for (i = 0; i < n1; i++)
        lv[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rv[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (lv[i] <= rv[j]) {
            vec[k] = lv[i];
            i++;
        } else {
            vec[k] = rv[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = lv[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rv[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}
