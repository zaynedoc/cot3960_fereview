#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: file not found\n");
        return 1;
    }

    char name[100];

    // Read animals from file and insert into heap
    while (fscanf(file, "%s", name) != EOF) {
        // Function
    }

    fclose(file);

    return 0;
}

/* Code Expected Input & Output:

1. Read input file upon file execution
2. Denote wether input file is composed of only digits or only strings
3. List sorting algorithms with associated "execution codes"

    "1 -> Min heap sort
    2 -> AVL tree sort
    3 -> Merge sort
    4 -> Quick sort
    ..."

4. Sort alogirmth based on execution code
5. Example output:

    "Your original input:
    [6, 3, 7, 8, 2, 4]

    Sorted list using {algorithm}:
    [2, 3, 4, 6, 7, 8]"


    Other notes:
    - File I/O in only read mode (all operations conducted in terminal)
    - Utilize memory allocation to fullest extent
*/