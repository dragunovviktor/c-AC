#include <iostream>
// вычитание Алгоритм Евклида
int main() {
	int a, b;
	std::cin >> a >> b;
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a - b;

		}
		else {
			b = b - a;
		}
	}
	if (a == 0) {
		std::cout << b;
	}
	else {
		std::cout << a;
	}
	return 0;
}

//Второй алгоритм - по остатку от деления

int main() {
	int a, b;
	std::cin >> a >> b;
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	if (a == 0) {
		std::cout << b;
	} else {
		std::cout << a;
	}
	return 0;
}

//НОК

#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b;
	c = a * b;
	while (a != 0 && b != 0) {
		if (b > a) {
			b = b % a;
		}
		else {
			a = a % b;
		}
	}
	if (a != 0) {
		std::cout << c / a;
	}
	else {
		std::cout << c / b;
	}
	return 0;
}

// разложение на множители

int main() {
	int devidor, N;
	devidor = 2;
	std::cin >> N;
	while (N != 1) {
		if (N % devidor == 0) {
			std::cout << devidor;
			N = N / devidor;
		} else {
			devidor++;
		}
	}
	return 0;
}

//поиск

#include <iostream>

int main() {
	int array_size, elem, id;
	id = 0;
	std::cin >> array_size;

	int* array = new int[array_size];
	for (int i; i < array_size; i++) {
		std::cin >> array[i];
	}
	std::cin >> elem;
	while (id < array_size - 1) {
		if (array[id] == elem) {
			std::cout << "Element was found!";
			break;
		}
		else {
			id++;
		}
	}
	if (id == array_size - 1) {
		std::cout << "Nihuya Net";
	}
	delete[] array;
	return 0;
}

//бинарный поиск

int main() {
	int array_size, left = 0, right, middle, elem;
	bool flag;
	std::cin >> array_size;
	right = array_size - 1;
	flag = false;
	
	int* array = new int[array_size];
	for (int i; i < array_size; i++) {
		std::cin >> array[i];
	}
	std::cin >> elem;
	//пока границы не схлопнутся
	while (left <= right - 1) {
		middle = (left + right) / 2;
		if (array[middle] > elem) {
			right = array[middle];
		} else if (array[middle] < elem) {
			left = array[middle];
		} else {
			flag = true;
			break;
		}
	}
	
	if (flag == true || array[left] == elem || array[right] == elem) {
		std::cout << "Nashel";
	} else {
		std::cout << "Ne nashel";
	}
	return 0;
}
	
//Решето Эратосфена - найти все простые числа <= N
//1 простое, 0 составное

int main() {
	int array_size, N, k;
	std::cin >> array_size;
	int* arr = new int[array_size];

	for (int i = 0; i < array_size; i++) {
		std::cin >> arr[i];
	}

	for (int i = 2; i < array_size; i++) {
		if (arr[i] == 0) {
			k = 2;
			while (k * i <= array_size) {
				arr[k * i] = 1;
				k++;
			}
		}
	}

	for (int i = 2; i < array_size; ++i) {
		if (arr[i] == 0) {
			std::cout << i;
		}
	}
	delete[] arr;
	return 0;
}




