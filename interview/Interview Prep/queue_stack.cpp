#include <iostream>
#include <stack>

template<typename T>
class queue_stack{ // implement a queue using 2 stacks
	std::stack<T> s1;
	std::stack<T> s2;

	public:
	queue_stack() {};

	void push(T v){ // for the lazy
		enqueue(v);
	}
	void enqueue(T v){
		s1.push(v);
	}

	T dequeue(){
		if(s2.empty()){ // basically s2 is the inverse of entered items on the stack, making it a queue
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		T v = s2.top();
		s2.pop();
		return v;
	}

	bool empty(){
		return s1.empty() && s2.empty();
	}
};

int main(){
	queue_stack<int> q;
	q.push(7);
	q.push(92);
	q.dequeue();
	q.push(-1);

	while(!q.empty())
		std::cout << q.dequeue() << std::endl;
	return 0;
}