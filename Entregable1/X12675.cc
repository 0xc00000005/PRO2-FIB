#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @pre c contiene la sucesión de enteros que representan los números de items de los clientes que
 * quieren pasar por las cajas, y num_cajas es el número de cajas abiertas. Se supone que todos los
 * clientes tienen más de un item para pagar.
 *
 * @post se devuelve el mínimo tiempo necesario para que todos hayan pasado por caja.
 *
 */
int punto_verde(int num_emp, queue<int>& c){
	vector<int> tiempoEmpleado(num_emp, 0);
	while(!c.empty()){
		int producto = c.front();
		c.pop();
		// Empleado aquí es un iterador que apunta al empleado que menos tiempo lleva trabajando
		auto empleado = min_element(tiempoEmpleado.begin(), tiempoEmpleado.end());
		// Añade el tiempo que tarda en atender al cliente al empleado en concreto
		*empleado += producto;
	}
	// Retorna el valor máximo del tiempo de espera de un empleado.
	// Esto es pq supone que al ir cogiendo siempre el mínimo en "auto empleado"
	// seria el simil a un comprador escogiendo la caja con menos cola.
	// Cuando el empleado con más tiempo de espera atienda al último cliente, todos los demás
	// ya han terminado, y es por eso que se escoge en "*max_element"
	return *max_element(tiempoEmpleado.begin(), tiempoEmpleado.end());

}

template <typename T>
T read() {
	T n;
	cin >> n;
	return n;
}

template <typename T>
queue<T> read_queue() {
	int n = read<int>();
	queue<T> q;
	for (int i = 0; i < n; i++) {
		q.push(read<T>());
	}
	return q;
}

int main() {
	int num_cases = read<int>();
	for (int i = 0; i < num_cases; ++i) {
		int num_emp = read<int>();
		auto q = read_queue<int>();
		cout << punto_verde(num_emp, q) << endl;
	}
	return 0;
}
