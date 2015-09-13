#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct union_find {
    std::vector<int> parent;

    union_find(int n) : parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = -1;
    }

    // Takes in the index of an item, and returns the root index of the
    // set that that item belongs to
    int find(int x) {
        if (parent[x] < 0) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    // Takes in the indexes of two items, and places all of the items
    // in the set that y belongs to into the set that x belongs to
    void unite(int x, int y) {
        if (parent[x] < 0 && parent[y] < 0) {
            parent[x] += parent[y];
            parent[y] = x;
        } else {
            unite(find(x), find(y));
        }
    }

    // Outputs the size of the set that the element at index x belongs to
    int size(int x) {
        if (parent[x] < 0) {
            return -parent[x];
        } else {
            return size(find(x));
        }
    }

    void print() {
        for (int p : parent)
            std::cout << p << " ";
        std::cout << std::endl;
    }

    void clear() {
        for (unsigned i = 0; i < parent.size(); ++i)
            parent[i] = -1;
    }
};

int main() {
    int t;
    std::cin >> t;

    std::unordered_map<std::string, int> friends;   // map name to id

    union_find networks(100000);
    std::string friend1;
    std::string friend2;

    for (int i = 0; i < t; ++i) {
        int f;

        std::cin >> f;

        int count = 0;  // Count the number of unique names we have seen

        for (int j = 0; j < f; ++j) {
            std::cin >> friend1 >> friend2;

            auto p = friends.insert({friend1, count});
            if (p.second)
                ++count;

            p = friends.insert({friend2, count});
            if (p.second)
                ++count;

            // Place the two friends into the same set
            networks.unite(friends[friend1], friends[friend2]);

            // Output the size of the network
            std::cout << networks.size(friends[friend1]) << std::endl;
        }

        friends.clear();
        networks.clear();
    }

    return 0;
}
