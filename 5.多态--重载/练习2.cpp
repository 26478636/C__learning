#include <iostream>
#include <cstring>

using namespace std;

//定义类 MyString
class MyString{
    //成员属性
    private:
    char* _data;
    unsigned long _length;
    unsigned long _capcity;
    //输出功能
    friend ostream& operator<<(ostream& os,const MyString& s){
        for(int i=0;i<s._length;i++){
            os<<s._data[i]<<",";
        }
        return os;
    }
    //四大构造函数
    public:
    MyString():_data(nullptr),_length(0),_capcity(0){};
    MyString(const char* s){
        _length=strlen(s);
        _capcity=_length+1;
        _data=new char[_capcity];
        strncpy(_data,s,_length);
        _data[_length]='\0';
    }
    MyString(const MyString& s){
        if(&s==this) return;
        _length=s._length;
        _capcity=s._capcity;
        _data=new char[_capcity];
        strncpy(_data,s._data,_length);
        _data[_length]='\0';
    }
    MyString& operator=(const MyString& s){
        if(&s==this) return *this;
        if(_data){
            delete[] _data;
        }
        _length=s._length;
        _capcity=s._capcity;
        _data=new char[_capcity];
        strncpy(_data,s._data,_length);
        _data[_length]='\0';
        return *this;
    }
    //功能函数
    //s+="345"-----const char* s
    //考虑到是否需要扩容 
    MyString& operator+=(const char* s){
        size_t size=strlen(s);
        if(_data){
            if(_length+size<_capcity){
                _length+=size;
                strncpy(_data+_length,s,size);
                _data[_length]='\0';
            }
            else{
                size_t newsize=2*(_length+size);
                char* p=(char*)realloc(_data,newsize);
                if(p){
                    _data=p;
                    _length+=size;
                    _capcity=newsize;
                    strncpy(_data+_length,s,size);
                    _data[_length]='\0';
                }
                else{
                size_t newsize2=2*(_length+size);
                char* q=(char*)realloc(_data,newsize2);
                strncpy(q,_data,_length);
                strncpy(q+_length,s,size);
                _length+=size;
                _capcity=newsize2;
                delete[] _data;
                _data=q;
                _data[_length]='\0';
                }
            } 
        }
        else{
            _length=strlen(s);
            _capcity=_length+1;
            _data=(char*)malloc(_capcity);
            strncpy(_data,s,_length);
            _data[_length]='\0';
        }
        return *this;
    }
    //s1+=s2
    //const MyString& s
    MyString& operator+=(const MyString& s){
        char* p=s._data;
        return operator+=(p);
    }
    //[]
    char& operator[](size_t index){
        return _data[index];
    }
    //s1+"456"
    MyString operator+(const char* s){
        MyString ret{*this};
        ret+=s;
        return ret;
    }
    //s1+s2
    MyString operator+(const MyString& s){
        MyString ret{*this};
        ret+=s;
        return ret;
    }
};

int main(){
    MyString s1{"123"};
    MyString s2{"456"};
    cout<<s1<<endl;
    cout<<s2<<endl;

    s1+="456";
    cout<<s1<<endl;

    s1[1]='9';
    cout<<s1<<endl;
    s1[16]='9';
    cout<<s1<<endl;

    cout<<(s1+s2)<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    return 0;
}