// need to be able to parse through kaggle dataset to get all games
//then ask for steam ID to get their games
// then compare genres

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace  std;

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

