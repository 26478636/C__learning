#include <iostream>
#include <vector>
using namespace std;

namespace master{
    template<class T>
    class vector{
    private:
        T* _begin;
        T* _end;
        T* _capcity;
    public:
        //swap
        void swap(master::vector<T>& vec){
            std::swap(this->_begin,vec._begin);
            std::swap(this->_end,vec._end);
            std::swap(this->_capcity,vec._capcity);
        }
        //size() & capcity()
        size_t size() const{
            return _end-_begin;
        }
        size_t capcity() const{
            return _capcity-_begin;
        }
        //迭代器方法
        inline T* begin() {return _begin;}
        inline T* end() {return _end;}
        //判断是否扩容
        void reverse(size_t n,bool value=true){
            if(n>capcity()){
                T* p=nullptr;
                size_t count=size();
                if(_begin){
                    p=(T*)realloc(_begin,n*sizeof(T));
                    if(p==nullptr){
                        p=(T*)malloc(n*sizeof(T));
                        if(p==nullptr){
                            cout<<"失败"<<endl;
                        }
                        //拷贝到新地址
                        if(value){
                            for(size_t i=0;i<count;i++){
                            *(p+i)=*(_begin+i);
                            }
                        }
                        delete[] _begin;
                    }
                }else{
                    p=(T*)malloc(n*sizeof(T));
                }
                _begin=p;
                _end=p+count;
                _capcity=p+n;
            }
        }
    public:
        //构造函数
        vector():_begin(nullptr),_end(nullptr),_capcity(nullptr){}
        vector(size_t size,const T& value=T()):_begin(nullptr),_end(nullptr),_capcity(nullptr){
            reverse(size);
            while(size--){
                *_end=value;
                _end++;
            }
        }
        vector(const master::vector<T>& vec):_begin(nullptr),_end(nullptr),_capcity(nullptr){
            reverse(vec.capcity());
            for(size_t i=0;i<vec.size();i++){
                *_end=*(vec._begin+i);
                _end++;
            }
        }
        //移动构造
        vector(const master::vector<T>&& vec):_begin(nullptr),_end(nullptr),_capcity(nullptr){
            swap(vec);
        }
        //赋值构造
        master::vector<T>& operator=(const master::vector<T>& vec){
            reverse(vec.capcity(),false);
            _end=_begin;
            for(size_t i=0;i<vec.size();i++){
                *_end=*(_begin+i);
                _end++;
            }
            return *this;
        }
        master::vector<T>& operator=(const master::vector<T>&& vec){
            swap(vec);

            if(vec._begin) delete[] vec._begin;
            vec._begin=nullptr;
            vec._end=nullptr;
            vec._capcity=nullptr;
            return *this;
        }
        virtual ~vector(){
            if(_begin) delete[] _begin;
        }
        T& operator[](size_t index){
            return *(_begin+index);
        }
        void push_back(const T& value){
            if(_end==_capcity){
                size_t len=size();
                len=(len+1)*2;
                reverse(len);
            }
            *_end=value;
            _end++;
        }
        void pop_back(){
            if(_end>_begin){
                _end--;
            }
        }
    };
}

int main(){
    master::vector<int> arr1(10,2);
    for(auto i:arr1){
        cout<<i<<endl;
    }
    cout<<"----------"<<endl;
    arr1.push_back(1);
    arr1.pop_back();
    arr1.size();
    arr1.swap(arr1);
    cout<<arr1[0]<<endl;

    return 0;
}