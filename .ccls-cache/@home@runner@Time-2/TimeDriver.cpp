#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
  Time t1;
  Time t2(8);
  Time t3(13, 30);
  Time t4(25, 5);
  Time t5(12, 60);

  Time times[] = {t1, t2, t3, t4, t5};
  for(int i=0;i<5;i++)
  times[i].print();


  t3.setHour(0);
  t3.setMinute(58);
  t3.setHour(25);
  t3.setMinute(65);
  cout<<"hour: "<<t3.getHour()<<", minute: "<<t3.getMinute()<<endl;
  t3.advance();
  t3.print();
  t3.advance();
  t3.print();

  Time t6(0, 0 ); 
  t6.print(); 
  t6.advance(120); 
  t6.back(); 
  cout<<"minutes since midnight: "<<t6.minSinceMidnight()<<endl; 
  t6.advance(); 
  t6.advance(1320); 
  t6.back(); 
  t6.print(); 

  t1.setHour(0);
  t1.setMinute(0);
  t2.setHour(13);
  t2.setMinute(30);

  if(t1 < t2)
  cout << "t1 is before t2" << endl;
  else
  cout << "t1 is not before t2" << endl;

  if (t1 == t2)
  cout << "t1 is the same as t2" << endl;
  else
  cout << "t1 is not the same as t2" << endl;

  cout << "t1: " << t1 << endl; 
  cout << "t2: " << t2 << endl; 

  return 0;
}