#include <iostream>

using namespace std;


void heapify(int arr[], int barr[], int n, int i)
{
    int largest = i;   

    int l = 2*i + 1;  
    int r = 2*i + 2; 


    if (l < n && arr[l] > arr[largest])
        largest = l;

   
    if (r < n && arr[r] > arr[largest])
        largest = r;

   
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swap(barr[i], barr[largest]);


        heapify(arr, barr, n, largest);
    }
}

void heapSort(int arr[], int barr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, barr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        swap(barr[0], barr[i]);
        heapify(arr, barr,  i, 0);
    }
}
int binpoisk(int num, int arr[], int len) {
    int l=0, r=len-1, midle;
    while(l<=r) {
        midle=(l+r)/2;
        if(arr[midle]==num) {
            return midle;
        }
        if(arr[midle]>num) {
            r=midle-1;
            continue;
        }
        else {
            l=midle+1;
        }
    }
    cout<<"Ошибка, индекс не найден";
    return -1;
}
void count( int arr[], int barr[], int len) {
    int k, pred, K, L, counter=0, sled;
    cin>>k;
    cin>>K;
    pred=binpoisk(K, arr, len);
    for (int i=1; i<k; i++) {
        cin>>L;
        sled=binpoisk(L, arr, len);
        if(barr[sled]!=barr[pred]) {
            counter++;
        }
        pred=sled;
   //     K=L;
    }
    
    
    
    cout<<counter;
}

int main() {
    int n, l, i, k,arr[n+1], barr[n+1] ;
    cin>>n;
    for (i=0; i<n; i++){
        cin>>l;
        arr[i]=l;
    }
    for (i=0; i<n; i++){
        cin>>l;
        barr[i]=l;
    }
    heapSort(arr, barr, n);
    /*for (i=0; i<n; i++){
        cout<<arr[i]<<" ";
       
    }
    for (i=0; i<n; i++){
        cout<<barr[i]<<" ";
    }*/
    count(arr, barr, n);
    return 0;
}
