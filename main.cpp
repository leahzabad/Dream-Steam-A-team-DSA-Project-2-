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

    // Print every column name in the header row, with its index
    cout << "Columns:\n";
    for (size_t i = 0; i < s[0].size(); ++i) {
        cout << "  " << i << ": " << s[0][i] << "\n";
    }

    // First 10 rows, ID and name only
    for (size_t i = 0; i < 10 && i < s.size(); ++i) {
        if (s[i].size() >= 2) {
            cout << s[i][0] << ", " << s[i][1] << "\n";
        }
    }

    return 0;
}