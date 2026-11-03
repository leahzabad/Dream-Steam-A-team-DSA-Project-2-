#include "datasets.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    auto s = loadCSV(string(DATA_DIR) + "applications.csv");
    if (s.empty()) return 1;

    cout << "Rows loaded: " << s.size() << "\n";
    vector<game> gameslist = loadGamelist(s);


    // First 10 rows, ID and name only
    // for (int i = 0; i < 10 && i < gameslist.size(); ++i) {
    //     cout << gameslist[i].appID << ", " << gameslist[i].name << "\n";
    // }

    map<string, string> ref_g = loadRef(string(DATA_DIR) + "genres.csv");
    auto path_g = string(DATA_DIR) + "application_genres.csv";
    loadGameInfo(path_g, gameslist, ref_g, "genres");

    map<string, string> ref_c = loadRef(string(DATA_DIR) + "categories.csv");
    auto path_c = string(DATA_DIR) + "application_categories.csv";
    loadGameInfo(path_c, gameslist, ref_c, "categories");

    for (int i = 0; i < 30 && i < gameslist.size(); ++i) {
        cout << gameslist[i].appID << ", " << gameslist[i].name << ", {";
        for (int j = 0; j < gameslist[i].genres.size(); j++) {
            cout << gameslist[i].genres[j] << ", ";
        }
        cout <<"}, {";

        for (int j = 0; j < gameslist[i].catagories.size(); j++) {
            cout << gameslist[i].catagories[j] << ", ";
        }
        cout <<"}";
        cout << "\n";
    }
    //final structure should be a game object = id, name, {all genres}, {all categories}

    return 0;
}