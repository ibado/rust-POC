#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countWord(char* word, char* line) {
    size_t linelen = strlen(line) - 1;
    char* linecpy = (char*) malloc(linelen);
    strncpy(linecpy, line, linelen);

    const char* separator = " ";
    int count = 0;

    char* token = strtok(linecpy, separator);
    while (token != NULL) {
       if (strcmp(token, word) == 0) count++;
       token = strtok(NULL, separator);
    }

    free(linecpy);

    return count;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        puts("usage: ./main <filename> <word>");
        return EXIT_FAILURE;
    }
    char* filename = argv[1];
    char* word = argv[2];

    FILE *file;
    char *line = NULL;
    size_t len = 0;

    file = fopen(filename, "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    int count = 0;
    while (getline(&line, &len, file) != -1) {
        count += countWord(word, line);
    }

    printf("Word was found %d times\n", count);

    free(line);
    exit(EXIT_SUCCESS);
}
