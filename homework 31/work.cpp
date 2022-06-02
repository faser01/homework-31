#include <iostream>					
#include <stdlib.h>				
#include <time.h>					
#include <algorithm>				
#include <string>					




int random(int n, int m);
int word(std::string str);



int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;
	std::string str;

	//Задача 1
	try {
		std::cout << "Задача1\nВведите два числа: \n";
		std::cin >> n >> m;
		std::cout << "Случайное число из данного диапазона = " << random(n, m) << std::endl << std::endl;
	}
	catch (const std::invalid_argument& ex) {
		std::cout << "Ошибка!: " << ex.what() << std::endl << std::endl;
	}
	std::cin.ignore();

	//Задача 2
	try {
		std::cout << "Задача 2\nВведите слово и его длину через пробел: ";
		std::getline(std::cin, str);
		std::cout << "Вывод: " << word(str) << std::endl << std::endl;
	}
	catch (const std::runtime_error& ex) {
		std::cout << "Runtime error: " << ex.what() << std::endl << std::endl;
	}

	return 0;
}

int word(std::string str) {
	int count = 0;
	if (str == " ")
		throw std::runtime_error("Ошибка выполнения!");
	if (str[0] == 0)
		throw std::runtime_error("Ошибка выполнения!");
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			count++;
		if (count > 1)
			throw std::runtime_error("Ошибка выполнения!");
	}
	if (count < 1)
		throw std::runtime_error("Ошибка выполнения!");

	size_t first = str.find_first_of("0123456789");
	size_t last = str.find_last_of("0123456789");
																	
	std::string num = str.substr(first, (last - first) + 1);
	int str_size = str.find(" ");
	int newNum = stoi(num);
	if (newNum == str_size)
		return true;
	return false;
}

int random(int n, int m) {
	if (n == m)
		throw std::invalid_argument("Числа равны!");
	if (n > m)
		throw std::invalid_argument("Первое число больше второго!");
	return rand() % (m - n) + n;

}
