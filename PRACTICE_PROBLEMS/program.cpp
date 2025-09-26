# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

class M{
    int x;
    int y;
    public:
        void set_xy(int a,int b){
            x=a;
            y=b;
        }
        friend int sum(M m);
};

int sum(M m){
    int M::*m_x=&M::x;
    int M::*m_y=&M::y;
    M *pm=&m;
    int sum=m.*m_x + pm->*m_y;
    return sum; 
}

int main(){
    M m1;
    void (M :: *p_f)(int,int)=&M::set_xy;
    (m1.*p_f)(2,7);
    cout<<"Sum: "<<sum(m1)<<endl;
    M *p_o=&m1;

    (p_o->*p_f)(30,40);
    cout<<"Sum: "<<sum(m1)<<endl;
    return 0;
}