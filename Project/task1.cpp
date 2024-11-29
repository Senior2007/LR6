#include "task1.h"

bool good1(char*s, int size) {
    for (int i = 0; i < size; i++) {
        if (s[i] != ' ' && !(s[i] >= '0' && s[i] <= '9')) return 0;
    }
    return 1;
}

std::vector<std::string> get_solution1(char* s, int size) {
    std::vector<std::string> ans;

    for (int i = 0; i < size; i++) {
        if (s[i] != ' ' && (s[i] - '0') % 2 == 0 && (i == size - 1 || s[i + 1] == ' ')) {
            int j = i;
            while(j > 0 && s[j] != ' ') j--;
            if (j == -1) {
                j++;
            }

            std::string cur = "";
            for (int k = j; k <= i; k++) cur += s[k];
            ans.push_back(cur);
        }
    }

    return ans;
}

void solve1() {
    std::cout << "Введите текст. Для окончания ввода введите *\n";

    while(1) {
        input1:
        int size = 0;
        char* s = nullptr;
        char ch;

        while (std::cin.get(ch) && ch != '\n' && ch != '*') {
            size++;
            char* s2 = new char[size];
            for (int i = 0; i < size - 1; i++) s2[i] = s[i];
            s2[size - 1] = ch;

            delete[] s;
            s = s2;
        }

        if (ch == '*') {
            delete[] s;
            break;
        }
        if (!good1(s, size)) {
            std:: cout << "\nВведенная Вами строка некорректна! Повторите ввод.\n\n";
            delete[] s;
            goto input1;
        }

        std::vector<std::string> ans = get_solution1(s, size);

        if (ans.size() == 0) {
            std::cout << "Четных чисел в строке нет\n\n";
        } else {
            std::cout << "Четные числа в строке : ";
            for (auto u : ans) std::cout << u << ' ';
            std::cout << "\n\n";
        }

        delete[] s;
    }
}