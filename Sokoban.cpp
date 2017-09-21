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
		//конструктор
		tile()
		{
			/*
			box = false;
			playerPos = false;
			wall = false;
			winPlace = false;
			*/

			//НАДО ПОЛУЧИТЬ НАЗВАНИЕ УРОВНЯ
			//А ДЛЯ ЭТОГО СДЕЛАТЬ ОТДЕЛЬНЫЙ ПРИВАТНЫЙ МЕТОД
			ifstream fin(lvlName);
			lvlGen();
		}

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

		void lvlGen()
		{
			//НАДО ПОЛУЧИТЬ НАЗВАНИЕ УРОВНЯ
			//А ДЛЯ ЭТОГО СДЕЛАТЬ ОТДЕЛЬНЫЙ ПРИВАТНЫЙ МЕТОД
			string lvlName = getLVL() + ".txt";
			ifstream fin(lvlName);

			//в начало уровней надо поместить кол-во строк/столбцов
			fin >> rows >> columns;

			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
				{
					//считываем один символ
					tileSpec = getline(fin, 1);

					switch (tilespec)
					{
					case '#':
					{
						array[i, j].setWall(true);
					}
					case '@':
					{
						array[i, j].setBox(true);
					}
					case '+':
					{
						array[i, j].setPlayerPos(true);
					}
					case '$':
					{
						array[i, j].setWinPlace(true);
					}
					}
				}

			fin.close();
			//СЮДА ЖЕ ВСУНУТЬ ОТРИСОВКУ УРОВНЯ
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
