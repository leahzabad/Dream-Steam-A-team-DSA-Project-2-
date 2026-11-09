#include <iostream>
#include <vector>
#include "datasets.h"

using namespace std;

void quickSort(vector<Game>& games, int low, int high)
{
    if (low >= high) return;

    int r = low + rand() % (high - low + 1);
    double pivot = games[r].score;

    int lt = low, i = low, gt = high;
    while (i <= gt) {
        if (games[i].score > pivot) {
            swap(games[lt++], games[i++]);
        } else if (games[i].score < pivot){
            swap(games[i], games[gt--]);
        }
        else {
            i++;
        }
    }

    quickSort(games, low, lt - 1);
    quickSort(games, gt + 1, high);
}
