#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "datasets.h"
#include "mergesort.h"
#include <fstream>
#include "userinterface.h"
#include "quicksort.h"

using namespace std;

//check that all information remains with the correct game
void checkGame(const Game& actual, const Game& expected) {
    REQUIRE(actual.id == expected.id);
    REQUIRE(actual.name == expected.name);
    REQUIRE(actual.genres == expected.genres);
    REQUIRE(actual.categories == expected.categories);
    REQUIRE(actual.platforms == expected.platforms);
    REQUIRE(actual.recommendations == expected.recommendations);
    REQUIRE(actual.score == expected.score);
}

//check our merge sort vs actual C++ sorting alg??

TEST_CASE("load all steam games", "[data]") {
    std::vector<Game> games = loadCSV(string(DATA_DIR) + "all_applications.csv");

    REQUIRE(!games.empty());

    Game& game = games.front();

    REQUIRE(game.id > -1);
    REQUIRE(!game.name.empty());
    REQUIRE(!game.genres.empty());
    REQUIRE(!game.categories.empty());
    REQUIRE(!game.platforms.empty());
    REQUIRE(game.recommendations > -1);
}

TEST_CASE("load all genres", "[data]") {
    std::vector<tgui::String> genres = getAllGenres();

    REQUIRE(!genres.empty());

    tgui::String& genre = genres.front();

    REQUIRE(!genre.empty());
}

TEST_CASE("load all categories", "[data]") {
    std::vector<tgui::String> categories = getAllCategories();

    REQUIRE(!categories.empty());

    tgui::String& category = categories.front();

    REQUIRE(!category.empty());
}


TEST_CASE("check recommendations", "[data]") {
    std::vector<Game> games = loadCSV(string(DATA_DIR) + "all_applications.csv");
    string category, genre, platform;
    vector<string> recommendedGames = loadMostSimilarGames(games, "", "", "");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "Action", "Family Sharing", "windows");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "Action", "", "");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "", "", "windows");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "Action", "", "windows");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "Action", "Family Sharing", "");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "", "Family Sharing", "");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());

    recommendedGames = loadMostSimilarGames(games, "", "Family Sharing", "windows");
    REQUIRE(!recommendedGames.empty());
    REQUIRE(!recommendedGames.front().empty());
}

vector<Game> getGames(){
    std::vector<Game> games = loadCSV(string(DATA_DIR) + "all_applications.csv");
    string category, genre, platform;

    for (Game& game : games) {
        double score = game.categories.find(category) == string::npos ? 0 : 15;
        score+=game.genres.find(genre) == string::npos ? 0 : 15;
        score+=game.platforms.find(platform) == string::npos ? 0 : 10;
        score+= ::log(game.recommendations);
        game.score = score;
    }
    return games;
}


TEST_CASE("test merge sort", "[sort]") {
    vector<Game> games = getGames();

    mergeSort(games);

    for (int i = 0; i < games.size()-1; i++) {
        REQUIRE((games[i].score > games[i+1].score) | (games[i].name <= games[i+1].name));
    }

}

TEST_CASE("test quick sort", "[sort]") {
    vector<Game> games = getGames();

    quickSort(games);

    for (int i = 0; i < games.size()-1; i++) {
        REQUIRE((games[i].score > games[i+1].score) | (games[i].name <= games[i+1].name));
    }

}


