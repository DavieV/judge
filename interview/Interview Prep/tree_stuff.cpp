#include <iostream>
#include <cassert>
#include <queue>

template <typename T>
struct Node{
	Node* right_;
	Node* left_;
	T datum_;
	Node(T d) : datum_(d), right_(nullptr), left_(nullptr) {};
};

template <typename T>
struct search_tree{
	Node<T>* root_;
	search_tree() : root_(nullptr) {};
	~search_tree(){
		kill_tree(root_);
	}
	void kill_tree(Node<T>* root){
		if(root == nullptr)
			return;
		kill_tree(root->left_);
		kill_tree(root->right_);
		delete root;
	}

	void insert(T d){
		Node<T>* n = new Node<T>(d);
		if(root_ == nullptr){
			root_  = n;
			return;
		}
		insert(n, root_);
	}

	void insert(Node<T>* n, Node<T>* root){
		if(n->datum_ < root->datum_){
			if(root->left_ == nullptr){
				root->left_ = n;
				return;
			}
			insert(n, root->left_);
		}
		else{
			if(root->right_ == nullptr){
				root->right_ = n;
				return;
			}
			insert(n, root->right_);
		}
	}

	bool is_search_tree(){
		return is_search_tree(root_);
	}

	int height(Node<T>* root){
		if(root == nullptr)
			return -1;
		return 1 + std::max(height(root->left_), height(root->right_));
	}

	bool is_search_tree(Node<T>* root){
		if(root == nullptr) return true;
		if(root->right_ != nullptr && root->datum_ > root->right_->datum_) return false;
		if(root->left_ != nullptr && root->datum_ < root->left_->datum_) return false;
		return true && is_search_tree(root->right_) && is_search_tree(root->left_);
	}

	void print_spaces(int n){
		for(int i = 0; i < n; i++)
			std::cout << "\t";
	}

	void bfs(){
		std::queue<Node<T>*> q;
		q.push(root_);
		int next_row = 0, current_row = 1;
		while(!q.empty()){
			auto top = q.front();
			q.pop();
			if(top->left_ != nullptr){
				next_row++;
				q.push(top->left_);
			}
			if(top->right_ != nullptr){
				next_row++;
				q.push(top->right_);
			}
			current_row--;
			std::cout << top->datum_ << " ";
			if(current_row == 0){
				std::cout << std::endl;
				current_row = next_row;
				next_row = 0;
			}
		}
	}
};

template <typename T>
struct not_search_tree{
	Node<T>* root_;
	bool go_left = true;
	not_search_tree() : root_(nullptr) {};
	~not_search_tree(){
		kill_tree(root_);
	}
	
	void kill_tree(Node<T>* root){
		if(root == nullptr)
			return;
		kill_tree(root->left_);
		kill_tree(root->right_);
		delete root;
	}

	void insert(T d){
		Node<T>* n = new Node<T>(d);
		if(root_ == nullptr){
			root_ = n;
			return;
		}
		insert(n, root_);
	}

	void insert(Node<T>* n, Node<T>* root){
		go_left = !go_left;
		if(go_left){
			if(root->left_ == nullptr){
				root->left_ = n;
				return;
			}
			insert(n, root->left_);
		}
		else{
			if(root->right_ == nullptr){
				root->right_ = n;
				return;
			}
			insert(n, root->right_);
		}
	}

	bool is_search_tree(){
		return is_search_tree(root_);
	}

	bool is_search_tree(Node<T>* root){
		if(root == nullptr) return true;
		if(root->right_ != nullptr && root->datum_ > root->right_->datum_) return false;
		if(root->left_ != nullptr && root->datum_ < root->left_->datum_) return false;
		return true && is_search_tree(root->right_) && is_search_tree(root->left_);
	}
};

int main(){
	search_tree<int> t;
	t.insert(9);
	t.insert(10);
	t.insert(-1);
	t.insert(4);
	t.insert(200);
	t.insert(-10);
	t.insert(12);
	assert(t.is_search_tree());
	t.pretty_print();

	not_search_tree<int> t2;
	t2.insert(9);
	t2.insert(10);
	t2.insert(-1);
	t2.insert(4);
	t2.insert(3);
	assert(!t2.is_search_tree());

	return 0;
}
