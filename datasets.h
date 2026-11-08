
#ifndef DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H
#define DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H

#pragma once
#include <string>
#include <vector>
using namespace std;

// struct Game {
// int id;
// string name;
// vector<string> genres;
// vector<string> categories;
// double score;
// int recommendations;
// };
struct Game {
    int id;
    string name;
    string genres;
    string categories;
    string platforms;
    int recommendations;
    double score;
};

vector<Game> loadCSV(const string& path);
std::vector<std::string> loadMostSimilarGames(std::vector<Game> allGames, string genre, string category, string platform);

#endif //DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H