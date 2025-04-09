#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void get_massiv(int* array, int l);
void get_massiv(int* array, int l){
    int i;
    for ( i = 0; i < l; i++)
    {
        array[i] = rand()%100;
    }
}

bool examination_massiv(int *array,  int l);
bool examination_massiv(int *array,  int l) {
   int i;
    for (i = 1; i < l; i++)
    {
        if (array[i - 1] > array[i]) {
            return false;
       }
    }
    return true;
}


void sort_massiv(int* array, int l);
void sort_massiv(int* array, int l) {
    int p, buf, j ,i;
    for ( i = 0; i < l; i++) {
        p = i;
        for ( j = i + 1; j < l; j++) {
            if (array[p] > array[j]) {
                p = j;
        }
        }
        buf = array[p];
        array[p] = array[i];
        array[i] = buf;
  }
}
int main(void)  {
    clock_t begin; 
    clock_t end;
    double time;
    int* array;
    int l;
    begin = clock();
    printf("Введите размер массива\n");
    scanf("%d",&l);
    array = (int*)malloc(l * sizeof(int*));
    get_massiv(array, l);
    sort_massiv(array, l);
    end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    if (examination_massiv(array,l)) {
    printf("Массив отсортирован за %lf",time);
    }
    else {
       printf("массив не отсортирован");
    }
    free(array);
}

      
