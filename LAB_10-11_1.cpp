// LAB_10-11_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>//підключення стандартних бібліотек
#include <stdio.h>
#include <math.h>
#include <regex>

double askForNumber() {//метод для отримання змінних "c" та "x" від користувача та перевірки правильності вводу 
    double number;//задаємо змінну
    std::string input;//задаємо стрінг
    std::cin >> input;//std::cin отримує дані від користувача за допомогою оператора вводу >>
    std::regex doubleFormat{ "-?[0-9]+[\\,,\\.][0-9]+" };//задаємо регулярний вираз для формату вводу з плаваючою крапкою
    std::regex intFormat{ "-?[0-9]+" };//задаємо регулярний вираз для формату вводу цілих чисел
    if (std::regex_match(input, doubleFormat)) {//якщо рядок підпадає під регулярний вираз для формату вводу з плаваючою крапкою
        size_t dotPosition = input.find(",");//шукаємо положення коми в рядку
        if (dotPosition != std::string::npos) {//якщо кома знайдена (її положення не дорівнює максимальному можливому), то виконуємо наступне
            input = input.replace(dotPosition, 1, ".");//замінити кому на крапку
        }
        number = std::stod(input);//конвертуємо стрінг у формат float
    }
    else {
        if (std::regex_match(input, intFormat)) {// якщо рядок підпадає під регулярний вираз для формату вводу цілих чисел
            number = std::stod(input);
        }
        else {//інакше - рядок введено не коректно
            std::cout << "Please, make a valid input using 0-9 digits and dot (.).\n";//виводимо повідомлення з проханням використовувати правильні символи
            number = askForNumber();//рекурсивно викликаємо метод
        }
    }
    return number;//повертаємо змінну "number"
}

int main()
{
    double S, c, x;//задаємо змінні
    std::cout << "Enter c\n";//виводимо повідомлення з проханням ввести значення для змінної с
    c = askForNumber();//викликаємо метод "askForNumber" для отримання значення змінної с
    std::cout << "Enter x\n";
    x = askForNumber();
    S = (log((c * exp(-2.5 * c + x) + pow(atan(fabs(c - x)), 2)) / (fabs(pow(-1, -2.5 * c) + sqrt(fabs(log(fabs(x)) + log10(fabs(c)))))))) / (log(c));
    //формула для обчислення результату
    printf("At c = % .2f and x = % .2f rezult of S = %lf \n ", c, x, S);//виводимо результат, запис "% .2f" виводить число лише з двома знаками після коми
    return 0;
}

