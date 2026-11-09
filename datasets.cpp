// need to be able to parse through kaggle datafiles to get all games
//then ask for steam ID to get their games
// then compare genres

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "datasets.h"
#include <cmath>
#include "mergesort.h"
#include "quicksort.h"
#include <chrono>

using namespace  std;

vector<Game> loadCSV(const string& path) {
    vector<Game> data;
    ifstream fin(path);
    if (!fin) { cerr << "Could not open " << path << "\n"; return data; }

    vector<string> row;
    string cell;
    bool inQuotes = false;
    char c;

    while (fin.get(c)) {
        if (inQuotes) {
            if (c == '"') {
                if (fin.peek() == '"') { cell += '"'; fin.get(); }
                else inQuotes = false;
            } else cell += c;
        }
        else if (c == '"') {
            inQuotes = true;
        }
        else if (c == ',') {
            row.push_back(cell);
            cell.clear();
        }
        else if (c == '\n') {
            if (!(row.empty() && cell.empty()) && row[0] != "appid") {
                row.push_back(cell);

                Game game{stoi(row[0]),
                    row[1],
                    row[2],
                    row[3],
                    row[4],
                    stoi(row[5])};

                data.push_back(game);
            }
            row.clear();
            cell.clear();
        }
        else if (c != '\r') {
            cell += c;
        }
    }
    if (!row.empty() || !cell.empty()) {
        row.push_back(cell);
        Game game{};
        data.push_back(game);
    }
    return data;
}

std::vector<std::string> loadMostSimilarGames(std::vector<Game> games, string genre, string category, string platform, bool useQuickSort, double* sortMs) {
    for (Game& game : games) {
        double score = game.categories.find(category) == string::npos ? 0 : 15;
        score+=game.genres.find(genre) == string::npos ? 0 : 15;
        score+=game.platforms.find(platform) == string::npos ? 0 : 10;
        score+= ::log(game.recommendations);
        game.score = score;
    }

    auto start = chrono::steady_clock::now();
    if (useQuickSort) {
        quickSort(games, 0, (int)games.size() - 1);
    } else {
        mergeSort(games);
    }
    auto end = std::chrono::steady_clock::now();
    if (sortMs) *sortMs = std::chrono::duration<double, std::milli>(end - start).count();


    //mergeSort(games);
    //quickSort(games,0, games.size() - 1);
    std::vector<std::string> mostSimilarGames;
    for (int i = 0; i < 20; i++) {
        mostSimilarGames.push_back(games[i].name);
    }
    return mostSimilarGames;
};

