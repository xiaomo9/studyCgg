#include <iostream>

using namespace std;

int main(void) 
{
    for (int i = 1; i < 10; i++)
    {
      if (i % 2 == 0)
      {
        continue;
      }
      cout << i << endl;
    }
    system("pause"); //pause the output
    return 0;
}