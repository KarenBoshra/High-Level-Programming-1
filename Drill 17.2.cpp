#include "std_lib_facilities.h"

ostream& print_array(ostream& os, int* a, int n)
{
    for(int i = 0; i<n; ++i) os<<a[i]<<"\n";
    return os;
}

int main(){

    //q.1
    int x= 7;
    int* p1= &x;

    //q.2
    cout<< "pointer "<<p1<<" points to "<<*p1<<"\n";

    //q.3
    int* p2= new int[7];
    x=1;
    for(int i=0; i<7; ++i){
        p2[i]=x;
        x*=2;
    }

    //q.4
    cout<<"address "<<p2<<"\n";
    for(int j= 0; j<7; ++j)
        cout<<p2[j]<<"\t";

    cout<<"\n\n";

    //q.5,6,7
    int* p3= p2;
    p2=p1;
    p2=p3;

    //q.8
    cout<< "pointer "<<p1<<" points to "<<*p1<<"\n";
    cout<< "pointer "<<p2<<" points to "<<*p2<<"\n";

    //q.9
    delete[] p2;

    //q.10
    p1= new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2= new int[10];

    //q.12
    for(int m=0; m<10; ++m)
        p2[m]= p1[m];

    for(int k= 0; k<10; ++k)
        cout<<p2[k]<<"\t";
    cout<<"\n\n";

    //q.13
    vector<int> v1 {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> v2 (10);
    v2=v1;

    cout<<"vector form\n"; //just for making it clear
    for(int v: v2) cout<<v<<"\t";
    cout<<"\n";
}
