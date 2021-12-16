//
// Created by Lenovo on 2021/10/16.
//
#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double image;

public:
    Complex(double r,double i) : real(r),image(i) {
        cout << "Complex(double r,double i)"<< endl;
    }
    Complex() : real(0),image(0) {
        cout << "Complex()"<< endl;
    }

    Complex(const Complex& c) {
        cout << "拷贝构造"<< endl;
    }

    ~Complex(){
        cout << "析构"<< endl;

    }

    void Show() const;

//    static Complex Add(const Complex& z1,const Complex& z2);

    Complex operator+ (const Complex& z2) {
        Complex tmp;
//    z = Complex(z1.real + z2.real, z1.image + z2.image);
        tmp.real = real + z2.real;
        tmp.image = image + z2.image;
        cout << "tmp:" << &tmp << endl;
        return tmp;
    }

    Complex& operator= (const Complex& x) {
        cout << "operator=" << endl;
        cout << "x:" << &x << endl;
        if(this != &x) {
            real = x.real;
            image = x.image;
        }
        return *this;
    }
};

void Complex::Show() const {
    if(image<0) {
        cout << real << image << "i"<< endl;
    } else if(image == 0) {
        cout << real << endl;
    } else {
        cout << real << "+" << image << "i" << endl;
    }
}

//Complex Complex::Add(const Complex &z1, const Complex &z2)
//{
//    Complex tmp;
////    z = Complex(z1.real + z2.real, z1.image + z2.image);
//    tmp.real = z1.real + z2.real;
//    tmp.image = z1.image + z2.image;
//    cout << "tmp:" << &tmp << endl;
//    return tmp;
//}

int main()
{
    Complex z1(2,3),z2(6,-5); // z1,z2调用有参构造
    z1.Show();
    z2.Show();
    Complex z3;
    z3 = z1+z2; // 自动做=号运算符重载
//    cout << "z3:" << &z3 << endl;

    z3.Show();
//    Complex z4=z3;
//    z4.Show();
    return 0;
}


