#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"队首元素："<<q.front()<<"，队尾元素："<<q.back()<<"，大小："<<q.size()<<endl;
    //弹栈
    q.pop();
    cout<<"队首元素："<<q.front()<<"，队尾元素："<<q.back()<<"，大小："<<q.size()<<endl;
    q.pop();
    cout<<"队首元素："<<q.front()<<"，队尾元素："<<q.back()<<"，大小："<<q.size()<<endl;
    q.pop();
    cout<<"队首元素："<<q.front()<<"，队尾元素："<<q.back()<<"，大小："<<q.size()<<endl;
    q.pop();
    cout<<"队首元素："<<q.front()<<"，队尾元素："<<q.back()<<"，大小："<<q.size()<<endl;
    q.pop();
    
    if(!q.empty()){
        cout<<"队首元素："<<q.front()<<"，队尾元素："<<q.back()<<"，大小："<<q.size()<<endl;
    }else{
        cout<<"结束弹栈"<<endl;
    };

    return 0;
}