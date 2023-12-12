#include <iostream>
//поиск максимума в массиве
int main() {
  int array_size, maximal;
  std::cin >> array_size;
  int* arr = new int[array_size];

  for (int i = 0; i < array_size; i++) {
    std::cin >> arr[i];
  }

  maximal = arr[0];
  for (int i = 1; i < array_size - 1; i++) {
    if (arr[i] > maximal) {
      maximal = arr[i];
    }
  }
  std::cout << maximal;
  delete[] arr;
}

//Сортировка выбором (selection sort)

//найти максимальный элемент и поместить его в начало

//swap - поменять местами элементы

#include <iostream>

int main() {
  int array_size;
  std::cin >> array_size;
  int* arr = new int[array_size];

  for (int i = 0; i < array_size; i++) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < array_size - 1; i++) {
    for (int j = i + 1; j < array_size; j++) { // внутренний - найти максимальный среди под массива
      if (arr[j] > arr[i]) {
        int t;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
  for (int i = 0; i < array_size; i++) {
    std::cout << arr[i];
  }
  delete[] arr;
}

//Сортировка вставками

//Реализация сдвига: 

int main() {
  int t, array_size, j;
  std::cin >> array_size;
  int* arr = new int[array_size];

  for (int i = 0; i < array_size; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < array_size - 1; i++) {
    j = i + 1;
    while ((j > 0) && (arr[j - 1] < arr[j])) {
      t = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = t;
      j = j - 1;
    }

  }

  for (int i = 0; i < array_size - 1; i++) {
    std::cout << arr[i];
  }
}


//Сортировка пузырьком

int main() {
  int t, array_size, j;
  std::cin >> array_size;
  int* arr = new int[array_size];

  for (int i = 0; i < array_size; i++) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < array_size - 1; i++) { // не идем по отсортированным элементам
    for (int j = i + 1; i < array_size - i - 1; i++) {
      if (arr[j] > arr[i]) {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;

      }
    }
  }
  for (int i = 0; i < array_size - 1; i++) {
    std::cout << arr[i];
  }
  delete[] arr;
}