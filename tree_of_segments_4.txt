/* Ближайшее большее число справа/ Дан массив a n чисел. Нужно обрабатывать запросы:
0. set(i, x) — присвоить новое значение элементу массива a[i] = x;
1. get(i, x) — найти индекс min k: k>=i и a[k] >= x */

#include<bits/stdc++.h>

using namespace std;

#define scl static_cast<long long int>
#define sci static_cast<int>
#define scd static_cast<long double>
#define gcd __gcd
#define vlli vector<vector<lli>> 
#define vi vector<vector<int>> 

using lli =  long long;
using ld  =  long double;
using ull =  unsigned long long;

struct Data{
  int l, r, num= INT_MIN ;
};

int find_size(int n ) {
  int k = 1;
  while(k < n ) {
      k = 2*k;
  }
  return k;
}

void input(vector<Data> &vec, int n, int size ) {
    for( int i = size-1 ; i < 2 * size - 1; i++  ) {
        if(i -size +1 < n ) {
            cin >> vec[i].num;
        }
        vec[i].l = i - size + 2;
        vec[i].r = i - size + 2;
    }
    for( int i = size -2 ; i > -1 ; i-- ) {             /// ИСПРАВИТЬ ФУНКЦИЮ ИНПУТ ИНАЧЕ ШЛЯПА КАКАЯ-то
        vec[i].num = max( vec[2*i+2].num, vec[2*i+1].num );
        vec[i].l = vec[2*i+1].l;
        vec[i].r = vec[2*i+2].r;
    }
} 

int obhod(int index, const vector<Data> &vec, int left, int right, const int number) {
    if( vec[index].l == left and vec[index].r == right ) {
        if( vec[index].num >= number ) {
            while( vec[index].r != vec[index].l  ) {
                if(vec[ 2*index+1 ].num >= number ) {
                    index = 2 * index + 1;
                }
                else {
                    index = 2 * index + 2;
                }
            }
            return vec[index].r;
        }
        else {
            return -1;
        }
    }
    else if( vec[index].l > right or vec[index].r < left ) {
        return -1;
    }
    else {
        int len = vec[index].r-vec[index].l+1, levaya = left, pravaya = right;
        if( left < vec[index].l + len / 2 and right >= vec[index].l+ len/2 ) {
            levaya =  vec[index].l + len / 2;
            pravaya = vec[index].l + len / 2 - 1;
        }
        int p1 = obhod( 2*index + 1, vec, left, pravaya, number );   // левый сые 
        int p2 = obhod( 2*index + 2, vec, levaya, right, number );    // правый сын
        if(p1 == -1 and p2 == -1 ) {
            return -1;
        }
        else if( p1 == -1  ) {
            return p2;
        }
        else if(p2 == -1 ){
            return p1;
        }
        else {
          return min(p1, p2);
        }
    }
}

void change(vector<Data> &vec, int index_upg,const int& new_number) {
    vec[index_upg].num = new_number;
    while(index_upg > 0 ) {
        index_upg = (index_upg-1)/2;
        vec[index_upg].num = max( vec[ 2*index_upg+1 ].num, vec[2*index_upg + 2 ].num );
    }
}

void SAVCH_inc() {
    int n, k;
    cin >> n >> k ;
    
    int size = find_size(n);
    vector< Data > vec(2*size -1 ); 
    input(vec, n, size);
    int a, b, c;
    
    for( int i = 0 ; i< k ; i++ ) {
        cin >> a >> b >> c;
        if(a == 0 ) {
            change(vec, size + b - 2, c);
        }
        else {
            cout << obhod(0, vec,  b, n, c) << endl;
        }
    }
}


int main() {
   SAVCH_inc();
}




