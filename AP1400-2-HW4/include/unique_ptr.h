#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include<iostream>
#include<memory>
using std::cout;
using std::endl;
// using std::make_unique;
template <typename T>
class UniquePtr {
    public:
        explicit UniquePtr(T* ptr = nullptr) : _p(ptr){}
        explicit UniquePtr(std::unique_ptr<T> ptr) : _p(ptr.release()){}

        // explicit UniquePtr() : _p(nullptr){}
        ~UniquePtr(){delete _p;}
        T* get(){
            return _p;
        }
        T operator*() const {
            return *_p;
        }
        T* operator->() const{
            return _p;
        }
        void reset(){
            delete _p;
            _p = nullptr;
        }
        template<typename U>
        void reset(U* ptr){
            delete _p;
            _p = ptr;
        }
        T* release(){
            T* releasePtr = _p;
            _p = nullptr;
            return releasePtr;
        }
        explicit operator bool() const{
            return _p != nullptr;
        }



    private:
        T* _p;
    // 类定义和成员函数声明/定义
    // 可以使用类型参数 T 作为模板参数
};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args){
    return std::make_unique<T>(std::forward<Args>(args)...);
}








#endif //UNIQUE_PTR