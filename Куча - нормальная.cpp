void Swap(int& x, int& y) { // Свапает элементы

  int tmp = x;

  x = y;

  y = tmp;

}

void ShiftUp(int arr[], int index) { // Поднимает элемент в куче

  int index_parent;

  while (index > 0) {

    index_parent = (index - 1) / 2;

    if (arr[index] > arr[index_parent]) {

      Swap(arr[index], arr[index_parent]);

      index = index_parent;

    } else {

      break;

    }

  }

}

void ShiftDown(int arr[], int index, int n) { // Опускает элемент в куче

  int index_child_1;

  int index_child_2;

  int index_max;

  while (index < n) {

    index_child_1 = (index * 2) + 1;

    index_child_2 = (index * 2) + 2;

    index_max = index;

    if (index_child_1 < n && arr[index_child_1] > arr[index_max]) {

      index_max = index_child_1;

    }

    if (index_child_2 < n && arr[index_child_2] > arr[index_max]) {

      index_max = index_child_2;

    }

    if (index != index_max) {

      Swap(arr[index], arr[index_max]);

      index = index_max;

    } else {

      break;

    }

  }

}

void ExtractMax(int arr[], int n) { // Ложит макс элемент вниз кучи

  Swap(arr[0], arr[n - 1]);

  n--;

  ShiftDown(arr, 0, n);

}

void HeapSort(int arr[], int n) { // Из кучи делает отсортированный массив;

  int k = n;

  for (int i = 0; i < n; ++i) {

    ExtractMax(arr, k);

    k--;

  }

}

// ВАЖНО!!! - Resize и Push без capacity + работают только с динамическим массивом и заданным в переменную число n

void Resize(int*& arr, int n) { // Увеличивать массив кучи

  int* new_arr = new int[n + 1];

  for (int i = 0; i < n; ++i) {

    new_arr[i] = arr[i];

  }

  delete[] arr;

  arr = new_arr;

}

void Push(int*& arr, int& n, int element) { // Добавляет элемент в кучу

  Resize(arr, n);

  arr[n] = element;

  ShiftUp(arr, n);

  n += 1;

}