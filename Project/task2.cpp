#include "task2.h"

bool good2(char*s, int size) {
    for (int i = 0; i < size; i++) {
        if (s[i] != '\n' && s[i] != '.' && s[i] != ' ' && s[i] != '!' && s[i] != '?' && s[i] != '\'' && s[i] != ',' && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) return 0;
    }
    return 1;
}

std::tuple<std::vector<int>, std::vector<int>, int, int> get_solution2(char* s, int size) {
    int maxx = -1e9, minn = 1e9;
    std::vector<int> idx1, idx2;

    int cur = 0;
    for (int i = 0; i < size; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            cur++;
        } else if (cur != 0){
            if (cur == maxx) {
                idx1.push_back(i - cur);
            }

            if (cur == minn) {
                idx2.push_back(i - cur);
            }

            if (cur > maxx) {
                maxx = cur;
                idx1.clear();
                idx1.push_back(i - cur);
            }

            if (cur < minn) {
                minn = cur;
                idx2.clear();
                idx2.push_back(i - cur);
            }

            cur = 0;
        }
    }

    if (cur != 0) {
        if (cur == maxx) {
            idx1.push_back(size - cur);
        }

        if (cur == minn) {
            idx2.push_back(size - cur);
        }

        if (cur > maxx) {
            maxx = cur;
            idx1.clear();
            idx1.push_back(size - cur);
        }

        if (cur < minn) {
            minn = cur;
            idx2.clear();
            idx2.push_back(size - cur);
        }
    }

    return {idx2, idx1, minn, maxx};
}

void solve2() {
    std::cout << "Введите текст. В конце введите *\n";

    input2:
    int size = 0;
    char* s = nullptr;
    char ch;

    while (std::cin.get(ch)) {
        if (ch == '*') {
            break;
        }

        size++;
        char *s2 = new char[size];
        for (int i = 0; i < size - 1; i++) s2[i] = s[i];
        s2[size - 1] = ch;

        delete[] s;
        s = s2;
    }

    if (!good2(s, size)) {
        std::cout << "Введенный Вами текст содержит не только слова! Повторите ввод.\n\n";
        delete[] s;
        goto input2;
    }

    std::vector<int> min_idx, max_idx;
    int min_len, max_len;
    tie(min_idx, max_idx, min_len, max_len) = get_solution2(s, size);

    std::cout << "Слова минимальной длины :\n";
    for (auto u : min_idx) {
        for (int j = u; j < u + min_len; j++) std::cout << s[j];
        std::cout << '\n';
    }

    std::cout << "\nСлова максимальной длины :\n";
    for (auto u : max_idx) {
        for (int j = u; j < u + max_len; j++) std::cout << s[j];
        std::cout << '\n';
    }

    std::cout << '\n';
    delete[] s;
}
