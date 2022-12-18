#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    unordered_map<string, int> hashmap;
    
    //赋值
    hashmap["ab"]=12;
    hashmap["abc"]=123;
    hashmap["abcd"]=1234;
    hashmap["abcde"]=12345;
    hashmap["abcdef"]=123456;

    //输出size
    cout<<"大小-----"<<hashmap.size()<<endl;

    //查询是否有k值
    auto it=hashmap.find("adc");
    if(it!=hashmap.end()){
        cout<<"value-----"<<hashmap["adc"]<<endl;
    }else{
        cout<<"nothing!!!!"<<endl;
    }

    //迭代器遍历
    for(auto i=hashmap.begin();i!=hashmap.end();i++){
        cout<<"key-----"<<i->first<<"value-----"<<i->second<<endl;
    }

    return 0;
}