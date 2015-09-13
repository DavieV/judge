#include <iostream>

template <typename T>
struct Node{
	T datum_;
	Node* next_;
	Node* prev_;
	Node(T d) : datum_(d), next_(nullptr), prev_(nullptr) {};
};

template <typename T>
struct singly{
	Node<T>* head_;
	Node<T>* tail_;
	singly() : head_(nullptr), tail_(nullptr) {};
	~singly(){
		Node<T>* tmp = head_;
		Node<T>* tmp2 = nullptr;
		while(tmp != nullptr){
			tmp2 = tmp->next_;
			delete tmp;
			tmp = tmp2;
		}
		delete tmp;
		delete tmp2;
	}

	void append(T d){
		Node<T>* n = new Node<T>(d);
		if(head_ == nullptr){
			head_ = n;
			tail_ = n;
			return;
		}
		tail_->next_ = n;
		tail_ = n;
	}

	void dump(){
		Node<T>* tmp = head_;
		while(tmp != nullptr){
			std::cout << tmp->datum_ << " ";
			tmp = tmp->next_;
		}
		std::cout << std::endl;
	}

	void reverse(){
		Node<T>* tmp = head_;
		std::swap(head_, tail_);
		Node<T>* next = nullptr;
		Node<T>* prev = nullptr;
		while(tmp != nullptr){
			next = tmp->next_;
			tmp->next_ = prev;
			prev = tmp;
			tmp = next;
		}
	}
};

template <typename T>
struct doubly{
	Node<T>* head_;
	Node<T>* tail_;
	doubly() : head_(nullptr), tail_(nullptr) {};
	~doubly(){
		Node<T>* tmp = head_;
		Node<T>* tmp2 = nullptr;
		while(tmp != nullptr){
			tmp2 = tmp->next_;
			delete tmp;
			tmp = tmp2;
		}
		delete tmp;
		delete tmp2;
	}

	void append(T d){
		Node<T>* n = new Node<T>(d);
		if(head_ == nullptr){
			head_ = n;
			tail_ = n;
			return;
		}
		tail_->next_ = n;
		n->prev_ = tail_;
		tail_ = n;
	}

	void dump(){
		std::cout << "Forward: ";
		Node<T>* tmp = head_;
		while(tmp != nullptr){
			std::cout << tmp->datum_ << " ";
			tmp = tmp->next_;
		}
		std::cout << std::endl; 
		std::cout << "Backward: ";
		tmp = tail_;
		while(tmp != nullptr){
			std::cout << tmp->datum_ << " ";
			tmp = tmp->prev_;
		}
		std::cout << std::endl;
	}

	void reverse(){
		Node<T>* tmp = head_;
		std::swap(head_, tail_);
		while(tmp != nullptr){
            std::swap(tmp->prev_, tmp->next_);
            tmp = tmp->prev_;
		}
	}
};

int main(){
	singly<int> s;
	s.append(54);
	s.append(199);
	s.append(-1);
	s.dump();
	s.reverse();
	s.dump();

	doubly<int> d;
	d.append(99);
	d.append(104);
	d.append(93);
	d.append(-981);
	d.dump();
	d.reverse();
	d.dump();
	return 0;
}
