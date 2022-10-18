#include "Time.h"
#include <iomanip>

Time::Time(int h, int m) : hour(h), minute(m)
{
  if(hour < 0 || hour > 23)
  hour = 0;

  if(minute < 0 || minute > 59)
  minute = 0;

}

void Time:: setHour(int h)
{
  if(h >= 0 && h < 24)
  hour = h;
}


void Time:: setMinute(int m)
{
  if(m >= 0 && m < 60)
  minute = m;
}


int Time:: getHour()
{
  return hour;
}


int Time:: getMinute()
{
  return minute;
}


void Time:: print()
{
  int h = hour;
  string period;


  if(h < 12)
  {
    if(h == 0)
    h = 12;

    period = "AM";
  }
  else
  {
    if(h > 12)
    h = hour - 12;
    period = "PM";
  }

  cout << h << ":" << setw(2) << setfill('0') << minute << " "<< period << endl;
}


void Time:: advance()
{

  minute++;
  if(minute == 60)
  {
    minute = 0;
    hour++;

    if(hour == 24)
    hour = 0;

  }  
}



void Time:: advance(int m)
{
  if(m >= 1) 
  {
    minute += m;
    hour += minute/60;
    minute = minute%60; 
    hour = hour%24;
  }
}

int Time:: minSinceMidnight() const
{
  return (hour*60 + minute);
}


void Time:: back()
{
  minute--; 
  if(minute < 0)
  {
    hour--; 
    minute += 60; 
  
    if(hour < 0)
    hour += 24; 
  }
}

bool Time::operator<(const Time& time) const
{
  if(hour < time.hour)
  return true;
  else if(hour > time.hour)
  return false;
  else
  {
    return minute < time.minute;
  }
}


bool Time:: operator==(const Time& time) const
{
  return(hour == time.hour && minute == time.minute);
}


ostream& operator<<(ostream& out, const Time& t)
{
  out<<setw(2)<<setfill('0')<<t.hour<<":"<<setw(2)<<setfill('0')<<t.minute;
  return out;
}
