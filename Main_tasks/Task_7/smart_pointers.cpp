#include <iostream>
#include <memory>
#include "Test.h"
using namespace std;

int main() {
	// shared_ptr<Test> sp (new Test[3], default_delete<Test[]>());
	// for(int i=0; i<3; i++) {
	// 	sp.get()[i].Val = i + 1;
	// 	sp.get()[i].get_val();
	// }

	unique_ptr<Test[]> p (new Test[3]);
	
	for(int i=0; i<3; i++) {
		p.get()[i].val = i + 1;
		p.get()[i].get_val();
	}

	cout << "---------" << endl;
	p.reset(new Test[2]);
	cout << "---------" << endl;

	return 0;
}
