/*
  В начале программы директивы препроцессора
*/
// Начало мантры

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
// Конец директив и выбора пространства имён

class Time{
  public:
   int hour;
   int min;
};

  Time add(Time a, int min){
    while ((a.min + min) >= 60)
    {
        min -= 60;
        a.hour++;
        if (a.hour >= 24)
        {
            a.hour -= 24;
        }

    }
    a.min += min % 60;
    a.hour += min / 60;
    return a;
}


int main() {
    Time a,newtime;
    int min;
    
    // Получить a  из консоли 


    cin>>a.hour>>a.min;
   // Получить min  из консоли 

    cin>>min;
    newtime = add(a,min);
    cout << newtime.hour << ":" << newtime.min << endl;
}
