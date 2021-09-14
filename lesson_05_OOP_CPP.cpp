//============================================================================
// Name        : lesson_05_OOP_CPP.cpp
// Author      : andry antonenko
// IDE         : Qt Creator 4.14.2 based on Qt 5.15.2
// Description : lesson 05 of the object-oriented programming on C++ course
//============================================================================
#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
//#include <list>
//#include <set>
#include <string>
//#include <sstream>
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
#include "game_blackjack.h"
//----------------------------------------------------------------------------
/*
1. Реализовать шаблон класса Pair1,
который позволяет пользователю передавать
данные одного типа парами.
Следующий код:
int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8
//*/

template<class T>
class Pair1
{
private:
  T f;
  T s;
public:
  Pair1(T aFirst, T aSecond)
    :f(aFirst),s(aSecond)
  {}
  ~Pair1(){}
  const T& first() const {return f;}
  const T& second() const {return s;}
};

void task_1()
{
  cout << "Task 1\n" << endl;

  Pair1<int> p1(6, 9);
  cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair1<double> p2(3.4, 7.8);
  cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  cout << endl;
}
//----------------------------------------------------------------------------
/*
2. Реализовать класс Pair,
который позволяет использовать
разные типы данных в передаваемых парах.
Следующий код:
int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5
Подсказка:
чтобы определить шаблон с использованием двух разных типов,
просто разделите параметры типа шаблона запятой.
//*/

template<class T1, class T2>
class Pair
{
private:
  T1 f;
  T2 s;
public:
  Pair(T1 aFirst, T2 aSecond)
    :f(aFirst),s(aSecond)
  {}
  ~Pair(){}
  const T1& first() const {return f;}
  const T2& second() const {return s;}
};

void task_2()
{
  cout << "\nTask 2\n" << endl;

  Pair<int, double> p1(6, 7.8);
  cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair<double, int> p2(3.4, 5);
  cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  cout << endl;
}
//----------------------------------------------------------------------------
/*
3. Написать шаблон класса StringValuePair,
в котором первое значение всегда типа string,
а второе — любого типа.
Этот шаблон класса должен наследовать
частично специализированный класс Pair,
в котором первый параметр — string,
а второй — любого типа данных.

Следующий код:
int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}

… должен производить следующий результат:
Pair: Amazing 7
Подсказка:
при вызове конструктора класса Pair
из конструктора класса StringValuePair
не забудьте указать,
что параметры относятся к классу Pair.
//*/

template<class T2>
class StringValuePair: public Pair<string, T2>
{
public:
  StringValuePair(string aFirst, T2 aSecond)
    :Pair<string,T2>(aFirst,aSecond)
  {}
  ~StringValuePair(){}
};

void task_3()
{
  cout << "\nTask 3\n" << endl;

  StringValuePair<int> svp("Amazing", 7);
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

  cout << endl;
}

//----------------------------------------------------------------------------
/*
4. Согласно иерархии классов,
которая представлена в методичке к уроку 3,
от класса Hand наследует класс GenericPlayer,
который обобщенно представляет игрока,
ведь у нас будет два типа игроков - человек и компьютер.
Создать класс GenericPlayer,
в который добавить поле name - имя игрока.
Также добавить 3 метода:
    • IsHitting() - чисто виртуальная функция,
возвращает информацию, нужна ли игроку еще одна карта.
    • IsBoosted() - возвращает bool значение,
есть ли у игрока перебор
    • Bust() - выводит на экран имя игрока и объявляет,
что у него перебор.
//*/


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  //----------------------------------------------------------------------------
  // Task 1
  //*
  task_1();
  //*/
  //----------------------------------------------------------------------------
  // Task 2
  //*
  task_2();
  //*/
  //----------------------------------------------------------------------------
  // Task 3
  //*
  task_3();
  //*/
  //----------------------------------------------------------------------------
  return a.exec();
}
