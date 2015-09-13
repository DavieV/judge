#include <iostream>

int get_len(std::string);
void fill_row(char**, int, int, std::string);
int parse_digit(char*);
int get_value(char**, int);

int main() {
    std::string line;
    std::getline(std::cin, line);
    int len = get_len(line);
    int pos = 0;

    char** nums = new char*[len];
    for (int i = 0; i < len; ++i)
        nums[i] = new char[15];

    fill_row(nums, pos, len, line);
    pos += 3;

    for (int i = 0; i < 4; ++i) {
        std::getline(std::cin, line);
        fill_row(nums, pos, len, line);
        pos += 3;
    }

    int val = get_value(nums, len);

    std::cout << val << std::endl;

    if (val < 0 || val % 6 != 0)
        std::cout << "BOOM!" << std::endl;
    else
        std::cout << "BEER!" << std::endl;

    delete[] nums;

    return 0;
}

int get_len(std::string line) {
    int c = 0;
    int len = 0;
    for (unsigned i = 0; i < line.length(); ++i) {
        if (c == 3) {
            c = 0;
            ++len;
        } else {
            ++c;
        }
    }
    return len + 1;
}

void fill_row(char** nums, int start, int len, std::string line) {
    int cur_num = 0;
    int pos = start;
    int c = 0;
    for (unsigned i = 0; i < line.length() && cur_num < len; ++i) {
        if (c == 3) {
            ++cur_num;
            pos = start;
            c = 0;
        } else {
            nums[cur_num][pos] = line[i];
            ++pos;
            ++c;
        }
    }
}

int parse_digit(char* digit) {
    int val = 0;
    for (int i = 0; i < 15; ++i) {
        val <<= 1;
        if (digit[i] == '*')
            val += 1;
    }

    switch (val) {
        case 31599:
            return 0;
        case 4681:
            return 1;
        case 29671:
            return 2;
        case 29647:
            return 3;
        case 23497:
            return 4;
        case 31183:
            return 5;
        case 31215:
            return 6;
        case 29257:
            return 7;
        case 31727:
            return 8;
        case 31695:
            return 9;
        default:
            return -1;
    }
}

int get_value(char** nums, int len) {
    int val = 0;
    int dig;
    for (int i = 0; i < len; ++i) {
        dig = parse_digit(nums[i]);
        if (dig < 0)  // error, invalid digit
            return -1;
        val = (val * 10) + parse_digit(nums[i]);
    }
    return val;
}
