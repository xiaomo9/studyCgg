#include <iostream>
using namespace std;

int main(void) 
{
    for(int i=0; i<100; i++) 
    {
        if (i%7 == 0 or i%10 == 7 or i/10==7)
        {
             cout << "ÇÃ×À×Ó" << endl;
        } 
        else
        {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}
