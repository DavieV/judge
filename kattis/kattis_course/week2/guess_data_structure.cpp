#include <iostream>
#include <stack>
#include <queue>

int main() {

    for (int n; std::cin >> n;) {
        std::stack<int> my_stack;
        std::queue<int> my_queue;
        std::priority_queue<int> my_pqueue;
        bool possible[3] = {true, true, true};

        for (int i = 0, cmd, x; i < n; ++i) {
            std::cin >> cmd >> x;

            if (cmd == 1) {
                my_stack.push(x);
                my_queue.push(x);
                my_pqueue.push(x);
            }

            else if (cmd == 2) {
                if (my_stack.empty() || my_stack.top() != x)
                    possible[0] = false;
                else
                    my_stack.pop();

                if (my_queue.empty() || my_queue.front() != x)
                    possible[1] = false;
                else
                    my_queue.pop();

                if (my_pqueue.empty() || my_pqueue.top() != x)
                    possible[2] = false;
                else
                    my_pqueue.pop();
            }
        }
        int sum = 0;
        int pos;
        for (int i = 0; i < 3; ++i) {
            if (possible[i]) {
                ++sum;
                pos = i;
            }
        }

        if (sum == 0) {
            std::cout << "impossible" << std::endl;
        } else if (sum > 1) {
            std::cout << "not sure" << std::endl;
        } else {
            if (pos == 0) std::cout << "stack" << std::endl;
            if (pos == 1) std::cout << "queue" << std::endl;
            if (pos == 2) std::cout << "priority queue" << std::endl;
        } 
    }

    return 0;
}
