#include <iostream>
#include <map>

bool is_sock(std::string);

int main(){
	std::map<std::string, int> clothes;
	std::string s;
	while(getline(std::cin, s)){
		if(clothes.find(s) == clothes.end())
			clothes[s] = 0;
		clothes[s]++;
	}
	for(auto i : clothes){
		if(is_sock(i.first)){
			int socks = i.second;
			std::cout << i.first << "|" << socks / 2 << std::endl;
			
		}
	}
	return 0;
}

bool is_sock(std::string s){
	return s.find("sock") != std::string::npos;
}