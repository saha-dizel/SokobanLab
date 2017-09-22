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
		//конструктор
		tile ()
		{
			/*
			box = false;
			playerPos = false;
			wall = false;
			winPlace = false;
			*/
			
			//НАДО ПОЛУЧИТЬ НАЗВАНИЕ УРОВНЯ
			//А ДЛЯ ЭТОГО СДЕЛАТЬ ОТДЕЛЬНЫЙ ПРИВАТНЫЙ МЕТОД
			ifstream fin (lvlName);
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
			ifstream fin (lvlName);
			
			//в начало уровней надо поместить кол-во строк/столбцов
			fin >> rows >> columns;
			
			for (int i = 0; i < rows ; i++)
				for (int j = 0; j < columns + 1; j++)
				{
					//считываем один символ
					tileSpec = getline (fin, 1);
					
					switch (tilespec)
					{
					case '#':
						{
							array[i,j].setWall(true);
						}
					case '@':
						{
							array[i,j].setBox(true);
						}
					case '+':
						{
							array[i,j].setPlayerPos(true);
						}
					case '$':
						{
							array[i,j].setWinPlace(true);
						}
					}
				}
			
			//СЮДА ЖЕ ВСУНУТЬ ОТРИСОВКУ УРОВНЯ
		}
	};
	
	class player
	{
	private:
	int PlayerCoordinateX, PlayerCoordinateY;//Координаты, где стоит игрок
	bool CanMovePlayer(int MoveInX, int MoveInY)/*Метод, который проверяет, может ли игрок двигаться влево или вправо,
							  MoveInX и MoveInY - смещение от координат героя, ожидаемый диапазон значений от -1 до +1*/
	{
		if (tile[PlayerCoordinateX + MoveInX][PlayerCoordinateY + MoveInY].getWall != true)//Если там не стена
		{
			if (tile[PlayerCoordinateX + MoveInX][PlayerCoordinateY + MoveInY].getBox == true &&
				(title[CoordinateX + 2 * MoveInX][CoordinateY + 2 * MoveInY].getBox != true) or (title[CoordinateX + 2 * MoveInX][CoordinateY + 2 * MoveInY].getWall != true))//Если там не две коробки или коробка+стена
				return true; //можно
			else return false;//иначе нельзя
		}
		else return false; //инача нельзя
	};

	public:
	void MovePlayer(int MoveInX, int MoveInY)/*Метод, который двигает игрка влево или вправо,
							  MoveInX и MoveInY - смещение от координат героя, ожидаемый диапазон значений от -1 до +1*/
	{
		if (player.CanMovePlayer(MoveInX , MoveInY) == true)
		{
			tile[PlayerCoordinateX + MoveInX][PlayerCoordinateY + MoveInY].setBox(false);//убрать коробку
			tile[PlayerCoordinateX + 2 * MoveInX][PlayerCoordinateY + 2 * MoveInY].setBox(true);//поставить коробку
			tile[PlayerCoordinateX][PlayerCoordinateY].setPlayerPos(false);//Убрать игрока с клетки
			tile[PlayerCoordinateX + MoveInX][PlayerCoordinateY + MoveInY].setPlayerPos(true);//Поставить игрока на новую клетку
			PlayerCoordinateX = PlayerCoordinateX + MoveInX;//Записать новые координаты игрока
			PlayerCoordinateY = PlayerCoordinateY + MoveInY;
		}/*Сама коробка двигаться не может, поэтому нет нужны в написании метода её отдельного движения*/
	};
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
