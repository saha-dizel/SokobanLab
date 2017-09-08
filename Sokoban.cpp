//инициализация библиотек
#include <windows.h>
#include <conio.h>
#include <iostream>

//устанавливаем пространство имён
using namespace std;

//класс Sokoban, в котором описана вся игра
class Sokoban
{
private:
	//выбранный уровень
	unsigned short int lvl;
	unsigned short int boxNum;
	unsigned short int boxInPlace;

public:
	//конструктор
	Sokoban()
	{
		setLVL(1);
		menu();
	}

	//выбор уровня
	void setLVL(int level)
	{
		lvl = level;
	}

	//получение уровня
	int getLVL()
	{
		return lvl;
	}

	//изменение уровня (тут оно херовое, надо научить его двигаться в обе стороны)
	void changeLVL()
	{
		/*TODO: прописать if для нажатых клавиш влево/вправо*/
		/*Также нужно сделать так, чтобы счётчик уровней не опускался ниже 1 и не поднимался выше количества уровней*/
		unsigned short int newLVL = getLVL() + 1;
		setLVL(newLVL);
	}

	//кол-во коробок на уровне
	void setBox(int boxes)
	{
		boxNum = boxes;
	}

	//меню (тут надо будет ебаться)
	void menu()
	{

	}
};

void main()
{

}

/*
Легенда:
+ тип public
- тип private
*/

//Итак, что нам нужно
/*
данные:
	-счётчик уровней: lvl
	-количестов ящиков на уровне: boxNum
	-количество установленных на нужное место ящиков: boxInPlace

методы:
	конструктор: Sokoban (тут надо реализовать запуск меню, меню - отдельный подкласс)
	+выбор уровня: setLVL
	+меню: menu
	+получение уровня: getLVL (для последующего счётчика уровней)
	+смена уровня: changeLVL
	+кол-во коробок на уровне: setBox
*/
