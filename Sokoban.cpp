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
	
	class tile
	{
		private:
		bool box;
		bool playerPos;
		bool wall;
		bool winPlace;
		
		public:
		//геттеры
		bool getBox()
		{
			return box;
		}
		bool getPlayerPos()
		{
			return playerPos;
		}
		bool getWall()
		{
			return wall;
		}
		bool getWinPlace()
		{
			return winPlace;
		}
		
		//сеттеры
		void setBox(bool boxState)
		{
			box = boxState;
		}
		void setPlayerPos(bool playerPosState)
		{
			playerPos = playerPosState
		}
		void setWall(bool wallState)
		{
			wall = wallState;
		}
		void setWinPlace(bool winPlaceState)
		{
			winPlace = winPlaceState;
		}
	};
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

/*
Итак, появляется новый класс: tile
данные:
	-наличие коробки: box
	-позиция игрока: playerPos
	-наличие стены: wall
	-место для коробки: winPlace
методы:
	+4 геттера
	+4 сеттера 
	//это для каждых данных
*/
