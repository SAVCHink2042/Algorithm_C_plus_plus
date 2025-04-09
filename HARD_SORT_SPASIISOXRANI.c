#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool examination_massiv(int *a,  int l);
bool examination_massiv(int *a,  int l) {
    int i;
    for (i = 1; i < l; i++)
    {
        if (a[i - 1] > a[i]) {
            return false;
       }
    }
    return true;
}
int* sort_lin( int l);
int* sort_lin( int l) {
   int *a, *b;
   int x=100, y=0,s=0, z=0,i, j=0, counter, buf;
   b = malloc((x-y+1)*sizeof(int));
   a = malloc(l*sizeof(int));
   for(i=0; i<l; i++) {
      a[i]=rand() % 100;
   }
   counter = y;
   buf=y;
   while (s < x-y+1){
     z=0;
     for (i = 0; i < l; i++) {
        if (counter == a[i]) {
	   z++;
        }
    }
    b[s] = z;
    counter++;
    s++;
    }
    for (i = 0; i < x-y+1; i++){
       if (b[i]> 0){
          for (z = j; z < j+b[i]; z++){
             a[z]=buf;
            }
       }
       if(b[i]<0) {
          printf("Ошибка");
       }
       buf++;
       j +=b[i];
     }
   free(b);
   return a;
}

int main(void)  {
    clock_t start; 
    clock_t end;
    double t;
    int *a;
    int l;
    printf("Введите размер массива\n");
    scanf("%d",&l);
    start = clock();
    a=sort_lin( l);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    if (examination_massiv(a,l)) {
       printf("Массивный массив отсортирован за %lf",t);
    }
    else {
       printf("массив не отсортирован");
    }
    free(a);
}
