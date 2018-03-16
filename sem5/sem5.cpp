#include <iostream>
#include <string>

using namespace std;

class Human {
	private:
		string name;
		string sname;
		string lname;
		int age;
		
	public:
		Human (){
			name = "name";
			sname = "sname";
			lname = "lname";
			age = -1;
		}
		
		Human (string _name, string _sname, string _lname, int _age) {
			name = _name;
			sname = _sname;
			lname = _lname;
			age = _age;
		}
		
		~Human() {}
		void set_name(string _name) {
			name = _name;
		}
		
		void set_sname(string _sname) {
			sname = _sname;
		}
		
		void set_lname(string _lname) {
			lname = _lname;
		}
		
		string get_name() {
			return name;
		}
		
		string get_sname() {
			return sname;
		}
		
		string get_lname() {
			return lname;
		}
};

class Student: public Human {
	private:
		int group;
		int score;
	public:
		Student() : Human() {
			score = -1;
			group = -1;
		}
		Student(string _name, string _sname, string _lname, int _age, int _score, int _group) : Human(_name, _sname, _lname, _age) {
			score = _score;
			group = _group;
		}
		
	
	
	
};

int main () {
	Student A = Student ("1", "2", "3", 25, 4, 652);
	cout << A.get_name();
	return 0;
}

