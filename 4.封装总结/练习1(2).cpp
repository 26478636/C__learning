#include <iostream>
#include <cstring>
using namespace std;

struct MemIO{
    void* ptr;
    size_t size;
    char file[100];//文件夹名
    size_t line;//行号
};
int count=0;
MemIO arr[100];

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
void* operator new(size_t size,const char* file,size_t line){
    cout<<"开辟内存空间"<<endl;
    void* p=malloc(size);
    arr[count].ptr=p;
    arr[count].size=size;
    strcpy(arr[count].file,file);
    arr[count].line=line;
    count++;
    return p;
}
void

int main(){

    return 0;
}