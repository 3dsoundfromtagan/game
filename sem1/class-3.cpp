#include <iostream>
using namespace std;
class Lin{
  public:
   int cm; // сантиметры
   int mm; // миллиметры
};

void printLin(Lin a)
{
	cout << a.cm << " " << a.mm << endl;
}


Lin convertToLin(int kletki)
{
	Lin a;
	a.cm = kletki / 2;
	a.mm = (kletki % 2) * 5;
	return a;
}

int main ()
{
	int len = 0;
	cin >> len;
	Lin a = convertToLin(len);
	printLin(a);
	return 0;
}
