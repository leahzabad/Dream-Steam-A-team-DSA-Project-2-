#include <cmath>

#include "datasets.h"
#include "mergesort.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    auto games = loadCSV(string(DATA_DIR) + "applications.csv");
    if (games.empty()) return 1;

    cout << "Rows loaded: " << games.size() << "\n";

    // Print every column name in the header row, with its index
    cout << "Columns:\n";
    /*for (size_t i = 0; i < s[0].size(); ++i) {
        cout << "  " << i << ": " << s[0][i] << "\n";
    }

    // First 10 rows, ID and name only
    for (size_t i = 0; i < 10 && i < s.size(); ++i) {
        if (s[i].size() >= 2) {
            cout << s[i][0] << ", " << s[i][1] << "\n";
        }
    }*/

    string category = "NOT_USED";
    string genre = "NOT_USED";
    string platform = "windows";

    for (Game& game : games) {
        double score = game.categories.find(category) == string::npos ? 0 : 15;
        score+=game.genres.find(genre) == string::npos ? 0 : 15;
        score+=game.platforms.find(platform) == string::npos ? 0 : 10;
        score+= ::log(game.recommendations);
        game.score = score;
    }
    mergeSort(games);
    for (Game &game : games) {
        cout << game.name << "\t" << game.score << "\n";
    }


    return 0;
}