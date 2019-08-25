#include<iostream>
using namespace std;
const double PI=3.1415926;
class Shape
{
public:
virtual void print()=0;
virtual double area()=0;
};
class TwoDimensional: public Shape
{
public:
virtual double perimeter()=0;
};
class ThreeDimensional:public Shape
{
public:
virtual double volume()=0;
};
int main()
{
Circle circle1(5); //半径
Cone cone1(5,10); //底面半径,高
Triangle tri1(3,4,5); //三条边
Rectangle rect1(6,7); //长,宽
Box box1(3,4,5); //长,宽,高
Cylinder cy1(5,10); //底面半径,高
Sphere sphere1(10); //球半径
circle1.print();
cout << circle1.area() << endl << circle1.perimeter() << endl;
cone1.print();
cout << cone1.area() << endl << cone1.volume() << endl;
tri1.print();
cout << tri1.area() << endl << tri1.perimeter() << endl;
rect1.print();
cout << rect1.area() << endl << rect1.perimeter() << endl;
box1.print();
cout << box1.area() << endl << box1.volume() << endl;
cy1.print();
cout << cy1.area() << endl << cy1.volume() << endl;
sphere1.print();
cout << sphere1.area() << endl << sphere1.volume() << endl;
return 0;
}

