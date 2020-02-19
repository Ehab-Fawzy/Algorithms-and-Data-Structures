/// UVA:     10810

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long mergeSort( long long* a , int l , int r ){
    if ( l == r ){
        return 0;
    }

    int mid = (l + r) >> 1;
    long long returnValue = 0;
    returnValue += mergeSort(a , l , mid);
    returnValue += mergeSort(a , mid + 1 , r);

    int total = r - l + 1;
    long long * _copy = new long long[total];

    int result_iterator     = 0;
    int left_iterator       = l;
    int right_iterator      = mid + 1;

    while ( left_iterator <= mid && right_iterator <= r ){
        if ( a[left_iterator] < a[right_iterator] ){
            _copy[result_iterator] = a[left_iterator];
            left_iterator++; result_iterator++;
        }
        else{
            _copy[result_iterator] = a[right_iterator];
            returnValue += (mid - left_iterator + 1);
            right_iterator++; result_iterator++;
        }
    }

    while ( left_iterator <= mid ){
        _copy[result_iterator] = a[left_iterator];
        left_iterator++; result_iterator++;
    }

    while ( right_iterator <= r ){
        _copy[result_iterator] = a[right_iterator];
        right_iterator++; result_iterator++;
    }

    for ( int i = l; i <= r; ++i ){
        a[i] = _copy[i - l];
    }

    delete[] _copy;
    return returnValue;
}

/*
 *  O( N.log(N) )       Time Complexity
 *  O( N )              Memory Compexity
 */

long long CountInvMerge(long long* a, int n){
    long long* _copy = new long long[n];
    for ( int i = 0; i < n; ++i )
        _copy[i] = a[i];

    long long returnValue = mergeSort(_copy , 0 , n - 1);

    delete[] _copy;
    return returnValue;
}

/*
 *  O( N^2 )    Time Complexity
 *  O( 1 )      Memory Compexity
 */
long long CountInv(long long* a, int n){
    int counter = 0;
    for ( int i = 0; i < n; ++i ){
        for ( int j = i + 1; j < n; ++j ){
            if ( a[i] > a[j] ){
                counter++;
            }
        }
    }
    return counter;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n; long long *a;
    while ( cin >> n && n != 0 ){
        a = new long long[n];
        for ( int i = 0; i < n; ++i ){
            cin >> a[i];
        }

        cout << CountInvMerge(a , n) << "\n";
        delete[] a;
    }
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
