#include <iostream>
#include <stack>

int main(){
	std::stack<int> s1;
	std::stack<int> s2;

	s1.push(80);
	s1.push(-19);
	s1.push(90);

	int in_order = 0;
	int max = 0;
	int done = s1.size();
	while(!s1.empty()){
		int tmp = s1.top();
		s1.pop();
		while(!s2.empty() && s2.top() > tmp){
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(tmp);
	}
	while(!s2.empty()){
		std::cout << s2.top() << std::endl;
		s2.pop();
	}
	return 0;
}