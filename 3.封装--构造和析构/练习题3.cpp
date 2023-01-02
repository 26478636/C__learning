#include <iostream>
#include <string>
#include <vector>

using namespace std;

//图书类 CBook
class CBook{
    //成员属性
    private:
    string _name;
    int _price;
    //有参构造函数
    public:
    CBook(const char* name,int price):_name(name),_price(price){

    }
    inline string name(){return _name;}
    virtual string desc()=0;
};

//计算机图书类 CComputer
class CComputer:public CBook{
    //成员属性
    private:
    string _desc;
    //有参构造函数
    public:
    CComputer(const char* name,int price,const char* desc):CBook(name,price),_desc(desc){

    }
    string desc(){return _desc;}
};

//历史图书类 CHistory
class CHistory:public CBook{
    //成员属性
    private:
    string _date;
    //有参构造函数
    public:
    CHistory(const char* name,int price,const char* date):CBook(name,price),_date(date){

    }
    string desc(){return _date;}
};

//图书管理类　CLib
class CLib{
    //成员属性
    private:
    vector<CBook*> library;
    //有参构造函数
    public:
    void addBooks(CBook* book){
        library.push_back(book);
    }
    void listBooks(){
        for(auto book:library){
            cout<<book->name()<<"..."<<book->desc()<<endl;
        }
    }
};

int main(){
    CLib lib;
    lib.addBooks(new CComputer("c++",22,"c++__hh"));
    lib.addBooks(new CComputer("cyuyan",23,"cyuyan__hh"));
    lib.addBooks(new CHistory("zhongguo",50,"zhongguo__hh"));
    lib.addBooks(new CHistory("shijie",51,"shijie__hh"));
    cout<<"____________________________________________"<<endl;
    lib.listBooks();
    return 0;
}