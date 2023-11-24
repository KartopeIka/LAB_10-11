// LAB_10-11_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>//���������� ����������� �������
#include <stdio.h>
#include <math.h>
#include <regex>

double askForNumber() {//����� ��� ��������� ������ "c" �� "x" �� ����������� �� �������� ����������� ����� 
    double number;//������ �����
    std::string input;//������ �����
    std::cin >> input;//std::cin ������ ��� �� ����������� �� ��������� ��������� ����� >>
    std::regex doubleFormat{ "-?[0-9]+[\\,,\\.][0-9]+" };//������ ���������� ����� ��� ������� ����� � ��������� �������
    std::regex intFormat{ "-?[0-9]+" };//������ ���������� ����� ��� ������� ����� ����� �����
    if (std::regex_match(input, doubleFormat)) {//���� ����� ������ �� ���������� ����� ��� ������� ����� � ��������� �������
        size_t dotPosition = input.find(",");//������ ��������� ���� � �����
        if (dotPosition != std::string::npos) {//���� ���� �������� (�� ��������� �� ������� ������������� ���������), �� �������� ��������
            input = input.replace(dotPosition, 1, ".");//������� ���� �� ������
        }
        number = std::stod(input);//���������� ����� � ������ float
    }
    else {
        if (std::regex_match(input, intFormat)) {// ���� ����� ������ �� ���������� ����� ��� ������� ����� ����� �����
            number = std::stod(input);
        }
        else {//������ - ����� ������� �� ��������
            std::cout << "Please, make a valid input using 0-9 digits and dot (.).\n";//�������� ����������� � ��������� ��������������� �������� �������
            number = askForNumber();//���������� ��������� �����
        }
    }
    return number;//��������� ����� "number"
}

int main()
{
    double S, c, x;//������ ����
    std::cout << "Enter c\n";//�������� ����������� � ��������� ������ �������� ��� ����� �
    c = askForNumber();//��������� ����� "askForNumber" ��� ��������� �������� ����� �
    std::cout << "Enter x\n";
    x = askForNumber();
    S = (log((c * exp(-2.5 * c + x) + pow(atan(fabs(c - x)), 2)) / (fabs(pow(-1, -2.5 * c) + sqrt(fabs(log(fabs(x)) + log10(fabs(c)))))))) / (log(c));
    //������� ��� ���������� ����������
    printf("At c = % .2f and x = % .2f rezult of S = %lf \n ", c, x, S);//�������� ���������, ����� "% .2f" �������� ����� ���� � ����� ������� ���� ����
    return 0;
}

