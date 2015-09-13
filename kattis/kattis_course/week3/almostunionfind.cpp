#include <iostream>
#include <vector>
#include <unordered_map>

struct union_find {
    std::vector<int> parent;
    std::vector<int> sums;
    std::unordered_map< int, std::vector<int> > connected;

    union_find(int n) : parent(n), sums(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = -1;
            sums[i] = i;
        }
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

            // Add the sum of the elements of the y set to the x set
            sums[x] += sums[y];

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
            sums[new_parent] = sums[x] - x;
            for (unsigned i = 1; i < children.size(); ++i) {
                parent[children[i]] = new_parent;
            }
        }

        int pos = find(y);
        parent[x] = pos;
        parent[pos] -= 1;
        sums[pos] += x;
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

    // Output the sum of the elements in the set that x belongs to
    int sum(int x) {
        if (parent[x] < 0) {
            return sums[x];
        } else {
            return sum(find(x));
        }
    }

    void print() {
        for (int p : parent)
            std::cout << p << " ";
        std::cout << std::endl;
    }
};

int main() {
    int n;  // represents the size of the set
    int m;  // represents the number of commands to be used

    std::cin >> n >> m;

    union_find sets(n); // create a union_find class of size n

    int cmd;    // integer that represents the set operation to use
    int p, q;   // inputs to the operation on the union_find structure
    int size;
    int sum;

    for (int i = 0; i < m; ++i) {
        std::cin >> cmd;
        
        switch (cmd) {
            case 1:
                std::cin >> p >> q;
                sets.unite(p - 1, q - 1);
                break;
            case 2:
                std::cin >> p >> q;
                sets.move(p - 1, q - 1);
                break;
            case 3:
                std::cin >> p;
                size = sets.size(p - 1);
                sum = sets.sum(p - 1) + size;
                std::cout << size << " " << sum << std::endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
