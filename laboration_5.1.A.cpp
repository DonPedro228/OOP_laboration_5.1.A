#include <iostream>
#include <string>
#include "Triangle.h"

using namespace std;


int main() {

    double a;
    cout << "Input a: "; cin >> a;
    double b;
    cout << "Input b: "; cin >> b;
    Triangle t_riangle(a, b);


    try {
        double hyp = t_riangle();
    }
    catch (const exception& e)
    {
        cerr << "Caught exception: " << e.what() << endl;
    }

    cout << "Triangle hypotenuse: " << t_riangle() << endl;
    cout << "Triangle info: " << endl;
    cout << t_riangle;

    return 0;

}