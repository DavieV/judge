#include <iostream>

template <typename T>
struct stack{
	struct Node{
		Node* next_;
		T datum_;
		Node(T d) : next_(nullptr), datum_(d) {};
	};
	Node* head_;
	stack() : head_(nullptr) {};
	~stack(){
		while(!empty())
			pop();
		delete head_;
	}
	void push(T d){
		Node* n = new Node(d);
		if(head_ == nullptr){
			head_ = n;
			return;
		}
		n->next_ = head_;
		head_ = n;
	}
	T pop(){
		Node* old_head = head_;
		head_ = head_->next_;
		T tmp = old_head->datum_;
		delete old_head;
		return tmp;
	}
	bool empty(){
		return head_ == nullptr;
	}
};

int main(){
	stack<int> s;
	for(int i = 0; i < 10; i++)
		s.push(i);
	while(!s.empty())
		std::cout << s.pop() << std::endl;
	return 0;
}