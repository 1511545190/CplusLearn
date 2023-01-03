#include <iostream>
using namespace std;

#include <vector>
template<class T>
class Desk{
    private:
        T height;
        T width;
        T id;
    public:
        //为了能够输出<< dk
        friend ostream& operator << (ostream& out,const Desk<T> &desk);
        Desk(T height,
        T width,
        T id);

};

template <class T>
Desk<T>::Desk(T height, T width, T id)
{
    
}
template <class T>
ostream & operator<<(ostream &out, const Desk<T> &desk)
{
    out<<desk.width<<desk.id;
    
    
    return out;
}
