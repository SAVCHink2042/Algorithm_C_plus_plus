/* Запросы таковы:

<<QUERY l r>> — найти длину максимальной последовательности из нулей на отрезке с l по r
<<UPDATE i x>> — обновить i-ый элемент массива значением x */ 

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
  int l, r, num= 0, len_pref=0, len_suf=0;
  bool flag = false;  //СОСТОИТ ЛИ ИЗ НУЛЕЙ ДАННЫЙ ОТРЕЗОК
};

int find_size(int n ) {
    int k = 1;
    while(k < n ) {
        k = 2*k;
    }
    return k;
}

void input(vector<Data> &vec, int n, int size ) {  //треш какой-то 
    for( int i = size-1 ; i < 2 * size - 1; i++  ) {
        if(i -size +1 < n ) {
            cin >> vec[i].num;
            if(vec[i].num == 0 ) {
                vec[i].num = 1;
                vec[i].flag = true;
                vec[i].len_suf = 1;
                vec[i].len_pref = 1;
            }
            else {
              vec[i].num = 0;
            }
        }
        vec[i].l = i - size + 2;
        vec[i].r = i - size + 2;
        
    }
    for( int i = size -2 ; i > -1 ; i-- ) {            
        vec[i].l = vec[2*i+1].l;
        vec[i].r = vec[2*i+2].r;
        vec[i].num = max( vec[2*i+1].num, max( vec[2*i+2].num, vec[2*i+1].len_suf + vec[2*i+2].len_pref ) ) ;
        if(vec[2*i+2].flag ) {                        //пересчет суффикса
            vec[i].len_suf = vec[2*i+1].len_suf + vec[2*i+2].num; 
        } 
        else {
            vec[i].len_suf = vec[2*i+2].len_suf;
        }                           
        if(vec[2*i+1].flag  ) {                        //пересчет преффикса
            vec[i].len_pref = vec[2*i+2].len_pref + vec[2*i+1].num;
        }
        else {
          vec[i].len_pref = vec[2*i+1].len_pref;
        }
        if(vec[i].num == vec[i].r - vec[i].l + 1 ) {     //проверка пересчета флага 
            vec[i].flag = true;
        }
    }
} 


// vector<int> возвращает три числа первое - максимум из нулей. второе - длина нулевого преффикса, третье - длина нулевого суффикса
vector<int>  obhod(int index, const vector<Data> &vec, int left, int right) {
    vector< int > ans( 3, 0 );
    if(vec[index].l == left and vec[index].r == right ) {
        ans[0] = vec[index].num;
        ans[1] = vec[index].len_pref;
        ans[2] = vec[index].len_suf;
        return ans;
    }
    else if(vec[index].l > right or vec[index].r < left  ) {
        return ans;
    }
    else {
       int len= vec[index].r-vec[index].l + 1, pravaya = right, levaya = left;
       vector< int > p1, p2;
       if( left < vec[index].l+len/2 and right >= vec[index].l+len/2 ) {
          levaya  = vec[index].l + len / 2; 
          pravaya = vec[index].l + len / 2 - 1;
       }
       p1 = obhod(2*index + 1, vec, left, pravaya);     //ЛЕВЫЙ СЫН
       p2 = obhod(2*index + 2, vec, levaya, right);     //ПРАВЫЙ СЫН
       
       ans[0] = max( p1[0], max( p2[0], p1[2]+p2[1] ) ); // ПЕРЕСЧЕТ МАКСИМУМА НА ОТРЕЗКЕж
       if( vec[2*index + 1].flag ) {                   //ПЕРЕСЧЕТ ПРЕФФИКСА Я УСТАЛ УЖЕ ЭТИ ПРОГИ ПИСАТь ДАЙТЕ ХОТЬ 
          ans[1] = p1[0] + p2[1];
       }
       else {
         ans[1] = p1[1];
       }
       if( vec[2*index + 2].flag ) {                                          //ПЕРЕСЧЕТ СУФФИКСА Я УСТАЛ ЭТИ ПРОГИ ПИСАТЬ УЖЕ
          ans[2] = p2[0] + p1[2];  
       }
       else {
          ans[2] = p2[2];
       }
        return ans;
    }
}

void change(vector<Data> &vec, int index_upg, const int& new_number) {
    int flagshtop = 0;
    if( new_number == 0 and vec[index_upg].num == 0 ) {
        flagshtop = 1;
        vec[index_upg].num = 1;
        vec[index_upg].len_pref = 1;
        vec[index_upg].len_suf = 1;
        vec[index_upg].flag = true;
    }
    else if( new_number != 0 and vec[index_upg].num != 0 ) {
        flagshtop = 1;
        vec[index_upg].num = 0;
        vec[index_upg].len_suf = 0;
        vec[index_upg].len_pref = 0;
        vec[index_upg].flag = false;
    }
    if( flagshtop ) {
        int i = index_upg;
        while(i != 0 ) {
            i = (i-1) / 2;
            vec[i].num = max(vec[2*i+1].num, max( vec[2*i+2].num, vec[2*i+1].len_suf+ vec[2*i+2].len_pref ) ) ;
            if(vec[2*i+2].flag ) {                        //пересчет суффикса
                vec[i].len_suf = vec[2*i+1].len_suf + vec[2*i+2].num; 
            } 
            else {
                vec[i].len_suf = vec[2*i+2].len_suf;
            }                           
            if(vec[2*i+1].flag  ) {                        //пересчет преффикса
                vec[i].len_pref = vec[2*i+2].len_pref + vec[2*i+1].num;
            }
            else {
              vec[i].len_pref = vec[2*i+1].len_pref;
            }
            if( vec[i].num == vec[i].r - vec[i].l + 1) {     //проверка пересчета флага 
                vec[i].flag = true;
            }
            else {
              vec[i].flag = false;
            }
        }
    }
}

void SAVCH_inc() {
    int n, k;
    cin >> n ;
    
    int size = find_size(n);
    vector< Data > vec(2*size -1 ); 
    input(vec, n, size);
    int b, c;
    string a;
    cin >> k;
    for( int i = 0 ; i< k ; i++ ) {
        cin >> a >> b >> c;
        if(a == "UPDATE" ) {           
            change(vec, size + b - 2, c);
        }
        else {
          vector< int> ans(3);
          ans =obhod(0, vec, b, c);
          cout<< ans[0]  << endl;
        }
    }
}

int main() {
   SAVCH_inc();
}
