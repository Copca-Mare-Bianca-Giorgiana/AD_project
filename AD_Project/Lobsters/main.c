#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "lobster.h"

int main()
{
    unsigned long long bag_size, lobster_number = 0;
    clock_t start, end;

    start = clock();

    FILE *input, *output;

    lobster* lobster_collection = malloc(sizeof(lobster));

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (input == NULL || output == NULL)
    {
        fprintf(stderr, "Failed to open files\n");
        return 1;
    }

    fscanf(input, "%llu", &bag_size);

    while (fscanf(input, "%s %llu %llu",
                  lobster_collection[lobster_number].name,
                  &lobster_collection[lobster_number].size,
                  &lobster_collection[lobster_number].value) != EOF)
    {
        if (lobster_collection[lobster_number].size <= bag_size)
        {
            lobster_number++;
            lobster_collection = realloc(lobster_collection, sizeof(lobster) * (lobster_number + 2));
        }
    }

    dynamic_programming_lobster(lobster_collection, lobster_number, bag_size, output);

    end = clock();

    fprintf(output, "\nTime: %lf seconds\n", (double)((end - start)) / CLOCKS_PER_SEC);

    free(lobster_collection);
    fclose(input);
    fclose(output);

    return 0;
}
