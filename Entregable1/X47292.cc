#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int>& inicial, stack<int>& ordenado);

void leer(stack<int>& p) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int elem;
		cin >> elem;
		p.push(elem);
	}
}

void escribir(stack<int> p) {
	cout << "<";
	// el paso por valor copia p correctamente ya que la clase tiene
	// creadora copiadora
	bool first = true;
	while (not p.empty()) {
		if (not first) {
			cout << " ";
		}
		cout << p.top();
		p.pop();  // el que no haya salto de linea entre elementos
		first = false;
	}  // solo interesa si la pila no es muy grande
	cout << ">";
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		stack<int> inicial, ordenado;
		leer(inicial);
		escribir(inicial);
		sort_stack(inicial, ordenado);
		escribir(ordenado);
		escribir(inicial);
		cout << endl;
	}

	return 0;
}
