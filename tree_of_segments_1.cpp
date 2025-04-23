/* Реализуйте структуру данных, которая на данном массиве из N
целых чисел позволяет узнать максимальное значение на этом массиве и индекс элемента, на котором достигается это максимальное значение. */

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
    int ind = 1;   // индекс максимума 
};

void input(vector<Data> &vec, const int &size, const int &n) {
    for (int i = size - 1; i < 2*size -1 ; i++) {
        if( i - size + 1 < n) {
          cin >> vec[i].num ;  
        }
        vec[i].l = i - size + 2;
        vec[i].r = i - size + 2;
        vec[i].ind = i-size + 2;
    }
    for( int i = size - 2; i > -1; i-- ) {
        if(vec[2*i+1].num == vec[2*i+2].num ) {
            vec[i] = { vec[2*i+1].l, vec[2*i+2].r, vec[2*i+1].num, vec[2*i+1].ind };
        }
        else {
          int index;
          if(vec[2*i+1].num > vec[2*i+2].num ) {
              index = 2*i+1;
          }
          else {
              index = 2*i+2;
          }
          vec[i] = { vec[2*i+1].l, vec[2*i+2].r, vec[index].num, vec[index].ind } ;
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
 
pair<int,int> obhod (int index, int left, int right,const vector<Data>& vec ) {
   // cout<<"АБОБА " <<left << " "<< right << endl;
    if( vec[index].l == left and vec[index].r == right)  { 
        return { vec[index].num, vec[index].ind };
    }
    else if( vec[index].r < left or  vec[index].l > right ) {                   //left , right -границы заданного промежутка 
        return { INT_MIN, INT_MIN };
    }
    else {
        pair<int, int > p1, p2;
        int pravaya=right, levaya=left, len = vec[index].r-vec[index].l + 1;

        if( left < vec[index].l +len/2 and right >= vec[index].l+len/2  ) {
            levaya = vec[index].l+len/2;
            pravaya = vec[index].l+len/2-1;
        }
        p1 = obhod( 2*index+1, left, pravaya, vec);  // левый  
        p2 = obhod( 2*index+2, levaya , right, vec);  // правый
        if(p1.first == p2.first ) {
            return {p1.first, p1.second};
        }
        else if(p1.first > p2.first ) {
            return p1;
        }
        else {
            return p2;
        }
    }
}

void SAVCH_inc() {
    int n, k, left, right;
    cin >> n;
    int size = find_size(n);
    vector<Data> vec(2 * size - 1);
    
    input(vec, size, n);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> left >> right;
        pair<int, int > ans;
        ans = obhod( 0, left , right, vec );
        cout<< ans.first << " "<< ans.second << endl;
    }
   
}

int main() {
    SAVCH_inc();
}
