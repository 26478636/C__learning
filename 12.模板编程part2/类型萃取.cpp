//迭代器求和&&&&数组求和
#include <iostream>
#include <vector>

using namespace std;

//类型萃取
template<typename iter>
class type_tt{
public:
    using value_type=typename iter::value_type;
};
template<typename iter>
class type_tt<iter*>{
public:
    using value_type=iter;
};

template<typename iter>//迭代器类型
typename type_tt<iter>::value_type My_Sum(iter begin,iter end){
    typename type_tt<iter>::value_type ret{0};
    for(iter i=begin;i!=end;i++){
        ret+=*i;
    }
    return ret;
}

int main(){
    vector<int> arr1;
    for(int i=0;i<=10;i++){
        arr1.push_back(i);
    }
    int arr2[]={0,1,2,3,4,5,6,7,8,9,10};
    cout<<My_Sum(arr1.begin(),arr1.end())<<endl;
    cout<<My_Sum(arr2,arr2+11)<<endl;
    return 0;
}