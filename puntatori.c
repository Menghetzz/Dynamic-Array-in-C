#include <stdio.h>
#include <stdlib.h>

#define NUMBERS 3000

typedef struct {
	int* item;      // Puntatore all'array dinamico
	int size;       // Numero di elementi attualmente presenti
	int capacity;   // Capacità  massima allocata
} DynamicArray;

void create(DynamicArray* array) {
	array->capacity = 0;
	array->size = 0;
	array->item = NULL;
}

void append(DynamicArray* array, int valore) {
	if(array->capacity == array->size) {
		if (array->capacity == 0) {
			array->capacity++;
		}
		array->capacity *= 2;
		array->item = realloc(array->item, array->capacity * sizeof(int));
		if (array->item == NULL) {
			fprintf(stderr, "Error while reallocating memory!");
			exit(EXIT_FAILURE);
		}
		
	}
	array->item[array->size] = valore;
	array->size++;
}

void destroy(DynamicArray* array) {
	free(array->item);
	array->item = NULL;
	array->capacity = 0;
	array->size = 0;
}

int main()
{
	DynamicArray* array = malloc(sizeof(DynamicArray));
	create(array);

	for (int i = 1; i <= NUMBERS; i++) {
		append(array, i);
	}

	for (int i = 0; i < NUMBERS; i++) {
		printf("%d ", array->item[i]);
	}

	destroy(array);

	// We can now recreate another one

	create(array);

	for (int i = 1; i <= NUMBERS / 2; i++) {
		append(array, i);
	}

	for (int i = 0; i < NUMBERS / 2; i++) {
		printf("%d ", array->item[i]);
	}

	destroy(array);
	free(array);

	return 0;
}