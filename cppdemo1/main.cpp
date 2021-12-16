#include <iostream>
using namespace std;
class Test{
public:
    static int a;
    void Init() {
        cout << "Init:" << a << endl;
        a=1;
    }
    Test(int a=6) {
        Init();
        cout << Test::a << endl;
        Test::a++;
    }
};

int Test::a=0;
Test obj;

//int main() {
//    cout << "res = "<< obj.a<< endl;
//    return 0;
//}
