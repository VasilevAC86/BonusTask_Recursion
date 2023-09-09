# include <iostream>

int number; // Глобальная переменная для решения задач 1, 2, 3 и 5

bool prime_Number(int n); // Функция проверки чсила на признак простого
int mirrored_Number(int n); // Функция зеркалирования числа
void brackets(short n); // Процедура вывода кол-ва вложенных пар круглых скобок
int nums_Sum(int n); // Процедура расчёта суммы всех цифр числа
void progression(short f, short k, short n); // Процедура вывода n-первых чисел геометрической прогрессии

int main() {

	// Задача 1. Простое число
	std::cout << "\033[91mTask 1. Prime number\033[0m\n\n";	
	std::cout << "Enter the number -> ";
	std::cin >> number;
	if (number <= 1)
		std::cout << "\n\033[92mfalse\033[0m\n\n";
	else {
		std::cout.setf(std::ios_base::boolalpha);
		std::cout << "\n\033[92m" << prime_Number(number) << "\033[0m\n\n";
	}

	// Задача 2. Зеркалирование числа
	std::cout << "\033[91mTask 2. Mirroring a number\033[0m\n\nEnter a positive number -> ";
	number = 0;
	int num;
	std::cin >> num;
	if (num < 0)
		std::cout << "\n\033[92mThe entered number can only be mirrored modulo!\033[0m\n";
	std::cout << "\n\033[92mThe mirrored number is " << mirrored_Number(abs(num)) << "\033[0m\n\n";
	
	// Задача 3. Вывод n-ого кол-ва вложенных круглых скобок
	std::cout << "\n\033[91mTask 3. Round brackets\033[0m\n\nEnter the number of round brackets -> ";
	std::cin >> number;
	std::cout << "\n\033[92mResult of your choice is: \033[0m";
	brackets(number);
	std::cout << "\n\n";

	// Задача 4. Сумма всех цифр положительного числа
	std::cout << "\033[91mTask 4. Sum of all digits of a positive number\033[0m\n\nEnter a positive number -> ";
	int value;
	std::cin >> value;
	while (value < 0) 	{
		std::cout << "Input error! Enter a positive number -> ";
		std::cin >> value;
	}	
	std::cout << "\n\033[92mSum of all digits of an entered number is " << nums_Sum(value) << "\033[0m\n\n";

	// Задача 5. Вывод n-чисел возрастающей геометрической прогрессии
	std::cout << "\033[91mTask 5. Printing numbers of increasing geometric progression\033[0m\n\nEnter the index of the number in increasing geometric progression -> ";
	short n, f = 1, k = 3;
	std::cin >> n;
	std::cout << "\n\033[92mResult of your choice is: \033[0m";
	number = 0;
	progression(f, k, n);
	std::cout << "\b\b \n\n";

	return 0;
}

bool prime_Number(int n) {
	if (n > 1) {		
		if (number % n == 0 && n != number)
			return false;
		prime_Number(n - 1);
	}
	else
		return true;	
}

int mirrored_Number(int n) {	
	if (n > 0) {
		number = number * 10 + n % 10;
		mirrored_Number(n / 10);
	}
	return number;
	
}

void brackets(short n) {
	if (n > 0)
		std::cout << '(';
	else
		if (n > -number)
			std::cout << ")";
		else
			return;
	brackets(n - 1);	
}

int nums_Sum(int n) {
	if (n == 0)
		return 0;
	return nums_Sum(n / 10) + n % 10;	
}

void progression(short f, short k, short n) {
	if (n > 0) {
		std::cout << f * pow(k, number) << ", ";
		number++;
		progression(f, k, n - 1);
	}
}