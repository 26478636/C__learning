#include <iostream>
#include <string>
#include <cstring> //strlen()函数中会用到

using namespace std;

int main(){
    string s1, s2;
    
    s1="hello";
    s2="world";
    
    s1+=s2;
    cout<<"s1:"<<s1<<", 大小:"<<s1.size()<<endl;
    cout<<"s2:"<<s2<<", 大小:"<<s2.size()<<endl;

    cout<<"s1[0]="<<s1[0]<<endl;
    cout<<"s1[10]="<<s1[10]<<endl;
    cout<<"s1[11]="<<s1[11]<<endl;

    // s1[10]='H';
    // cout<<"s1:"<<s1<<", 大小"<<s1.size()<<endl;
    // cout<<"s1[10]="<<s1[10]<<endl;
    // cout<<"s1[11]="<<s1[11]<<endl;

    int n=100;
    while(n--){
        s1+="1";
    }

    cout<<"s1:"<<s1<<", 大小:"<<s1.size()<<endl;

    long start =clock();
    cout<<"size:"<<s1.size()<<", time:"<<clock()-start<<endl;

    start=clock();
    cout<<"strlen:"<<strlen(s1.c_str())<<", time:"<<clock()-start<<endl;

    return 0;
}