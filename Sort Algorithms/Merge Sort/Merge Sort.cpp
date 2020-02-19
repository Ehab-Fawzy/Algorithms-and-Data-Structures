#include <iostream>
using namespace std;

template <class T>
void mergeSort( T* a , int l , int r ){
    if ( l == r ) return;

    int mid = (l + r) >> 1;
    mergeSort(a , l , mid);
    mergeSort(a , mid + 1 , r);

    int total = r - l + 1;
    T* _copy = new T[total];

    int iterator = 0 , leftIterator = l , rightIterator = mid + 1;
    while ( leftIterator <= mid && rightIterator <= r ){
        if ( a[leftIterator] < a[rightIterator] ){
            _copy[iterator++] = a[leftIterator++];
        }
        else{
            _copy[iterator++] = a[rightIterator++];
        }
    }
    while ( leftIterator <= mid ){
        _copy[iterator++] = a[leftIterator++];
    }
    while ( rightIterator <= r ){
        _copy[iterator++] = a[rightIterator++];
    }

    for ( int i = l; i <= r; ++i ){
        a[i] = _copy[i - l];
    }
    delete[] _copy;
    return;
}

template <class T>
void mergeSort( T* a , int n ){
    mergeSort(a , 0 , n - 1);
}

template <class T>
void mergeSort( T* a , T* b ){
    mergeSort(a , b - a);
}


int main(){

    int a[] = {5,8,6,1,7,4,-9,10,-7,6};
    mergeSort(a + 2 , a + 7);

    for ( int i = 0; i < 10; i++ )
        cout << a[i] << " ";
    return 0;
}