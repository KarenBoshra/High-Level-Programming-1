#include "std_lib_facilities.h"

template<typename T>
struct S {
private:
    T val;
public:
    S(T vv = 0)  : val{vv} {}

    T&get();
    const T& get() const;

    //void set(T new_t) { val = new_t; }
    S& operator=(const T&);
};

template<typename T>
T& S<T>::get() 
{ 
    return val; 
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v)
{
    os << '{';
    for (int i = 0; i < v.size(); ++i)
        os << v[i] << (i < v.size() - 1 ? ", " : "");

    os << "}\n";

    return os;
}

template<typename T>
istream& operator << (istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if(ch != '{')
    {
        is.unget();
        return is;
    }

    for (T val; is >> val; )
    {
        v.push.back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

template<typename T>
void read_val(T& v)
{
    cin >> v;
}

int main() 
{
    S<int> intVal {5};
    S<char> charVal {'C'};
    S<double> doubleVal {6.6};
    S<string> stringVal {"Hello"};
    S<vector<int>> vectorVal = {vector<int>{10, 20, 30}};  

    cout << "S<int> : " << intVal.get() << '\n'
         << "S<char> : " << charVal.get() << '\n'
         << "S<double> : " << doubleVal.get() << '\n'
         << "S<string> : " << stringVal.get() << '\n'
         << "S<vector<int>> : " << vectorVal.get() << '\n';
    

    return 0;
}
