#include <iostream>
#include <vector>

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
};

int main() {
    union_find sets(10);

    sets.unite(1, 2);
    sets.unite(1, 3);

    sets.unite(5, 6);
    sets.unite(6, 7);

    sets.unite(1, 5);

    sets.print();

    return 0;
}
