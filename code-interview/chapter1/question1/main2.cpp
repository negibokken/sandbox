#include <iostream>
#include <map>
#include <string>

#include <time.h>
using namespace std;

void quickSort(int arr[], int left, int right);
void showArr(int arr[]);
int partition(int arr[], int left, int right);
void swap(int arr[], int left, int right);
bool HasDuplicatedChar(string str);

int size = 7;

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "./" << argv[0] << " <string>" << endl;
    exit(1);
  }
  srand(time(NULL));
  int a[] = {rand() % 100, rand() % 100, rand() % 100, rand() % 100,
             rand() % 100, rand() % 100, rand() % 100};
  size = 7;
  // int a[] = {5, 4, 1};
  showArr(a);
  quickSort(a, 0, size - 1);
  showArr(a);
  cout << endl;
  return 0;
}

void showArr(int arr[]) {
  for (int i = 0; i < size - 1; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}

void quickSort(int arr[], int p, int r) {
  if (p < r) {
    int q = partition(arr, p, r);
    quickSort(arr, p, q - 1);
    quickSort(arr, q + 1, r);
  }
}

int partition(int arr[], int p, int r) {
  int pivot = arr[p];
  int i = p;
  for (int j = p + 1; j <= r; j++) {
    if (arr[j] < pivot) {
      swap(arr, i, j);
      i++;
    }
  }
  cout << "i: " << i << endl;
  return i;
}

void swap(int arr[], int left, int right) {
  int temp = arr[left];
  arr[left] = arr[right];
  arr[right] = temp;
}
