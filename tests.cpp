#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// TEMPORARY STUFF <<<
struct Game {
    string name;
    int id;
    string genre;
    double score;
};

vector<Game> loadAllSteamGames() {
    vector<Game> games;
    Game game1{"game1"};
    Game game2{"game2"};
    Game game3{"game3"};
    games.push_back(game1);
    return games;
}

vector<Game> loadUsersGames() {
    vector<Game> games;
    Game game1{"game1"};
    games.push_back(game1);
    return games;
}

vector<Game> getRecommendations() {
    vector<Game> games;
    Game game2{"game2"};
    games.push_back(game2);
    return games;
}

vector<Game> quickSort(vector<Game> games) {
     return games;
 }

vector<Game> mergeSort(vector<Game> games) {
    return games;
}
// >>> TEMPORARY STUFF

TEST_CASE("load all steam games", "[data]") {
    vector<Game> games = loadAllSteamGames();

    REQUIRE(!games.empty());
}

TEST_CASE("check recommendations", "[data]") {
    vector<Game> usersGames = loadUsersGames();
    vector<Game> recommendedGames = getRecommendations();
    vector<Game> intersection;

    auto byName = [](const Game& a, const Game& b) {
        return a.name < b.name;
    };

    std::sort(usersGames.begin(), usersGames.end(), byName);
    std::sort(recommendedGames.begin(), recommendedGames.end(), byName);

    std::set_intersection(
            usersGames.begin(), usersGames.end(),
            recommendedGames.begin(), recommendedGames.end(),
            std::back_inserter(intersection),
            byName
        );

    REQUIRE(intersection.empty());
}

TEST_CASE("test sorting", "[data]") {
    vector<Game> usersGames = loadUsersGames();

}