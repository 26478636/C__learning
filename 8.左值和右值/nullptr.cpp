#include <iostream>

using namespace std;

void print(long a){
    cout<<"long"<<endl;
}

void print(void* a){
    cout<<"指针"<<endl;
}

int main(){
    cout<<typeid(NULL).name()<<endl;

    print(NULL);
    print(nullptr);

    cout<<typeid(nullptr).name()<<endl;

    return 0;
}