#include <iostream>

using namespace std;

class AbstractPerson{
public:
    virtual ~AbstractPerson(){}
};
class PersonA:public AbstractPerson{
public:
    void speakchinese(){
        cout<<"speakchinese"<<endl;
    }
};
class PersonB:public AbstractPerson{
public:
    void speakenglish(){
        cout<<"speakenglish"<<endl;
    }
};

template<class T>
void speak(T* t){
    if constexpr(std::is_same<T,PersonA>{}){
        t->speakchinese();
    }else{
        t->speakenglish();
    }
}

int main(){
    PersonA* A=new PersonA();
    PersonB* B=new PersonB();
    speak(A);
    speak(B);
    return 0;
}