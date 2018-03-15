#include <iostream>
#include <ctime>

using namespace std;

class Stopwatch {
	double begin;
	double end;
public:
	Stopwatch();
	~Stopwatch();
	void start();
	void stop();
	void show();
	
};

Stopwatch::Stopwatch() {
	cout << "Creating object Stopwatch..." << endl;
	begin = end = 0.0;
}

Stopwatch::~Stopwatch() {
	cout << "Deleting object Stopwatch..." << endl;
	show();
}

void Stopwatch::start() {
	begin = (double) clock()/CLOCKS_PER_SEC;
}

void Stopwatch::stop() {
	end = (double) clock()/CLOCKS_PER_SEC;
}

void Stopwatch::show() {
	cout << "Time elapsed: " << end - begin << endl;
}

int main() {
	Stopwatch sw;
	sw.start();
	for(int i = 0; i < 1000000900; ++i);
	sw.stop();
	sw.show();
	return 0;
}
