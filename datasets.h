
#ifndef DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H
#define DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H

#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


struct game {
    int appID;
    string name;
    vector<string> genres;
    vector<string> catagories;
};

vector<vector<string>> loadCSV(const string& path);
map<string, string> loadRef(const string& lookup);
void addToGenres(const string& val, const string& k, vector<game>& game, const map<string, string>& ref, const unordered_map<int, int>& indexOf);
void addToCata(const string& val, const string& k, vector<game>& game, const map<string, string>& ref, const unordered_map<int, int>& indexOf);

void loadGameInfo(const string& lookup, vector<game>& g, const map<string, string>& ref, string type);
vector<game> loadGamelist(vector<vector<string>>& s);
bool isAscii(const string& s);
#endif //DREAM_STEAM_A_TEAM_DSA_PROJECT_2__DATASETS_H