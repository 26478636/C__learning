#include <iostream>
#include <algorithm>

using namespace std;

//创建仿函数
struct A{
    int _min,_max;
    A(int min,int max):_min(min),_max(max){}

    //仿函数
    A& operator()(int n){
        if(n>=_min&&n<=_max){
            cout<<"n= "<<n<<endl;
        }
        return *this;
    }
    A& operator()(const char* s){
        cout<<"s= "<<s<<endl;
        return *this;
    }
};

//判断大小
bool check_one(int n){
    if(n<=50){
        return true;
    }else{
        return false;
    }
}

//判断大小--仿函数
struct check_two{
    int _min,_max;
    check_two(int min,int max):_min(min),_max(max){}

    bool operator()(int n){
        if(n>=_min&&n<=_max){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    //定义一个类
    A a(1,100);
    a(11)(22)("nihaoya")(101)("\n");
    //<=50
    int arr[]={1,99,33,55,102,90,0,89,90,10};
    int count1=count_if(arr,arr+10,check_one);
    cout<<"count1: "<<count1<<endl;
    //<=50 使用仿函数
    int count2=count_if(arr,arr+10,check_two(0,50));
    cout<<"count2: "<<count2<<endl;

    return 0;
}