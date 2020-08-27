#include <iostream>
#include <vector>
#include <string>

#include "whattotest.h"
 
using namespace std;

 int main ()
 { 
    WidgetWithArrays * widget1 = new WidgetWithArrays();
    widget1->storeInteger(1);
    widget1->storeInteger(3);

    int sum1 = widget1->sum();
    cout << "sum1:"<<sum1 << " ";
    delete widget1;

    WidgetWithVector * widget2 = new WidgetWithVector();
    widget2->storeInteger(1);
    widget2->storeInteger(3);
    int sum2 = widget2->sum();
    cout << "sum2:"<<sum2 << " ";
    delete widget2;  

    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

}