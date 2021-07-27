#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  long long int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(long long int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, long long int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(long long int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

int main() {
    // parameter about parsing token
    char* line = NULL;
    size_t size;
    ssize_t line_size;
    int line_count = 0;
    char* token;
    char delimit[] = " ,/."; 
    long long int convert_int = 0;
    
    //init Array
    Array a;
    initArray(&a, 2);
    
    //parse input string to int
    line_size = getline(&line, &size, stdin);

    while (line_size != -1) {
        line_count ++;
        token = strtok(line, delimit);
        while(token != NULL){
            convert_int = atoll(token);
            insertArray(&a, convert_int);

            token = strtok(NULL, delimit);
        }
        
        // if you only type space line_size=1, type the other character
        // ex:tab, space....,line_size = 2
        if (line_size == 1) {
            free(line);
            line = NULL;

            // if matrix has 4 rows, line_count = 5
            // line_count -1 = matrix row number
            // add token to dynamic array
            for (int i = 0; i < line_count-1; i++) {
                long long int result = 0;
                result = (a.array[i*2] > a.array[i*2+1]) ? a.array[i*2]-a.array[i*2+1] : a.array[i*2+1]- a.array[i*2];
                printf("%lld\n", result);
            }

            freeArray(&a);
            break;
        }
        else{
            line_size = getline(&line, &size, stdin);
        }
    }
    
    return 0;
}
