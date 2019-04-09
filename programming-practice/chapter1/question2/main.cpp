#include<iostream>
#include<map>
using namespace std;

void sweep(map<char, int> &m, char *str1, char *str2);
bool check(map<char, int> m);

int main(int argc, char **argv) {
  map<char, int> m;
  if(argc != 3) {
    cout << argv[0] << " <str1> <str2>" << endl;
    return 1;
  }
  sweep(m, argv[1], argv[2]);
  bool result = check(m);
  cout << "result: " << result << endl;
  return 0;
}

bool check(map<char, int> m) {
  for (auto i = m.begin(); i != m.end(); i++) {
    if (i->second != 0) {
      return false;
    }
  }
  return true;
}

void sweep(map<char, int> &m, char *str1, char *str2) {
  for (int i = 0; str1[i] != '\0'; i++) {
    m[str1[i]]++;
  }
  for (int i = 0; str2[i] != '\0'; i++) {
    m[str2[i]]--;
  }
}
