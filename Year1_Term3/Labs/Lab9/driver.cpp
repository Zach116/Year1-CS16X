#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tools.h"

int get_dimension() {
	char height[256];

	do {
		scanf("%s", &height);
		
		if (!is_int(height) || get_int(height) < 1 || get_int(height) >10){
			printf("Please enter a number between 0 and 10! \n ");
		}


	} while (!is_int(height) || get_int(height) < 1 || get_int(height) >10);

	return get_int(height);
}

int** malloc_mem(int width, int height) {
	int** arr;
	time_t t;

	arr = (int**) malloc(sizeof(int)*width);

	for (int i =0; i < width; i++) {
		arr[i] = (int*) malloc(sizeof(int)*height);
	}

	srand((unsigned) time(&t));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[j][i]= ((rand() % 50) + 1);
		}
	}

	return arr;
}

void print_arr(int** arr, int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
}

int get_input() {
	char num[256];

	do {
		scanf("%s", &num);
		
		if (!is_int(num) || get_int(num) < 0){
			printf("Please enter a number greater than 0! \n ");
		}


	} while (!is_int(num) || get_int(num) < 0);

	return get_int(num);

}

void add_element(int** arr, int num, int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[j][i] += num;
		}
	}
}

void delete_arr(int** arr, int width, int height) {
	for (int j = 0; j < width; j++) {
		free(arr[j]);
	}
	free(arr);
}

int main() {
	int** arr;
	int height, width, num;

	printf("Please enter the width \n");
	width = get_dimension();
	printf("Please enter the height \n");
	height = get_dimension();
	printf("\n");

	arr = malloc_mem(width, height);
	
	print_arr(arr, width, height);
	
	printf("Please enter a number to add \n");	
	num = get_input();
	printf("\n");

	add_element(arr, num, width, height);

	print_arr(arr, width, height);

	delete_arr(arr, width, height);
}
