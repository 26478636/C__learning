#include <iostream>
using namespace std;

//重载new
void* operator new(size_t size){//操作符重载 size 开辟内存空间的大小
    cout<<"创建内存空间"<<endl;
    void* p=malloc(size);
    return p;
}
//重载delete
void operator delete(void* p){//操作符重载 
    cout<<"删除内存空间"<<endl;
    if(p){
        free(p);
    }
}

class A{
public:
    A(){
        cout<<"默认构造"<<endl;
    }
    ~A(){
        cout<<"析构函数"<<endl;
    }
};

char arr[100];
int main(){
    A* a1=new A();
    delete a1;

    A* a2=new(arr) A();
    A* a3=new(arr+sizeof(A)) A();
    return 0;
}