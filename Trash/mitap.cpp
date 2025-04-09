/*Митап бэкенда 1 задача 2023 */



#include <cstring>
#include <iostream>
using namespace std;

char **input_matr(int N, int M);
char **input_matr(int N, int M) {
    int i, j;
    char** array;
    unsigned int r=M;
    string line;
    array = (char**)malloc(sizeof(char*) * N);
    for(i = 0; i < N; i++) {
        array[i] = (char*) malloc( sizeof (char*) * M);
    }
    for(j=0;j<N; j++) {
        getline(cin, line);
        if( line.length()!=r ) {
        	getline(cin, line);
        }
        	for(i=0; i<M; i++) {
            	array[j][i]=line[i];
        	}
    }
    return array;
}

void output_matr(int N, int M, char **array);
void output_matr(int N, int M, char **array) {
    int j, i;
    for(j=0;j<N; j++) {
        for(i=0; i<M; i++) {
            printf("%c", array[j][i]);
        }
        printf("\n");
    }
}

int main(void) {
    int N, M, i, z, r , j, x , counter;
    char **array, e;
    string q;
    cin>>N;
    cin>>M;
    counter=N;
    array=input_matr(N, M);
    cin>>z;
		for (i=0; i<z; i++) {
		  cin>>q;
		  cin>>r;       
		  cin>>e;      
		  for(x=counter-2; x>counter-r-2; x--) {
		      for(j=0; j<M; j++) {
		          if(array[x][j]==' ') {
		           array[x][j]=e;
		     //    cout<<N;
		          }
		        }
		 		 }
		 	counter-=r;
    }
    output_matr(N, M, array);
    for(i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
    return 1;
}
