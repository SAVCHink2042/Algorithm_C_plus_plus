/* Реализуйте структуру данных, позволяющую изменять элементы массива и вычислять индекс 
k-го слева нуля на данном отрезке в массиве.

Формат ввода
В первой строке вводится одно натуральное число 
N- количество чисел в массиве. Во второй строке вводятся 
элементы массива. В третьей строке вводится одно натуральное число 
M — количество запросов. Каждая из следующих 
M строк - описание запроса. Сначала буква, кодирующая вид запроса (s — вычислить индекс 
k
k-го нуля, u — обновить значение элемента). Следом за s вводится три числа — левый и правый концы отрезка и число 
Следом за u вводятся два числа — номер элемента и его новое значение.

Формат вывода
Для каждого запроса 
s выведите результат. Все числа выводите в одну строку через пробел. Если нужного числа нулей на запрашиваемом отрезке нет, выводите  −1 */

 
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
   int num = -1 , count = 0, l, r;     // count - число нулей получается.
};

void input(vector<Data> &vec, const int &size, const int &n) {
    for( int i = size - 1; i < 2 * size-1; i++ ) {
        if( i - size + 1 < n ) {
            cin >> vec[i].num ;
            if( vec[i].num == 0 ) {
                vec[i].count = 1;
            }
        }
        vec[i].l = i - size + 2;
        vec[i].r = i - size + 2;
    }
    
    for( int i = size -2 ; i > -1; i-- ) {
        vec[i].count = vec[ 2*i + 1 ].count + vec[ 2*i + 2 ].count;
        vec[i].l = vec[2*i + 1].l;
        vec[i].r = vec[2*i + 2].r;
    }
    
}

int find_size(int n) {
    int k = 1;
    while (k < n) {
        k *= 2;
    }
    return k;
}               


void change( vector<Data > &vec, int index_upg, const int& new_number ) {
    if( vec[index_upg].num != 0 and new_number == 0 ) {
        vec[index_upg].num = new_number;
        vec[index_upg].count = 1;
    }
    if(vec[index_upg].num == 0 and new_number != 0 ) {
        vec[index_upg].num = new_number;
        vec[index_upg].count = 0;
    }
    while( index_upg != 0 ) {
        index_upg = ( index_upg - 1 ) / 2;
        vec[index_upg].count = vec[ 2 * index_upg + 1 ].count + vec[ 2*index_upg + 2].count;
    }
}

int find_preffix(int index, int left, int right,const vector<Data>& vec) {
    if(vec[index].l== left and vec[index].r == right ) {
        return vec[index].count;
    }  
    else if(vec[index].l > right or vec[index].r < left ) {
        return 0;
    }
    int len = vec[index].r-vec[index].l + 1, pravaya= right, levaya=left;
    if( left < vec[index].l + len/2 and right >= vec[index].l+len/2) {
      levaya =  vec[index].l + len / 2;
      pravaya = vec[index].l + len / 2 - 1;
    }
    return ( find_preffix( 2*index + 1, left, pravaya, vec ) + find_preffix(2*index + 2, levaya, right,  vec ) );
}

int find_k_zero(int index, int left, int right, int k_zero, vector<Data> &vec, int size ) {
    if( find_preffix(0, 1, right, vec ) < k_zero  ) {
        return -1;
    }
    while(vec[index].r != vec[index].l  ) {
        if( k_zero <= vec[ 2 * index + 1 ].count ) {
            index = 2*index + 1;
        }
        else {
            k_zero -= vec[ 2 * index + 1 ].count;
            index = 2*index + 2;
            if( k_zero <= 0 ) {
                return -1;
            }
        }
    }
    if( vec[index].num != 0  ) { //мб тут шляпа написана    
      return -1;
    }
    return index - size + 2 ;         
}

void SAVCH_inc() {
    int n, k, left, right, number_zero;
    char str;
    cin >> n;
    int size = find_size(n);
    vector< Data > vec(2 * size - 1);
    
    input(vec, size, n);

    cin >> k ;
    for ( int i = 0; i < k; i++ ) {
        cin >> str ;
        if( str == 's' ) {
            cin >> left >> right >> number_zero;
            number_zero += find_preffix(0, 1, left-1, vec );
          //  cout<<" КОЛИЧЕСТВО НУЛЕЙ"<<number_zero << endl;
            cout <<  find_k_zero(0, 1, right, number_zero, vec, size )<< " ";
        }
        else {
            cin >> left >> right;
            change(vec, size + left - 2, right);
        }
    }
}

int main() {
    SAVCH_inc();
}
