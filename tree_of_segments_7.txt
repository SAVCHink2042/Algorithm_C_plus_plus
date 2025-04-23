/*Реализуйте эффективную структуру данных для хранения массива и выполнения следующих операций: увеличение всех элементов данного интервала на одно и то же число; поиск максимума на интервале.*/

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
  lli l, r, num = INT_MIN, add_1=0;   
};                                               
lli find_size(lli n ) {
    lli k = 1;
    while(k < n ) {
        k = 2*k;
    }
    return k;
}

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
        vec[i].num = max( vec[ 2 * i + 1 ].num, vec[ 2 * i + 2 ].num );
    }
} 

lli obhod(lli index,  vector<Data> &vec, lli left, lli right ) {
    if( vec[index].l == left and vec[index].r == right ) {
        vec[index].num += vec[index].add_1;
        if(vec[index].l != vec[index].r ) {
            vec[2*index + 1].add_1 += vec[index].add_1;
            vec[2*index + 2].add_1 += vec[index].add_1;
        } 
        vec[index].add_1 = 0;
        return vec[index].num;
    }
    else if(vec[index].l > right or vec[index].r < left ) {
        return INT_MIN;
    }
    else {
        lli len = vec[index].r - vec[index].l + 1, levaya = left, pravaya = right; 
        if(left < vec[index].l + len / 2 and right >= vec[index].l + len / 2 ) {
            levaya  = vec[index].l + len / 2;
            pravaya = vec[index].l + len / 2 - 1; 
        }
        vec[index].num += vec[index].add_1;
        if( vec[index].r != vec[index].l )  {
				    vec[2*index + 1].add_1 += vec[index].add_1;
				    vec[2*index + 2].add_1 += vec[index].add_1; 
       	} 
        vec[index].add_1 = 0;
        
        lli p1 = obhod( 2*index + 1, vec, left, pravaya );
        lli p2 = obhod( 2*index + 2, vec, levaya, right );
        return max(p1, p2);
    }
}

void change(lli index, vector<Data> &vec, lli left, lli right, lli number ) {   //ХОЧУ ПИВО
    if( vec[index].l == left and vec[index].r == right ) {
        vec[index].num += number + vec[index].add_1;
        if(vec[index].l != vec[index].r ) {
            vec[2*index + 1].add_1 += number + vec[index].add_1;
            vec[2*index + 2].add_1 += number + vec[index].add_1;
        } 
        vec[index].add_1 = 0;
        while(index!= 0) {
            index =(index -1 ) / 2;
            vec[index].num = max( vec[2*index+1].num+vec[2*index + 1].add_1, vec[2*index + 2].num  + vec[2 * index + 2 ].add_1 );
        }
    }
    else if(vec[index].r < left  or vec[index].l > right ) {
      return ; 
    } 
    else {
        int len = vec[index].r - vec[index].l +1, levaya = left, pravaya = right;
        if(left < vec[index].l + len / 2 and right >= vec[index].l+ len / 2 ) {
            levaya  = vec[index].l + len / 2;
            pravaya = vec[index].l + len / 2 - 1;
        }
        change(2*index + 1, vec, left, pravaya, number );
        change(2*index + 2, vec, levaya, right, number );
        
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
    int count = 0 ;
    for( int i = 0 ; i < m ; i++ ) {
        cin >> s ;
        if( s == "m" ) {
            cin >> a >> b ;
            if(count == 0 ) {
                cout <<  obhod( 0, vec, a, b ) ; 
            }
            else {
              cout <<" " <<  obhod( 0, vec, a, b ) ; 
            }
             count++;
        }
        else {
            cin >> a >> b >> c;
            change(0, vec, a, b, c );
            
        }
    }
}

int main() {
   SAVCH_inc();
}
