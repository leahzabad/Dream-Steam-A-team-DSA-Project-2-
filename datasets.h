
#ifndef DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H
#define DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H

#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;


struct game {
    int appID;
    string name;
    vector<string> genres;
    vector<string> catagories;
};

vector<vector<string>> loadCSV(const string& path);
vector<game> loadGamelist(vector<vector<string>> s);

#endif //DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H