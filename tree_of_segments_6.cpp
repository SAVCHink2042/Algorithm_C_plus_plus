/* Реализуйте эффективную структуру данных для хранения элементов и увеличения нескольких подряд идущих элементов на одно и то же число.   (g — получить текущее значение элемента по его номеру, а — увеличить все элементы на отрезке). */

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
  lli l, r, num= 0;
};

lli find_size(lli n ) {
    lli k = 1;
    while(k < n ) {
        k = 2*k;
    }
    return k;
}

unordered_map< lli , lli > um;

void input(vector<Data> &vec, lli n, lli size ) {  
    for( int i = size - 1 ; i < 2*size - 1; i++ ) {
        if( i - size + 1 < n  ) {
            cin >> vec[i].num;   
        }
        vec[i].l = i - size + 2;
        vec[i].r = i - size + 2 ;
    }
    for( int i = size - 2; i > -1  ; i-- ) {
        vec[i].l = vec[2*i+1].l;
        vec[i].r = vec[2*i+2].r;
    }
} 

lli obhod(lli index,  vector<Data> &vec, lli ind, lli size ) {
  
    while( vec[index].l != vec[index].r ) {
        
        um[2*index + 1] += um[index];
        um[2*index + 2] += um[index];
        um[index] = 0;
        
        if( vec[2*index+1].r >= ind ) {
            index = 2*index + 1;
        }
        else {
            index = 2*index + 2 ;
        }
    }
    vec[index].num += um[index];
    um[index] = 0;
    return vec[index].num; 
}

void change(lli index, vector<Data> &vec, lli left, lli right, lli number ) {   //ХОЧУ ПИВО
    if( vec[index].l == left and vec[index].r == right ) {
        um[index] += number;
    }
    else if( vec[index].l > right or vec[index].r < left ) {
        return;
    }
    else {
        lli len = vec[index].r - vec[index].l + 1, pravaya = right, levaya = left;
        if( left < vec[index].l + len / 2 and right >= vec[index].l + len / 2 ) {
            levaya  = vec[index].l + len / 2;
            pravaya = vec[index].l + len / 2 - 1;
        }
        change( 2 * index + 1, vec, left, pravaya, number );
        change( 2 * index + 2, vec, levaya, right, number );
    }
}

void SAVCH_inc() {
    lli n, m, a, b, c;
    cin >> n;
    string s;
    lli size = find_size(n);
    vector<Data> vec( 2 * size - 1 );
    input(vec, n, size );
    cin >> m;
    for( int i = 0 ; i < m ; i++ ) {
        cin >> s ;
        if( s == "g" ) {
            cin >> a;
            cout << obhod(0, vec, a, size) << endl; 
            
        }
        else {
            cin >> a >> b >> c;
            change(0, vec, a, b, c );
        }
    }
}

int main() {
   Sachine();
}
