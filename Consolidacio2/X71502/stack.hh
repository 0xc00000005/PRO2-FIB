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
    // Si k es cero o la pila 's' está vacía, no hay nada que mover
    if (k == 0 || s.ptopitem == nullptr) return;

    // Caso: mover todos los elementos si k >= número de elementos en 's'
    if (k >= s._size) {
        // Se busca el fondo de la pila 's' avanzando hasta que next == nullptr
        Item *p = s.ptopitem;
        while (p->next != nullptr) p = p->next;
        // Se enlaza el fondo de la pila 's' con la cima (top) de la pila actual
        p->next = ptopitem;
        // La cima de la pila actual pasa a ser la cima de 's'
        ptopitem = s.ptopitem;
        // Se incrementa el tamaño con el total de 's'
        _size += s._size;
        // Se vacía la pila 's'
        s.ptopitem = nullptr;
        s._size = 0;
        return;
    }

    // Caso: mover exactamente k elementos de 's'
    Item *oldTop = s.ptopitem;  // Referencia al nodo top de 's'
    Item *prev = nullptr;       // Apuntador auxiliar para encontrar el nuevo top
    Item *node = oldTop;        // Nodo explorado en el bucle

    // Avanzamos k veces para dejar 'node' en el (k+1)-ésimo elemento
    for (int i = 0; i < k && node != nullptr; i++) {
        prev = node;        // 'prev' se queda en el último nodo visitado
        node = node->next;  // 'node' avanza al siguiente
    }
    // En este punto, 'prev' apunta al k-ésimo nodo (último que se moverá)
    // 'node' pasa a ser el nuevo top de 's' (el elemento que queda en 's')

    // Se separa la sublista de k elementos en 's'
    prev->next = nullptr;
    // Ajuste de la pila 's' para que su tope sea 'node'
    s.ptopitem = node;

    // Ajustes de tamaño
    s._size -= k;
    _size += k;

    // Se adjunta la sublista [oldTop..prev] por encima de la pila actual
    Item *bottomSub = oldTop;
    // Se localiza el último nodo de la sublista que se movió
    while (bottomSub->next != nullptr) {
        bottomSub = bottomSub->next;
    }
    // Se enlaza con la cima de la pila actual
    bottomSub->next = ptopitem;
    // La sublista se convierte en la nueva cima
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
