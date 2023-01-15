#include <iostream>
using namespace std;

typedef char arr[10];

int getsize(int n){
    return n*2;
}

int main(){
    char arr1[sizeof(arr)];
    char arr2[getsize(5)];
    cout<<sizeof(arr1)<<endl;
    cout<<sizeof(arr2)<<endl;
    return 0;
}