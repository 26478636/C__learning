#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
//整数反转
int a1=12345678;
string a2=to_string(a1);
reverse(a2.begin(),a2.end());
a1=atoi(a2.c_str());
cout<<"结果："<<a1<<endl;

//回文判断
string a3="123454321";
string a4=a3;
reverse(a4.begin(),a4.end());
if(a3==a4){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}

//排序
int arr[]={12,4,7,35,75,88,55,9,4,67};
int len=sizeof(arr)/sizeof(int);
sort(arr,arr+len,greater<int>());
for(auto i: arr){
    cout<<i<<" ";
}
cout<<endl;

return 0;
}