/* Ejemplo de una estructura de datos dinámica: pila de edades de N personas */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int edad;
	struct nodo *puntero;	
} Nodo;

Nodo *crearNodo(int edad);
Nodo *crearPila();
void crearNodo2(Nodo **, int edad);
void crearPila2(Nodo **);
void recorrerPila(Nodo *pila);

int main() {
	printf("\nCreacion de pila1:\n");
	Nodo *pila = crearPila();
	printf("\nRecorriendo la pila...:\n");
	recorrerPila(pila);
	
	printf("\n\nCreacion de pila2:\n");
	Nodo *pila2 = NULL;
	crearPila2(&pila2);
	printf("\nRecorriendo la pila2...:\n");
	recorrerPila(pila2);
	
	return 0;
}

Nodo* crearNodo(int edad) {
	Nodo *p = malloc(sizeof(Nodo));
	p->edad = edad;
	p->puntero = NULL;
	return p;
}

void crearNodo2(Nodo **p, int edad) {
	*p = malloc(sizeof(Nodo));
	(*p)->edad = edad;
	(*p)->puntero = NULL;
}

Nodo* crearPila() {
	Nodo *pila = NULL;
	Nodo *aux = NULL;
	int cantidad;
	int i;
	int edad;
	
	printf("Ingrese la cantidad de personas: ");
	scanf("%d", &cantidad);
	for (i = 0; i < cantidad; ++i) {
		printf("Ingrese la edad de la persona #%d: ", (i + 1));
		scanf("%d", &edad);
		
		if (pila == NULL) {
			pila = crearNodo(edad);
		} else {
			aux = crearNodo(edad);
			aux->puntero = pila;
			pila = aux;
		}
	}
	
	return pila;
}

void crearPila2(Nodo **pila) {
	Nodo *aux = NULL;
	int cantidad;
	int i;
	int edad;
	
	printf("Ingrese la cantidad de personas: ");
	scanf("%d", &cantidad);
	for (i = 0; i < cantidad; ++i) {
		printf("Ingrese la edad de la persona #%d: ", (i + 1));
		scanf("%d", &edad);
		
		if (*pila == NULL) {
			crearNodo2(pila, edad);
		} else {
			crearNodo2(&aux, edad);
			aux->puntero = *pila;
			*pila = aux;
		}
	}
}

void recorrerPila(Nodo *pila) {
	while (pila != NULL) {
		printf("->%d ", pila->edad);
		pila = pila->puntero;
	}
}

