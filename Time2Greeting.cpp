#include <iostream>
#include <string>
using namespace std;
//returns greeting as a string based on integer value of time recieved
string time2greeting(int &time)
{
  if(time >= 400 && time < 1200)
    return "Good Morning, ";
  if(time >= 1200 && time < 1700)
    return "Good Afternoon, ";
  if(time >= 1700 && time < 2300)
    return "Good Evening, ";
  if((time >= 2300 && time < 2400) || (time >= 0 && time < 400))
    return "What are you doing up, ";
  return "That is an illegal time, ";
}    
//recieves the name of someone and a time and returns an output corresponding to the time followed by the name input
int main()
{
  string time2greeting(int &time);
  string name;
  int time;
  
  cout << "What is your name? ";
  cin >> name;
  cout << "What time is it? (0-2400)";
  cin >> time;
  cout << time2greeting(time);
  cout << name << endl;
  return 0;
  
}