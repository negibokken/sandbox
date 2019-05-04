#include <iostream>
#include <list>
#include <random>
using namespace std;

enum AnimalType { Cat, Dog };

typedef struct Animal {
  AnimalType type;
  int no;
} Animal;

class AnimalQueue {
  private:
  list<Animal> l;

  public:
  void enqueue(Animal a) { l.push_back(a); }
  Animal dequeAny()
  {
    Animal a = l.front();
    l.erase(l.begin());
    return a;
  }
  Animal* dequeDog()
  {
    Animal* a = NULL;
    list<Animal>::iterator i = l.begin();
    for (; i != l.end(); ++i) {
      if (i->type == Dog) {
        a = &*i;
        l.erase(i);
        break;
      }
    }
    return a;
  }
  Animal* dequeCat()
  {
    Animal* a = NULL;
    list<Animal>::iterator i = l.begin();
    for (; i != l.end(); ++i) {
      if (i->type == Cat) {
        a = &*i;
        l.erase(i);
        break;
      }
    }
    return a;
  }
  void show()
  {
    for (auto i = l.begin(); i != l.end(); ++i) {
      cout << i->no << ": " << (i->type == Dog ? "Dog" : "Cat") << endl;
    }
  }
};

int main(void)
{
  AnimalQueue q;
  random_device rnd;
  for (int i = 0; i < 10; ++i) {
    Animal a;
    a.type = rnd() % 2 == 0 ? Dog : Cat;
    a.no = i;
    q.enqueue(a);
  }
  cout << "All animals" << endl;
  q.show();

  cout << "All dogs" << endl;
  while (1) {
    Animal* a = q.dequeDog();
    if (a == NULL) {
      break;
    }
    cout << a->no << ": " << (a->type == Dog ? "Dog" : "Cat") << endl;
  }

  cout << "All cats" << endl;
  while (1) {
    Animal* a = q.dequeCat();
    if (a == NULL) {
      break;
    }
    cout << a->no << ": " << (a->type == Dog ? "Dog" : "Cat") << endl;
  }
  cout << "==";
  q.show();
  return 0;
}
