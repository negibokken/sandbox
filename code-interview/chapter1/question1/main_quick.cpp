#include <iostream>
#include <map>
#include <string>
using namespace std;

bool HasDuplicatedChar(char *str);
void quickSort(char *str, int p, int r);
int partition(char str[], int p, int r);
void swap(char str[], int i, int j);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "./" << argv[0] << " <string>" << endl;
    exit(1);
  }
  bool result = HasDuplicatedChar(argv[1]);
  cout << "result: " << result << endl;
  ;
  return 0;
}

void quickSort(char *str, int p, int r) {
  if (p < r) {
    int q = partition(str, p, r);
    quickSort(str, p, q - 1);
    quickSort(str, q + 1, r);
  }
}

int partition(char *str, int p, int r) {
  char pivot = str[p];
  int i = p;
  for (int j = p + 1; j <= r; j++) {
    if (str[j] < pivot) {
      cout << str[j] << pivot << endl;
      swap(str, i, j);
      i++;
    }
  }
  return i;
}

void swap(char str[], int i, int j) {
  char c = str[i];
  str[i] = str[j];
  str[j] = c;
}

int strLength(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++)
    ;
  return i;
}

bool HasDuplicatedChar(char *str) {
  int len = strLength(str);
  quickSort(str, 0, len - 1);
  // Check Neighbor
  for (int i = 0; i < len - 1; i++) {
    if (str[i] == str[i + 1]) {
      return true;
    }
  }
  return false;
}

