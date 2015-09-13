#include <iostream>
#include <string>
#include <string.h>

std::string reverse(std::string);
int strcmp(std::string, std::string);
int strcmp(char*, char*);
std::string longest_run(std::string);
void run_offsets(std::string);
char sorted_repeat(std::string);
void reverse(char *);
void percent_20(char*);
void compress_occurances(char*);
//std::string compress_underscores(std::string s);
void compress_underscores(char*);

int main(){
	std::cout << reverse("Hello world") << std::endl;
	std::cout << strcmp("Hello", "Hellow") << std::endl;
	std::cout << longest_run("aabbccdd") << std::endl;
	run_offsets("0010011");
	std::cout << sorted_repeat("aabbbcccdddeeefffgggghhhjjjiiklllmmnnopqrstuvxz") << std::endl;

	char s1[100] = "aabbacccbbb";
	compress_occurances(s1);
	//reverse(s1);
	//percent_20(s1);
	std::cout << s1 << std::endl;
	
    char s2[100] = "__hello___world__";
    compress_underscores(s2);
    return 0;
}

void compress_underscores(char* s){
    char *tmp = s;
    while(tmp){
        if(*tmp == '_' && *(tmp + 1) == '_'){
            tmp++;
            char* look = tmp;
            while(*look == '_') look++;
            while(*look != '_')
                *tmp++ = *look++;
        }
        tmp++;
    }
    std::cout << s << std::endl;
}

/*std::string compress_underscores(std::string s){
    std::string ans = "";
    ans += s[0];
    for(int i = 1; i < s.size(); i++){
        while(s[i] == '_' && ans.back() == '_') i++;
        ans += s[i];
    }
    return ans;
}*/
void compress_occurances(char* s){
	char cur = s[0];
	int count = 1, len = strlen(s), cur_index = 0;
	for(int i = 1; i < len; i++){
		while(s[i] == cur){
			count++;
			i++;
		}
		s[cur_index] = cur;
		cur = s[i];
		s[cur_index + 1] = count + '0';
		cur_index += 2;
		count = 1;
	}
	s[cur_index] = cur;
	s[cur_index + 1] = count + '0';
	s[cur_index + 2] = '\0';
}

void percent_20(char* s){
	while(*s){
		if(*s == ' '){
			memmove(s + 3, s + 1, strlen(s + 1));
			*s = '%';
			*(s + 1) = '2';
			*(s + 2) = '0';
		}
		s++;
	}
}

void reverse(char* start){
	char* end = start;
	while(*end) end++;
	end--;
	while(start < end){
		std::swap(*start, *end);
		start++;
		end--;
	}
}

int strcmp(char* s1, char* s2){
	while(*s1 && *s2 && *s1 == *s2){
		s1++; s2++;
	}
	return *s1 - *s2;
}

char sorted_repeat(std::string s){
	char c = s[0], max = s[0];
	int cur_count = 1, max_count = 1;
	for(int i = 1; i < s.size(); i++){
		while(s[i] == c && i < s.size()){
			i++;
			cur_count++;
		}
		if(cur_count > max_count){
			max_count = cur_count;
			max = c;
		}
		c = s[i];
		cur_count = 1;
	}
	return max;
}

void run_offsets(std::string s){
	char last = s[0];
	for(int i = 1; i < s.size(); i++){
		if(last == s[i]) std::cout << i - 1 << ", ";
		while(s[i] == last && i < s.size()) i++;
		last = s[i];
	}
	std::cout << std::endl;
}

std::string longest_run(std::string s){
	std::string cur = "";
	cur += s[0];
	std::string max = cur;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == cur.back()) cur += s[i];
		else cur = s[i];
		if(cur.size() > max.size()) max = cur;
	}
	return max;
}

int strcmp(std::string s1, std::string s2){
	int i = 0;
	while(i < s1.size() && i < s2.size() && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}

std::string reverse(std::string s){
	for(int i = 0; i < s.size() / 2; i++)
		std::swap(s[i], s[s.size() - i - 1]);
	return s;
}
