/* Реализуйте структуру данных, позволяющую изменять элементы массива и вычислять максимальное значение из нескольких подряд идущих элементов.
Формат ввода
В первой строке вводится одно натуральное число  N- количество чисел в массиве
Во второй строке вводятся  элементы массива.
В третьей строке вводится одно число M - количество запросов.
Каждая из следующих  M строк представляет собой описание запроса. Сначала вводится одна буква, кодирующая вид запроса (
s — вычислить максимум, u — обновить значение элемента).
Следом за s вводятся два числа — номера левой и правой границы отрезка. Следом за u вводятся два числа — номер элемента и его новое значение.

Формат вывода
Для каждого запроса s выведите результат. Все числа выводите в одну строку через пробел. */

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

struct Data {
    int l = 0;
    int r = 0;
    int num = 0;
};

void input(vector<Data> &vec, const int &size, const int &n) {
    for (int i = size - 1; i < 2*size -1 ; i++) {
        if( i - size + 1 < n) {
          cin >> vec[i].num ;  
        }
        vec[i].l = i - size + 2;
        vec[i].r = i - size + 2;
    }
    for( int i = size - 2; i > -1; i-- ) {
        if(vec[2*i+1].num == vec[2*i+2].num ) {
            vec[i] = { vec[2*i+1].l, vec[2*i+2].r, vec[2*i+1].num };
        }
        else {
          int index;
          if(vec[2*i+1].num > vec[2*i+2].num ) {
              index = 2*i+1;
          }
          else {
              index = 2*i+2;
          }
          vec[i] = { vec[2*i+1].l, vec[2*i+2].r, vec[index].num } ;
        }
    }
}

int find_size(int n) {
    int k = 1;
    while (k < n) {
        k *= 2;
    }
    return k;
}               //первое число пары- максимум. второе число -количество максимумов 
 
int obhod (int index, int left, int right,const vector<Data>& vec ) {
   // cout<<"АБОБА " <<left << " "<< right << endl;
    if( vec[index].l == left and vec[index].r == right)  { 
        return  vec[index].num;
    }
    else if( vec[index].r < left or  vec[index].l > right ) {                   //left , right -границы заданного промежутка 
        return  INT_MIN;
    }
    else {
        int p1, p2;
        int pravaya=right, levaya=left, len = vec[index].r-vec[index].l + 1;

        if( left < vec[index].l +len/2 and right >= vec[index].l+len/2  ) {
            levaya = vec[index].l+len/2;
            pravaya = vec[index].l+len/2-1;
        }
        p1 = obhod( 2*index+1, left, pravaya, vec);  // левый  
        p2 = obhod( 2*index+2, levaya , right, vec);  // правый
        if(p1 >= p2 ) {
            return p1;
        }
        else {
            return p2;
        }
    }
}

void change(vector<Data > &vec, int index_upg,const int& new_number ) {
    vec[ index_upg ].num = new_number;
    while( true ) {
        index_upg = ( index_upg - 1 ) / 2;
        vec[ index_upg ].num =  max( vec[ 2*index_upg+1 ].num, vec[ 2*index_upg+2 ].num );
        if( index_upg == 0 ) {
            break;
        }
    }
}

void SAVCH_inc() {
    int n, k, left, right;
    char str;
    cin >> n;
    int size = find_size(n);
    vector< Data > vec(2 * size - 1);
    
    input(vec, size, n);

    cin >> k;
    for ( int i = 0; i < k; i++) {
        cin >> str >> left >> right;
        if( str == 's' ) {
            int ans;
            ans = obhod( 0, left , right, vec );
            cout<< ans  << " ";
        }
        else {
          change(vec, size + left - 2, right);
        }
    }
}

int main() {
    SAVCH_inc();
}
