// need to be able to parse through kaggle dataset to get all games
//then ask for steam ID to get their games
// then compare genres

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace  std;

struct game {
    int appID;
    string name;
    vector<string> genres;
    vector<string> catagories;

    game() {
        appID = 0;
        name = "NULL";
        genres = {};
        catagories = {};
    }
};


vector<vector<string>> loadCSV(const string& path) {
    vector<vector<string>> data;
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
            if (!(row.empty() && cell.empty())) {
                row.push_back(cell);
                data.push_back(row);
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
        data.push_back(row);
    }
    return data;
}

vector<game> loadGamelist(vector<vector<string>> s) {
    vector<game> gameslist;
    for (int i = 1; i < s.size(); i++) {
        game g;
        g.appID = stoi(s[i][0]);
        g.name = s[i][1];
        gameslist.push_back(g);
    }
    return gameslist;
}