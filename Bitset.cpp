/* Игра в трёхмерные шахматы ведется на кубическом поле N×N×N. Трёхмерная ладья может ходить на любое число клеток по прямой в любом из шести направлений (в любую сторону в каждом из трёх направлений).
На таком поле расставлены K ладей. Напишите программу, которая определит, бьют они всё поле или нет. */

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


void SAVCH_inc() {
  int n, k;
  cin >> n >> k;
  int a, b, c;
  vector<ull> power_2(64, 1);
  for( int i = 1 ; i < 64; i++ ) {
      power_2[i] = 2 * power_2[i-1];
  }
  
  vector<vector<bool>> xy( n, vector< bool> (n, true ) );
  vector<vector<ull> > xz( n, vector< ull > ( (n+63)/64 ,0) );
  vector<vector<ull> > yz( n, vector< ull > ( (n+63)/64 ,0) );
  for( int i = 0 ; i < k; i++ ) {
      cin >> a >> b >> c;         //КООРДИНАТУ C БУДЕМ НА БИТЫ РЕЗАТЬ В БИТСЕТЕ
      a--;
      b--;
      c--;
      xy[a][b]=false;
      ull aboba_1 = xz[a][c/64] &  power_2[c%64];
      ull aboba_2 = yz[b][c/64] & power_2[c%64];
      if( aboba_1 == 0 ) {
          xz[a][c/64] += power_2[c%64];
      }    
      if( aboba_2== 0 ) {
          yz[b][c/64] += power_2[c%64];
      }
      
      
  }
  ull ostatok = 0, all=0 ;
  for( int i = 0 ; i < n%64; i++ ) {
      ostatok+=power_2[i];
  }
  for( int i = 0 ; i < 64; i++ ) {
      all+=power_2[i];
  }
  for( int i = 0 ; i < n; i++) {
      for( int j = 0 ; j < n; j++ ) {
          if(xy[i][j] ) {
              for( int h = 0 ; h < (n+63)/64; h++ ) {
                  ull num = all;
                  if(n % 64 != 0 and h == (n+63)/64 -1 ) {
                      num = ostatok;
                  }
                  ull aboba_3 = yz[j][h] ^ num;
                  ull aboba_4 = xz[i][h] ^ num;
                  
                  if( aboba_3 != 0 and aboba_4 != 0 ) {
                      int ans = 0;
                      int predel = n% 64;
                      if(predel == 0 ) {
                        predel = 64;
                      }
                      for( int r = 0 ; r <  predel; r++) {  
                          ull res_1 = yz[j][h] & power_2[r];
                          ull res_2 = xz[i][h] & power_2[r];
                          if( res_1 == 0 and res_2 == 0 ) {
                              ans = h*64+r+1;
                              cout<<"NO "<< i+1 << " " << j + 1 << " " << ans << endl; 
                              return;
                          }
                      }
                    
                  }
              }
          }
          
      }
  }
  cout<<"YES"<<endl;
}

int main() {
   SAVCH_inc();
}
