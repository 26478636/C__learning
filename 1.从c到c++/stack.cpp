#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"栈顶元素："<<s.top()<<"，大小："<<s.size()<<endl;
    s.pop();
    cout<<"栈顶元素："<<s.top()<<"，大小："<<s.size()<<endl;
    s.pop();
    cout<<"栈顶元素："<<s.top()<<"，大小："<<s.size()<<endl;
    s.pop();
    cout<<"栈顶元素："<<s.top()<<"，大小："<<s.size()<<endl;
    s.pop();
    cout<<"栈顶元素："<<s.top()<<"，大小："<<s.size()<<endl;
    s.pop();

    if(!s.empty()){
        cout<<"栈顶元素："<<s.top()<<"，大小："<<s.size()<<endl;
    }else{
        cout<<"弹栈结束"<<endl;
    }
    return 0;
};