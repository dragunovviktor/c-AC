#include <iostream>

int Partition(int array[], int left, int right) {
  int pivot = array[left];
  int L = left;
  int R = right;
  while (L < R) {
    while (array[L] < pivot) {
      L++;
    }
    while (array[R] >= pivot) {
      R--;
    }
    if (L < R) {
      int t = array[L];
      array[L] = array[R];
      array[R] = t;
    }
  }
  return L;
}

void Qsort(int array[], int left, int right) {
  if (right <= left) {
    return;
  }
  int P = Partition(array, left, right);
  Qsort(array, left, P-1);
  Qsort(array, P+1, right);
}

int main() {
  int n;
  std::cin >> n;
  int* array = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
  Qsort(array, 0, n);
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << " ";
  }
  delete[] array;
  return 0;
}
