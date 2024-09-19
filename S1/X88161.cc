#include <iostream>     // Incluye la biblioteca estándar para la entrada y salida
#include <vector>       // Incluye el soporte para la estructura de datos vector
#include <algorithm>    // Incluye funciones de algoritmo como sort
using namespace std;    // Permite usar identificadores del espacio de nombres estándar sin prefijo (como std::vector)

typedef vector<pair<int,int> > Fila;   // Define "Fila" como un vector de pares de enteros, cada par representa un partido (goles locales y goles visitantes)
typedef vector<Fila> Matriz;           // Define "Matriz" como un vector de filas, representando los resultados de varios equipos

// Estructura que representa a un equipo con su identificador, puntos, goles a favor (gf) y goles en contra (gc)
struct equipo {
	int id, pts = 0, gf = 0, gc = 0;    // Inicializa puntos, goles a favor y goles en contra en 0
};

// Función para leer los resultados de los partidos y almacenarlos en una matriz
void leer_matriz(Matriz& v) {
	int tam = v.size();    // Obtiene el tamaño de la matriz (cantidad de equipos)
	for (int i = 0; i < tam; ++i) {     // Recorre cada fila (partidos jugados por el equipo i)
		for (int j = 0; j < tam; ++j) { // Recorre cada columna (resultados de equipo i contra equipo j)
			cin >> v[i][j].first;       // Lee los goles del equipo i en el partido contra el equipo j
			cin >> v[i][j].second;      // Lee los goles del equipo j en el partido contra el equipo i
		}
	}
}

// Función para clasificar a los equipos según los resultados de los partidos
vector<equipo> clasificar(const Matriz& v) {
	int equipos = v.size();              // Cantidad de equipos
	vector<equipo> clas(equipos);        // Vector que almacenará la información de cada equipo, se establece el tamaño a "equipos"
	
	// Asigna un identificador único a cada equipo (del 1 al número total de equipos)
	for (int i = 0; i < equipos; ++i) clas[i].id = i + 1;
	
	// Sección para contabilizar los puntos y goles de los equipos jugando "en casa"
	for (int i = 0; i < equipos; ++i) {        // Recorre cada equipo i
		for (int j = 0; j < equipos; ++j) {    // Recorre cada equipo j contra el que juega el equipo i
			if (i != j) {                      // Evita el partido contra sí mismo
				// Calcula los puntos según el resultado del partido
				if (v[i][j].first > v[i][j].second) clas[i].pts += 3;    // Si el equipo i gana, suma 3 puntos
				else if (v[i][j].first == v[i][j].second) clas[i].pts += 1; // Si empatan, suma 1 punto
				// Acumula los goles a favor y en contra para el equipo i
				clas[i].gf += v[i][j].first;   // Suma goles a favor del equipo i
				clas[i].gc += v[i][j].second;  // Suma goles en contra del equipo i
			}
		}
	}
	
	// Sección para contabilizar los puntos y goles de los equipos jugando "fuera de casa"
	for (int j = 0; j < equipos; ++j) {        // Recorre cada equipo j
		for (int i = 0; i < equipos; ++i) {    // Recorre cada equipo i contra el que juega el equipo j
			if (i != j) {                      // Evita el partido contra sí mismo
				// Calcula los puntos según el resultado del partido
				if (v[i][j].second > v[i][j].first) clas[j].pts += 3;    // Si el equipo j gana fuera de casa, suma 3 puntos
				else if (v[i][j].first == v[i][j].second) clas[j].pts += 1; // Si empatan, suma 1 punto
				// Acumula los goles a favor y en contra para el equipo j
				clas[j].gf += v[i][j].second;  // Suma goles a favor del equipo j
				clas[j].gc += v[i][j].first;   // Suma goles en contra del equipo j
			}
		}
	}

	return clas;  // Devuelve el vector con los equipos clasificados según sus puntos y goles
}

// Función de comparación para ordenar los equipos en la clasificación
bool comp(equipo v, equipo u)  {
	// Si los puntos son iguales, se compara la diferencia de goles (goles a favor - goles en contra)
	if (v.pts == u.pts) {
		if ((v.gf - v.gc) == (u.gf - u.gc)) return v.id < u.id; // Si la diferencia de goles también es igual, se ordena por el ID (menor ID primero)
		else return (v.gf - v.gc) > (u.gf - u.gc);              // Si la diferencia de goles no es igual, se ordena por la mejor diferencia de goles
	}
	else return v.pts > u.pts;   // Si los puntos son diferentes, se ordena por el equipo con más puntos
}

// Función para escribir la clasificación final en la consola
void escribe_matriz(const vector<equipo>& v) {
	int tam = v.size();    // Obtiene el tamaño del vector (cantidad de equipos clasificados)
	
	for (int i = 0; i < tam; ++i) {     // Recorre cada equipo clasificado
		// Imprime el identificador del equipo, sus puntos, goles a favor y goles en contra
		cout << v[i].id << " ";         
		cout << v[i].pts << " ";
		cout << v[i].gf << " ";
		cout << v[i].gc << endl;
	}
}

// Función principal del programa
int main() {
	int equipos;     // Número de equipos en la competición
	cin >> equipos;  // Lee el número de equipos
	Matriz resultados(equipos, Fila(equipos));  // Crea una matriz de resultados de tamaño [equipos][equipos]
	leer_matriz(resultados);                    // Llama a la función para leer los resultados
	vector<equipo> clasificacion;               // Vector para almacenar la clasificación de los equipos
	clasificacion = clasificar(resultados);     // Clasifica los equipos según los resultados
	sort(clasificacion.begin(), clasificacion.end(), comp);  // Ordena la clasificación utilizando la función de comparación
	escribe_matriz(clasificacion);              // Imprime la clasificación final
}
