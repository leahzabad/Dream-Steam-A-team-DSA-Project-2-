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
    for (int i = 0; i < 10 && i < gameslist.size(); ++i) {
        cout << gameslist[i].appID << ", " << gameslist[i].name << "\n";
    }

    return 0;
}