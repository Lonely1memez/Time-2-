
#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
  private:
    int hour, minute;

  public:
    Time(int h=0, int m=0);
    void setHour(int h);
    void setMinute(int m);
    int getHour();
    int getMinute();
    void print();
    void advance();


  void advance(int m); 
  int minSinceMidnight() const;
  void back();


  bool operator<(const Time& time) const;
  bool operator==(const Time& time) const;
  friend ostream& operator<<(ostream& out, const Time& t);
};

#endif