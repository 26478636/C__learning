#include <iostream>
#include <functional>
using namespace std;

void test(int& n){
    n++;
    cout<<n<<endl;
}

int main(){
    int m=1;
    function<void()> func1=bind(&test,ref(m));
    func1();
    func1();
    return 0;
}