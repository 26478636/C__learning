#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    //奇数
    int count1=count_if(arr,arr+9,[](int n){return n%2;});
    cout<<count1<<endl;
    int count2=count_if(arr,arr+9,bind2nd(modulus<int>(),2));
    cout<<count2<<endl;
    return 0;
}