#include <iostream>
#include <string.h>

void* memcpy(void*, void*, size_t);
void* memmove(void*, void*, size_t);

int main(){
	char source[] = "Hello world";
	char dest[100];
	memcpy(dest, source, strlen(source) + 1);
	std::cout << dest << std::endl;
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	std::cout << str << std::endl;
	return 0;
}

void* memmove(void* dest, void* src, size_t bytes){ // do worry about overlap
	char* src_ = (char*)src;
	char* dest_ = (char*)dest;
	if(src < dest){
		src_ = src_ + bytes - 1;
		dest_ = dest_ + bytes - 1;
		for(int i = 0; i < bytes; i++)
			*(dest_ - i) = *(src_ - i);
	}
	else{
		for(int i = 0; i < bytes; i++)
			*(dest_ + i) = *(src_ + i);
	}
	return dest;
}

void* memcpy(void* dest, void* src, size_t bytes){
	char* src_ = (char*)src;
	char* dest_ = (char*)dest;
	for(size_t i = 0; i < bytes; i++) // dont worry about overlap and just copy away;
		*(dest_ + i) = *(src_ + i);
	return dest;
}
