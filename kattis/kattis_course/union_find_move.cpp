#include <iostream>
#include <vector>
#include <unordered_map>

struct union_find {
    std::vector<int> parent;
    std::unordered_map< int, std::vector<int> > connected;

    union_find(int n) : parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = -1;
    }

    // Return the root element of the set containing x
    int find(int x) {
        if (parent[x] < 0) {
            return x;
        } else {
            return find(parent[x]);
        }
    }

    // Join the set containing x with the set containing y
    void unite(int x, int y) {
        if (parent[x] < 0 && parent[y] < 0) {
            parent[x] += parent[y];
            parent[y] = x;

            // The root takes on the direct child y
            connected[x].push_back(y);

        } else {
            unite(find(x), find(y));
        }
    }

    // Move the element x to the set containing y
    void move(int x, int y) {
        if (connected.find(x) != connected.end()) {
            std::vector<int> children = connected[x];
            int new_parent = children[0];

            // Make a connection between x's replacement and x's parent
            // (If x was the root, we retain its negative root value)
            if (parent[x] < 0) {
                parent[new_parent] = parent[x] + 1;
            } else {
                parent[new_parent] = parent[x];
            }

            // Loop through all of the children of x, and connect them to
            // the replacement for x
            for (unsigned i = 1; i < children.size(); ++i) {
                parent[children[i]] = new_parent;
            }
        }
        int pos = find(y);
        parent[x] = pos;
        parent[pos] -= 1;
        connected[pos].push_back(x);
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
    sets.print();

    sets.move(3, 4);
    sets.print();

    sets.unite(3, 5);
    sets.print();

    std::cout << sets.size(4) << std::endl;

    sets.move(4, 1);
    sets.print();

    return 0;
}
