/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
ULListStr dat;

dat.push_back("10");
dat.push_back("9");
for(int i=0; i<8;i++){
	dat.push_back("8");
}
dat.push_back("7");
dat.push_back("6");
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(11) << " " << dat.get(12) << endl;
//should print 10 9 7 6

dat.pop_back();
dat.pop_back();
cout << dat.back() << endl;
//should print 8

for(int i=0; i<10;i++){
	dat.pop_back();
}
cout << dat.empty() << endl;
//should print 1

dat.push_front("10");
dat.push_front("9");
dat.push_front("8");
dat.push_front("7");
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl;
// should print 7 8 9 10

dat.pop_front();
dat.pop_front();
dat.pop_front();
cout << dat.front() << endl;
//should print 10
dat.pop_front();
cout << dat.empty() << endl;
//should print 1
  return 0;
}
