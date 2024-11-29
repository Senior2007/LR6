#include "task1.h"
#include "task2.h"
#include "task3.h"

int main() {
    std::string type;

    while(1) {
        std::cout << "Если хотите запустить первую задачу - введите 1\n";
        std::cout << "Если хотите запустить вторую задачу - введите 2\n";
        std::cout << "Если хотите запустить третью задачу - введите 3\n";
        std::cout << "При любом другом вводе программа завершится\n\n";

        std::getline(std::cin, type);

        if (type != "1" && type != "2" && type != "3") {
            break;
        }

        if (type == "1") {
            solve1();
            std::getline(std::cin, type);
        } else if (type == "2") {
            solve2();
            std::getline(std::cin, type);
        } else {
            solve3();
        }
    }

    return 0;
}