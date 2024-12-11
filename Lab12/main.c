#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT_FILE_NAME "output.txt"
#define IN_FILE_NAME "input.txt"

int main(int argc, char const *argv[]) {
    FILE *output_file = NULL;
    FILE *input_file = NULL;

    // 1 - Open input file
    input_file = fopen(IN_FILE_NAME, "r");
    if (!input_file) {
        perror("Cannot open input file");
        return EXIT_FAILURE;
    }

    // 2 - Open output file
    output_file = fopen(OUT_FILE_NAME, "w");
    if (!output_file) {
        perror("Cannot open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // 3 - Count lines in input file
    char buffer[255] = {0};
    int line_counter = 0;
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        line_counter++;
    }

    // 4 - Allocate memory for each line in the dump
    char **dump = (char **)malloc(line_counter * sizeof(char *));
    if (!dump) {
        perror("Memory allocation failed");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    // 5 - Read each line from the input file into the buffer
    int line = 0;
    rewind(input_file);
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        dump[line] = (char *)malloc(strlen(buffer) + 1);
        memcpy(dump[line], buffer, strlen(buffer) + 1);
        ++line;
    }

    // 6 - Process each line to replace "TODO" with "DONE"
    for (int i = 0; i < line_counter; ++i) {
        char *pch = strstr(dump[i], "TODO");
        while (pch) {
            memcpy(pch, "DONE", 4);
            pch = strstr(pch + 4, "TODO"); 
        }
    }

    // 7 - Write each line to the output file
    for (int i = 0; i < line_counter; ++i) {
        printf("%s", dump[i]);
        if (dump[i]) {
            fprintf(output_file, "%s", dump[i]);
        }
        free(dump[i]); // Free memory for each line
    }

    // 8 - Write the total line count at the end of the file
    fprintf(output_file, "\nTotal Line Count: %d\n", line_counter);
    printf("\nTotal Line Count: %d\n", line_counter);

    // 9 - Clean up
    free(dump);
    fclose(input_file);
    fclose(output_file);

}