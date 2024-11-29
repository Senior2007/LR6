#ifndef PROJECT_TASK3_H
#define PROJECT_TASK3_H
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
bool good3(std::string);
bool is_utf8_lead_byte(unsigned char);
size_t utf8_strlen(const char*);
bool is_palin(const char*);
void solve3();
#endif
