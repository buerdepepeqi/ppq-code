/*************************************************************************
 * @File Name: shared_ptr.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Mon Apr 14 00:52:10 2025
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <functional>

using namespace std;

template <typename T>
class SmartPoint{
    public:
        SmartPoint(T *ptr) {
            ref = ptr;
            ref_count = (unsigned*) malloc(sizeof(unsigned));
            *ref_count = 1;
            cout<<"xxxxx"<<endl;
        }

        SmartPoint(SmartPoint<T> &sptr) {
            ref = sptr.ref;
            ref_count = sptr.ref_count;
            *ref_count ++;
        }
        SmartPoint<T>& operator = (SmartPoint<T> &sptr) {
            if(this != &sptr) {
                if(--*ref_count == 0) {
                    clear();
                    cout <<"operator = clear" << endl;
                }
                ref = sptr.ref;
                ref_count = sptr.ref_count;
                *ref_count ++;
            }
            return *this;
        }
        ~SmartPoint(){
            if(--*ref_count == 0) {
                clear();
                cout <<"destructor clear" << endl;
            }
        }

        T getValue() {return *ref;}

    private:
        void clear() {
            delete ref;
            free(ref_count);
            ref = NULL;
            ref_count = NULL;
        }
        T* ref;
        unsigned *ref_count;

};

int main()
{
    int *ip1 = new int();
    *ip1 = 11111;
    int *ip2 = new int();
    *ip2 = 22222;
    SmartPoint<int> sp1(ip1), sp2(ip2);
    SmartPoint<int> spa = sp1;
    sp2 = spa; // 注释掉它将得到不同输出
    return 0;
}

