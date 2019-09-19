#include <iostream>
using namespace std;

int partition(int arrayL[], int p, int r){
    int temp = 0;
    int x = arrayL[r];
    int i = (p-1);
    for (int j = p; j <= r-1 ;j++){
        if(arrayL[j] <= x){
            i++;
            temp = arrayL[i];
            arrayL[i] = arrayL[j];
            arrayL[j] = temp;
        }
    }
    temp = arrayL[i+1];
    arrayL[i+1] = arrayL[r];
    arrayL[r] = temp;
    return (i+1);
}
void quicksort(int array[], int p, int r){
    if(p < r){
        int q = partition(array, p, r);
        quicksort(array, p, q -      1);
        quicksort(array, q + 1, r);
    }
}


int main(){
    int t,n;
    cin >> t;
    if(t>10) return 0;
    while(t--){
        cin >> n;
        int array[n];
        for(int i=0;i<n;i++) cin >> array[i];
        quicksort(array,0,n-1);
        if(!array[n-1]%2) cout << array[n-1] + 2;
        else cout << array[n-1]+1; 
    }
    return 0;
}