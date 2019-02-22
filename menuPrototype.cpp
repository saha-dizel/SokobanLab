#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//прототип функции
int menu();

int main()
{
  int answer = menu();
  
  switch(answer)
  {
  case 0: cout << "1" << endl; break;
  case 1: cout << "2" << endl; break;
  case 2: cout << "3" << endl; break;
  }
  
  system("pause");
  return 0;
  
}

int menu() 
{
  int key = 0;
  int code;
  
  do
  {
  system("cls");
  key = (key + 3) % 3;
  
  switch(key)
  {
  case 0:
  cout << "Play <-" << endl << "Choose level: " << LVL << endl; << "Exit" << endl;
  break;
  case 1: 
  cout << "Play" << endl << "Choose level: " << LVL << " <-"<< endl; << "Exit" << endl;
  break;
  case 2:
  cout << "Play" << endl << "Choose level: " << LVL << endl; << "Exit <-" << endl;
  break;
  }
  
  code = _getch();
  if (code == 224)
  {
    code = _getch();
    if (code == 80) key++;
    if (code == 72) key--;
  }
  } while (code != 27);
  
  system("cls");
  
  return key;
}
