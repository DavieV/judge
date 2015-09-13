/*
Solved the rock paper scissors problem on Kattis.
Receives from the user the data for a rock paper scissors tournament, and
then outputs the win rate of each player. w / (w + l)
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <cstdio>

int winner(std::string, std::string);

void add_scores(
    std::unordered_map< int, std::pair<int, int> >&,
    int, std::string, int, std::string
);

int main() {
    int n, k;

    int p1, p2;
    std::string m1, m2;
    std::unordered_map< int, std::pair<int, int> > scores;

    while (std::cin >> n >> k) {
        // Read in the data for each round and add it to the scores map
        for (int i = 0; i < k * (n * (n - 1) / 2); ++i) {
            std::cin >> p1 >> m1 >> p2 >> m2;
            add_scores(scores, p1, m1, p2, m2);
        }

        // Iterate through the map and output the win avg of each player
        for (int i = 1; i <= n; ++i) {
            float wins = scores[i].first;
            float wins_or_losses = scores[i].second;

            if (wins_or_losses == 0)
                std::cout << '-' << std::endl;
            else
                printf("%.3f\n", wins / wins_or_losses);
        }
        std::cout << std::endl;

        scores.clear();  // Clear the map for the next test case
    }
    return 0;
}

/*
Determine a winner of a round of rock-paper-scissors.
1 -> player 1 wins
2 -> player 2 wins
0 -> tie
-1 -> erroneous input
*/
int winner(std::string m1, std::string m2) {
    if (m1 == m2) return 0;
    if (m1 == "rock") {
        if (m2 == "paper") return 2;
        if (m2 == "scissors") return 1;
        return -1;
    } else if (m1 == "paper") {
        if (m2 == "scissors") return 2;
        if (m2 == "rock") return 1;
        return -1;
    } else if (m1 == "scissors") {
        if (m2 == "rock") return 2;
        if (m2 == "paper") return 1;
        return -1;
    }
    return -1;
}

/*
Make changes to the scores map by reference, so as not to muddy up
the main program.
*/
void add_scores(
    std::unordered_map< int, std::pair<int, int> >& scores,
    int p1, std::string m1,
    int p2, std::string m2
) {
    auto p1_iter = scores.find(p1);
    auto p2_iter = scores.find(p2);

    if (winner(m1, m2) == 1) {
        if (p1_iter == scores.end()) {
            scores.insert({p1, {1, 1}});    // Start p1 with 1w 1l
        } else {
            ++p1_iter->second.first;        // Increment win counter
            ++p1_iter->second.second;       // Increment win/loss counter
        }
        if (p2_iter == scores.end())
            scores.insert({p2, {0, 1}});    // Start p2 with 0w 1l
        else
            ++p2_iter->second.second;       // Increment win/loss counter
    }

    else if (winner(m1, m2) == 2) {
        if (p2_iter == scores.end()) {
            scores.insert({p2, {1, 1}});    // Start p2 with 1w 1l
        } else {
            ++p2_iter->second.first;        // Increment win counter
            ++p2_iter->second.second;       // Increment win/loss counter
        }
        if (p1_iter == scores.end())
            scores.insert({p1, {0, 1}});    // Start p1 with 0w 1l
        else
            ++p1_iter->second.second;       // Increment win/loss counter
    }
}
