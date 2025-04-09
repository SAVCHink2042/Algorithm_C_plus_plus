//определитель матрицы NxN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int getsize (const char *name);
int getsize (const char *name) {
    int w, n = 0;
    FILE *f;
    f = fopen (name, "r");
    if (!f) {
        printf (" Файл не открывается\n");
        return -1;
    }
    if (fscanf (f, "%d", &w) != 1)  {
        printf ("Файл пустой");
        fclose(f);
        return -1;
    }
    rewind (f);
    while (fscanf (f, "%d", &w) == 1) {
        n++;
    }
    fclose (f);
    return n;
}

double **filling_the_array ( int k, const char *name);
double **filling_the_array ( int k, const char *name) {
    int x, i, j;
    double **a;
    FILE *f;
    f = fopen (name, "r");
    a = (double**)malloc(sizeof(double*) * k);
    for(i = 0; i < k; i++) {
        a[i] = (double*) malloc( sizeof (double*) * k);
    }
    for(j=0;j<k; j++) {
        for(i=0; i<k; i++) {
            fscanf (f, "%d", &x);
            a[j][i]=x;
        }
    }
    fclose (f);
    return a;
}

double determinant (double **a, int k);
double determinant (double **a, int k) {
    double s=1, det=1,  w, r, e=1; 
    int i, ind, j, f, u, c=0; 
    while(1+e>1) {
        w=e;
        e=e/2;
    }
    while(c<k-1) {
        for(j=k-1; j>c; j--) {
            for(i=k-1; i>=c; i--) {
                if(fabs(a[j][c])>w) {
                    if(fabs(a[c][c])<w) {
                        for(f=c+1; f<k; f++) {
                            if(fabs(a[f][c])<w) {
                                ind=0;
                                continue;
                            }
                            else {
                                ind=1;
                                s*=-1;
                                for( u=c; u<k; u++) {
                                    r=a[c][u];
                                    a[c][u]=a[f][u];
                                    a[f][u]=r;
                                }
                                break;
                            }
                            if(ind==0) {
                                det=ind;
                                return det;
                            }
                        }
                    }
                    a[j][i]=a[j][i]*a[c][c]/a[j][c]-a[c][i];
                    if(i==k-1 ) {
                        det=det*a[j][c]/a[c][c];
                    }
                }
            }
        }
        c++;
    }
    for(i = 0; i < k; i++) {
        det*=a[i][i];
    }
    det*=s;
    return det;
}

int main(void) {
    int n, k, i;
    double **a, det;
    n = getsize ("in.txt");
    k = sqrt(n);
    a = filling_the_array ( k, "in.txt");
    det=determinant (a, k);
    printf("Определитель равен: %lf", det);
    for(i = 0; i < k; i++) {
        free(a[i]);
    }
    free(a);
    return 1;
}
