#include <iostream>
#include <map>
#include <string>
using namespace std;
bool HasDuplicatedChar(string str);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "./" << argv[0] << " <string>" << endl;
    exit(1);
  }
  bool result = HasDuplicatedChar(argv[1]);
  return result;
}

bool HasDuplicatedChar(string str) {
  for (int i = 0; i < str.length(); i++) {
    for (int j = i + 1; j < str.length(); j++) {
      if (str[i] == str[j]) {
        return true;
      }
    }
  }
  return false;
}
