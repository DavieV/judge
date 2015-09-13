#include <iostream>

template <typename T>
class Queue{
	class Node{
		public:
			Node* next_;
			T datum_;
			Node(T v) : next_(nullptr), datum_(v) {};
	};
	private:
		Node* head_;
		Node* tail_;
	public:
		Queue() : head_(nullptr), tail_(nullptr) {};
		~Queue(){
			while(!empty())
				dequeue();
		}
	
		void enqueue(T v){
			Node* n = new Node(v);
			if(head_ == nullptr){
				head_ = n;
				tail_ = n;
				return;
			}
			tail_->next_ = n;
			tail_ = n;
		}

		T peek(){
			return head_->datum_;
		}

		void dequeue(){
			Node* tmp = head_;
			head_ = head_->next_;
			delete tmp;
		}

		bool empty(){
			return head_ == nullptr;
		}
};

int main(){
	Queue<int> q;
	q.enqueue(15);
	q.enqueue(18);
	q.enqueue(27);
	while(!q.empty()){
		std::cout << q.peek() << std::endl;
		q.dequeue();
	}
	return 0;
}