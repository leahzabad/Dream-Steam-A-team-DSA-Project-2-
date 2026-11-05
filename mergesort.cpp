#include <iostream>
#include <vector>
#include <datasets.h>

using namespace std;


void merge(vector<Game>& games, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Game> lv(n1), rv(n2);

    for (int i = 0; i < n1; i++)
        lv[i] = games[left + i];
    for (int j = 0; j < n2; j++)
        rv[j] = games[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (lv[i].score > rv[j].score) {
            games[k] = lv[i];
            i++;
        } else if (lv[i].score < rv[j].score) {
            games[k] = rv[j];
            j++;
        } else {
            if (lv[i].name <= rv[j].name) {
                games[k] = lv[i];
                i++;
            }
            else {
                games[k] = rv[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        games[k] = lv[i];
        i++;
        k++;
    }

    while (j < n2) {
        games[k] = rv[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Game>& games, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(games, left, mid);
        mergeSort(games, mid + 1, right);
        merge(games, left, mid, right);
    }
}

void mergeSort(vector<Game>& games) {
    mergeSort(games, 0, games.size() - 1);
}
