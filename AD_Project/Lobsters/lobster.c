#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "lobster.h"

void set_matrix_value(matrix *target_matrix, unsigned long long row_index, unsigned long long column_index, unsigned long long element_value){
	unsigned long position;
	position = row_index * target_matrix->no_cols + column_index;
	*(target_matrix->matrix_element + position) = element_value;
}

unsigned long long get_matrix_value(matrix *target_matrix, unsigned long long row_index, unsigned long long column_index){
	return *(target_matrix->matrix_element + row_index * target_matrix->no_cols + column_index);
}

unsigned long long get_max(unsigned long long val1, unsigned long long val2){
	return (val1>val2) ? val1 : val2;
}

void dynamic_programming_lobster(lobster *lobster_collection, unsigned long long no_objects, unsigned long long max_capacity, FILE* output){
	matrix dynamic_matrix;
	unsigned long long objects_iterator;
	unsigned long long size_iterator;
	unsigned long long knapsack_value;
	unsigned long long current_size;
	unsigned long long current_object;

	dynamic_matrix.no_rows = no_objects + 1;
	dynamic_matrix.no_cols = max_capacity + 1;

	dynamic_matrix.matrix_element = malloc((dynamic_matrix.no_rows) * (dynamic_matrix.no_cols) * sizeof(unsigned long long));

	for(objects_iterator=0; objects_iterator<=no_objects; objects_iterator++)
	{
		for(size_iterator=0; size_iterator<=max_capacity; size_iterator++)
		{
			if(size_iterator==0 || objects_iterator==0)
			{
				set_matrix_value(&dynamic_matrix, objects_iterator, size_iterator, 0);
			}
			else if (lobster_collection[objects_iterator-1].size <= size_iterator)
			{
				set_matrix_value(&dynamic_matrix, objects_iterator, size_iterator,
						get_max(lobster_collection[objects_iterator-1].value +
							get_matrix_value(&dynamic_matrix, objects_iterator-1, size_iterator-lobster_collection[objects_iterator-1].size),
							get_matrix_value(&dynamic_matrix, objects_iterator-1, size_iterator)));
			}
			else {
				set_matrix_value(&dynamic_matrix, objects_iterator, size_iterator, get_matrix_value(&dynamic_matrix, objects_iterator-1, size_iterator));
			}
		}
	}

	knapsack_value = get_matrix_value(&dynamic_matrix, dynamic_matrix.no_rows - 1, dynamic_matrix.no_cols - 1);

	current_size = dynamic_matrix.no_cols - 1;
	current_object = dynamic_matrix.no_rows - 1;

	while(current_object != 0 && current_size != 0) {
		if(get_matrix_value(&dynamic_matrix, current_object, current_size) != get_matrix_value(&dynamic_matrix, current_object-1, current_size))
		{
			fprintf(output, "%s\n", lobster_collection[current_object-1].name);
			current_size = (current_size > lobster_collection[current_object-1].size) ? current_size - lobster_collection[current_object-1].size : 0;
		}
		current_object--;
	}

	free(dynamic_matrix.matrix_element);

	fprintf(output, "\n=== Value in the knapsack %llu ===", knapsack_value);
}
