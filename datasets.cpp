


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
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

bool isAscii(const string& s) {
    for (unsigned char ch : s)
        if (ch > 127) return false;
    return true;
}

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

map<string, string> loadRef(const string& lookup) {
    map<string, string> ref;
    ifstream fin(lookup);
    if (!fin) { cerr << "Could not open " << lookup << "\n"; return ref; }

    string key;
    string second;
    char c;
    int count = 0;

    while (fin.get(c)) {
        if (c == ',') {
            count++;
        }
        else if (c == '\n') {
            if (!(second.empty() && key.empty()) && isAscii(second)) {
               ref.insert({key, second});
            }
            second.clear();
            key.clear();
            count = 0;
        }
        else if (c != '\r') {
            if (count == 0){
                key += c;
            } else if (count == 1) {
                second += c;
            }
        }
    }
    if (!second.empty() || !key.empty()) {
        ref.insert({key, second});
    }
    return ref;
}

void addToGenres(const string& val, const string& k, vector<game>& game, const map<string, string>& ref, const unordered_map<int, int>& indexOf) {

    auto g = indexOf.find(stoi(k));
    auto r = ref.find(val);
    if (g != indexOf.end() && r != ref.end())
        game[g->second].genres.push_back(r->second);

}

void addToCata(const string& val, const string& k, vector<game>& game, const map<string, string>& ref, const unordered_map<int, int>& indexOf) {

    auto g = indexOf.find(stoi(k));
    auto r = ref.find(val);
    if (g != indexOf.end() && r != ref.end())
        game[g->second].catagories.push_back(r->second);

}

void loadGameInfo(const string& lookup, vector<game>& g, const map<string, string>& ref, string type) {
    ifstream fin(lookup);
    if (!fin) { cerr << "Could not open " << lookup << "\n"; return; }

    unordered_map<int, int> indexOf;
    for (int i = 0; i < g.size(); ++i) {
        indexOf[g[i].appID] = i;
    }

    string key;
    string second;
    char c;
    int count = 0;
    bool header = true;

    while (fin.get(c)) {
        if (c == ',') {
            count++;
        }
        else if (c == '\n') {
            if (header) {
                header = false;
            } else if (!(key.empty())) {
               if (type == "genres"){
                   addToGenres(second, key, g, ref, indexOf);
               } else if (type == "categories") {
                   addToCata(second, key, g, ref, indexOf);
               }
            }
            second.clear();
            key.clear();
            count = 0;
        }
        else if (c != '\r') {
            if (count == 0){
                key += c;
            } else if (count == 1) {
                second += c;
            }
        }
    }
    if (!second.empty() || !key.empty()) {
        addToGenres(second, key, g, ref, indexOf);
    }
}


vector<game> loadGamelist(vector<vector<string>>& s) {
    vector<game> gameslist;
    for (int i = 1; i < s.size(); i++) {
        game g;
        g.appID = stoi(s[i][0]);
        g.name = s[i][1];
        gameslist.push_back(g);
    }
    return gameslist;
}
