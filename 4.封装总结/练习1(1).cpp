#include <iostream>

using namespace std;

//定义数据类型
struct MemIO{
    void* ptr;
    size_t size;
};

int count=0;
MemIO arr[100];

//定义 class A
class A{
public:
    A(){
        cout<<"默认构造函数"<<endl;
    }
    ~A(){
        cout<<"析构函数"<<endl;
    }
};

//操作符重载
void* operator new(size_t size){
    cout<<"开辟内存空间"<<endl;
    void* a1=malloc(size);
    arr[count]=MemIO{a1,size};
    count++;
    return a1;
}

void operator delete(void* p){
    for(int i=0;i<100;i++){
        if(arr[i].ptr==p){
            arr[i].size=0;
        }
    }
    if(p){
        free(p);
    }
}

int main(){
    A* a1=new A();
    int* a2=new int(3);
    delete a1;
    
    size_t size=0;
    for(auto it:arr){
        if(it.size!=0){
            size+=it.size;
            cout<<it.size<<"..."<<it.ptr<<endl;
        }
    }
    cout<<size<<endl;
    return 0;
}