#include "task3.h"

bool good3(std::string s) {
    if (s.size() > 10 || s.size() == 0) return 0;
    if (s[0] == '0') return 0;
    for (int i = 0; i < s.size(); i++) if (!(s[i] >= '0' && s[i] <= '9')) return 0;
    return 1;
}

bool is_utf8_lead_byte(unsigned char byte) {
    return (byte & 0xC0) != 0x80;
}

size_t utf8_strlen(const char* s) {
    size_t length = 0;
    for (size_t i = 0; s[i] != '\0'; ++i) {
        if (is_utf8_lead_byte(s[i])) {
            ++length;
        }
    }
    return length;
}

bool is_palin(const char* s) {
    size_t len = strlen(s);
    size_t char_len = utf8_strlen(s);

    const char *start = s;
    const char *end = s + len;

    for (size_t i = 0; i < char_len / 2; ++i) {
        const char *next_start = start;
        while (!is_utf8_lead_byte(*++next_start));

        const char *prev_end = end;
        while (!is_utf8_lead_byte(*--prev_end));

        if (strncmp(start, prev_end, next_start - start) != 0) {
            return false;
        }

        start = next_start;
        end = prev_end;
    }

    return true;
}

void solve3() {
    std::string sn;
    input3:
    std::getline(std::cin, sn);

    if (!good3(sn)) {
        std::cout << "Некорректный ввод! Введите заново.\n\n";
        goto input3;
    }

    int n = std::stoi(sn);
    char** arr = new char*[n];
    std::vector<int> len;

    for (int i = 0; i < n; i++) {
        char str[300];
        std::cin.getline(str, 300);
        int size = strlen(str);
        len.push_back(size);

        arr[i] = new char[size + 1];
        strcpy(arr[i], str);
    }

    for (int i = 0; i < n; i++) {
        if (is_palin(arr[i])) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    for (int i = 0; i < n; i++) {
        delete arr[i];
        arr[i] = nullptr;
    }

    delete[] arr;
    arr = nullptr;
}