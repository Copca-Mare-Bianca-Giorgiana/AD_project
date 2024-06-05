#ifndef LOBSTER_H
#define LOBSTER_H

#define MAX_NAME_SIZE 100

#include <stdio.h>

typedef struct LOBSTER {
    unsigned long long size;
    unsigned long long value;
    char name[MAX_NAME_SIZE];
} lobster;

typedef struct MATRIX {
    unsigned long long no_rows;
    unsigned long long no_cols;
    unsigned long long *matrix_element;
} matrix;

void set_matrix_value(matrix* target_matrix, unsigned long long row_index, unsigned long long column_index, unsigned long long element_value);
void dynamic_programming_lobster(lobster *lobster_collection, unsigned long long no_objects, unsigned long long max_capacity, FILE* output);
unsigned long long get_matrix_value(matrix* target_matrix, unsigned long long row_index, unsigned long long column_index);
unsigned long long get_max(unsigned long long val1, unsigned long long val2);

#endif
