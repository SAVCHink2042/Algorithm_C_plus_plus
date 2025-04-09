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

double *filling_the_array (int n, const char *name);
double *filling_the_array (int n, const char *name) {
    int x, i;
    double *a;
    FILE *f;
    f = fopen (name, "r");
    a = (double*)malloc(n*sizeof(double));
    if (!a) {
        printf (" Память для массива не выделена");
        fclose (f);
        return 0;
    }
    for (i = 0; i < n; i++) {
        fscanf (f, "%d", &x);                     
        a[i] = x;
    }
    fclose (f);
    return a;
}

double determinant (double *a, int n);
double determinant (double *a, int n) {
    int k, i, j, c = 0,  f, r, ind, u;
    double det = 1, e=1, w, s = 1; 
     while(1+e>1) {
        w=e;
        e=e/2;
    }
    k = sqrt (n);
    while(c<k-1) {        
        for(j=k-1; j>c; j--) {
            for(i=k-1; i>=c; i--) {
                if(fabs(a[j*k+c])>w) {
                    if(fabs(a[c*k+c])<w) {
                        for(f=c+1; f<k; f++) {
                            if(fabs(a[f*k+c])<w) {
                                ind=0;
                                continue;
                            }
                            else {
                                ind=1;
                                s*=-1;
                                for(u=c; u<k; u++) {
                                    r=a[c*k+u];
                                    a[c*k+u]=a[f*k+u];
                                    a[f*k+u]=r;
                                }
                                break;
                            }
                            if(ind==0) {
                                det=ind;
                                return det;
                            }
                        }
                    }
                        a[j*k+i]=a[j*k+i]*a[c*k+c]/a[j*k+c] -a[c*k+i];
                        if(i==k-1) {
                            det=det*a[j*k+c]/a[c*k+c];
                    }
                }
                
            }
        }         
    c++;
    }
    for(i = 0; i < k; i++) {
        det *= a[i * k + i];
    }
    det *= s;
    return det;
}

int main(void) {
    int n;
    
    double *a, det;
    n = getsize ("in.txt");
    a = filling_the_array (n, "in.txt");
    det=determinant (a, n);
    printf ("Определитель: %f\n", det);
    free (a);
    return 1;
}

