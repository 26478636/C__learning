#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int count1=count_if(arr,arr+9,bind2nd(greater<int>(),3));
    cout<<count1<<endl;
    int count2=count_if(arr,arr+9,bind1st(greater<int>(),3));
    cout<<count2<<endl;
    int count3=count_if(arr,arr+9,not1(bind1st(greater<int>(),3)));
    cout<<count3<<endl;
    return 0;
}
