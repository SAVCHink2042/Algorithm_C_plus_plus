/* Первая строка входного файла содержит два целых числа 

N и K — количество чисел в массиве и количество запросов 
 Следующие K строк содержат следующие запросы:
A i x — присвоить  i-му элементу массива значение  x
Q l r — найти сумму чисел в массиве на позициях от 
Изначально в массиве нули. */

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


void update( vector< lli> & protocol, vector< lli>& vec, lli n, lli a, lli b ) {   //a - индекс, b - новое число 
 lli index = a;
  while(a < n ) {
      vec[a] = vec[a] - protocol[index] + b;
      a = a | (a+1);
  }
  protocol[index] = b;
}

lli sum_pref( vector< lli> &vec, lli l ) {
    lli ans = 0;
    while( l >= 0 ) {
        ans += vec[l];
        l = l & (l+1) ;
        l -= 1;
    }
    return ans;
}

void SAVCH_inc() {
  lli n, k, a, b;
  string s;
  cin >> n >> k;
  vector<lli> vec(n, 0 ), protocol(n, 0);
  for( int i = 0 ; i < k ; i++ ) {
      cin >> s >> a >> b;
      if( s =="A" ) {
        update(protocol, vec, n, a-1, b);
      }
      else {
          cout<< sum_pref(vec,  b-1) - sum_pref(vec,  a -1 -1 )<<endl; 
      }
  }
}


int main() {
   SAVCH_inc();
}




