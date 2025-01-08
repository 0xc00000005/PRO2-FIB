#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
private:

  // Items:
  
  struct Item {
    T value;
    Item* next;
  };

  // Data:
  
  int _size;
  Item* ptopitem;

  // Helpers:
  
  Item* copyItems(Item *pitem) {
    if (pitem == NULL) return NULL;
    Item *pfirstitem = new Item();
    Item *pcurrentitem = pfirstitem;
    while (pitem != NULL) {
      pcurrentitem->value = pitem->value;
      if (pitem->next != NULL) pcurrentitem->next = new Item();
      else pcurrentitem->next = NULL;
      pcurrentitem = pcurrentitem->next;
      pitem = pitem->next;
    }
    return pfirstitem;
  }
  
  void deleteItems()
  {
    Item *pitem = ptopitem;
    while (pitem != NULL) {
      Item *pitemaux = pitem;
      pitem = pitem->next;
      delete pitemaux;
    }
    _size = 0;
  }
  
  void printRec(ostream &os, const Item *pitem) const
  {
    if (pitem == NULL) return;
    printRec(os, pitem->next);
    if (pitem->next != NULL) os << " ";
    os << pitem->value;
  }
  
public:

  // Constructors/destructors.
  Stack() {
    ptopitem = NULL;
    _size = 0;
  }
  
  Stack(const Stack<T> &s) {
    ptopitem = copyItems(s.ptopitem);
    _size = s._size;
  }
  
  ~Stack() {
    deleteItems();
  }

  // Assignment:
  
  Stack<T> &operator=(const Stack<T> &s) {
    if (this != &s) {
      deleteItems();
      ptopitem = copyItems(s.ptopitem);
      _size = s._size;
    }
    return *this;
  }

  // Standard functions:
  
  int size() {
    return _size;
  }

  bool empty() const {
    return ptopitem == NULL;
  }

  void push(T value) {
    Item *pnewitem = new Item();
    pnewitem->value = value;
    pnewitem->next = ptopitem;
    ptopitem = pnewitem;
    _size++;
  }
  
  void pop() {
    if (ptopitem == NULL) {
      cerr << "Error: pop on empty stack" << endl;
      exit(1);
    }
    Item *paux = ptopitem;
    ptopitem = ptopitem->next;
    delete paux;
    _size--;
  }
    
  T top() {
    if (ptopitem == NULL) {
      cerr << "Error: accessing top of empty stack" << endl;
      exit(1);
    }
    return ptopitem->value;
  }
    
  const T top() const {
    if (ptopitem == NULL) {
      cerr << "Error: accessing top of empty stack" << endl;
      exit(1);
    }
    return ptopitem->value;
  }

  // Read and write:
  
  template <typename U> friend ostream &operator<<(ostream &os, const Stack<U> &s);
  template<typename U> friend istream &operator>>(istream &is, Stack<U> &s);
    
  // Pre:  Sigui [a1,...,an] el contingut del paràmetre implícit (des del fons fins al cim).
  //       Sigui [b1,...,bm] el contingut de s.
  //       k>=0.
  // Post: En el cas en que k>=m, aquest és el resultat:
  //          [a1,...,an,b1,...,bm] és el contingut del paràmetre implícit.
  //          [] és el contingut de s.
  //       En canvi, en el cas k<m, aquest és el resultat:
  //          [a1,...,an,b{m-k+1},...,bm] és el contingut del paràmetre implícit.
  //          [b1,...,b{m-k}] és el contingut de s.
  // Descomenteu les següents dues linies i implementeu el mètode:
  void take(Stack<T> &s, int k) {
    if (k == 0 || s.ptopitem == nullptr) return;

    // Case: move all
    if (k >= s._size) {
        // Find bottom of s
        Item *p = s.ptopitem;
        while (p->next != nullptr) p = p->next;
        // Link bottom of s to top of this
        p->next = ptopitem;
        ptopitem = s.ptopitem;
        _size += s._size;
        s.ptopitem = nullptr;
        s._size = 0;
        return;
    }

    // Case: move exactly k elements
    Item *oldTop = s.ptopitem;
    Item *prev = nullptr;
    Item *node = oldTop;
    for (int i = 0; i < k && node != nullptr; i++) {
        prev = node;
        node = node->next;
    }
    // 'prev' is now the last of the k moved items
    // 'node' is the new top of s
    prev->next = nullptr;
    s.ptopitem = node;

    s._size -= k;
    _size += k;

    // Attach sublist [oldTop..prev] on top of this
    Item *bottomSub = oldTop;
    // Find the bottom of that sublist
    // but here, bottomSub is the top of the sublist
    while (bottomSub->next != nullptr) {
        bottomSub = bottomSub->next;
    }
    bottomSub->next = ptopitem;
    ptopitem = oldTop;
  }
  void Stack<T>::take(Stack<T> &s, int k) {
  if (k == 0 || s.ptopitem == nullptr) return;

  // Case: move all
  if (k >= s._size) {
      // Find bottom of s
      Item *p = s.ptopitem;
      while (p->next != nullptr) p = p->next;
      // Link bottom of s to top of this
      p->next = ptopitem;
      ptopitem = s.ptopitem;
      _size += s._size;
      s.ptopitem = nullptr;
      s._size = 0;
      return;
  }

  // Case: move exactly k elements
  Item *oldTop = s.ptopitem;
  Item *prev = nullptr;
  Item *node = oldTop;
  for (int i = 0; i < k && node != nullptr; i++) {
      prev = node;
      node = node->next;
  }
  // 'prev' is now the last of the k moved items
  // 'node' is the new top of s
  prev->next = nullptr;
  s.ptopitem = node;

  s._size -= k;
  _size += k;

  // Attach sublist [oldTop..prev] on top of this
  Item *bottomSub = oldTop;
  // Find the bottom of that sublist
  // but here, bottomSub is the top of the sublist
  while (bottomSub->next != nullptr) {
      bottomSub = bottomSub->next;
  }
  bottomSub->next = ptopitem;
  ptopitem = oldTop;
  }
  
};

// Implementation of read and write:

template <typename U> ostream &operator<<(ostream &os, const Stack<U> &s)
{
  //os << s._size;
  //if (s.ptopitem != NULL) os << " ";
  s.printRec(os, s.ptopitem);
  return os;
}

template <typename U> istream &operator>>(istream &is, Stack<U> &s)
{
  int n;
  is >> n;
  s = Stack<U> ();
  for (int i = 0; i < n; i++) {
    U u;
    is >> u;
    s.push(u);
  }
  return is;
}
