#ifndef SHARED_PTR
#define SHARED_PTR
#include<iostream>
#include<memory>
#include <atomic>

using std::cout;
using std::endl;
template <typename T>
class SharedPtr {
    public:
        SharedPtr(T* ptr = nullptr) : _p(ptr), _refCount(new size_t(1)){
            // cout << "this is SharedPtr(p)"<<endl;
        }
        template<typename U>
        SharedPtr(const std::shared_ptr<U>& ptr) : _p(ptr.get()), _refCount(new size_t(ptr.use_count())){
            if(_refCount){
                ++(*_refCount);
                // cout << "this is SharedPtr(make_s)"<<endl;
            }
        }
        
        //copy-ctor
        SharedPtr(const SharedPtr& sp) : _p(sp._p), _refCount(sp._refCount){
            if(_refCount){
                ++(*_refCount);
                // cout << "this is copy ctor"<<endl;
            }
        }


        ~SharedPtr(){ release(); }

        SharedPtr& operator=(const SharedPtr& sp){
            if(this !=&sp){
                release();

                _p = sp._p;
                _refCount = sp._refCount;
                if(_refCount){
                    ++(*_refCount);
                    // cout << "this is op ="<<endl;
                }
            }
            return *this;
        }
        size_t use_count() const{
            // cout << "*_refCnt = "<<*_refCount <<endl;
            return _refCount ? *_refCount : 0;
        }

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
            release();
            _p = nullptr;
            _refCount = nullptr;
        }
        template<typename U>
        void reset(U* ptr){
            release();
            _p = ptr;
            _refCount = new size_t(1);
        }
        explicit operator bool() const{
            return _p != nullptr;
        }

    private:
        void release(){
            if(_refCount && --(*_refCount)==0){
                delete _p;
                delete _refCount;
                _p = nullptr;
                _refCount = nullptr;
            }
        }

        T* _p;
        size_t* _refCount;
        // std::atomic<size_t>* _refCount;






};
template<typename T, typename... Args>
SharedPtr<T> make_shared(Args&&... args){
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}



#endif //SHARED_PTR