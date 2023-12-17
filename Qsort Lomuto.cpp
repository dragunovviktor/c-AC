int PartitionLomuto(int arr[], int left, int right) {
  int pivot = arr[right];
  int i = left;
  int tmp;
  for (int j = left; j <= right - 1; j++) {
    if (arr[j] <= pivot) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i += 1;
    }
  }

  tmp = arr[i];
  arr[i] = arr[right];
  arr[right] = tmp;
  return i;
}

void QuickSort(int arr[], int left, int right) {
  if (right <= left) {
    return;
  }
  int p;
  p = PartitionLomuto(arr, left, right);
  QuickSort(arr, left, p - 1);
  QuickSort(arr, p + 1, right);

}