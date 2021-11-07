#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	// CONSTRUCTORS:
	Point()
	{
		x = 0;
		y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	Point operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	// Increment/Decrement
	Point& operator++()
	{
		this->x++;
		this->y++;
		cout << "PrefixIncrement:\t" << this << endl;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; // Сохраняем текущее значение нашего объекта
		this->x++;
		this->y++;
		cout << "SuffixIncrement:\t" << this << endl;
		return old;
	}


	//     METHODS
	double distance(Point& other)
	{
#ifdef HARD
		double	x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
#endif // HARD

		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print() const
	{
		cout << "x = " << x << "\t" << "Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{

	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
Point operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() + right.get_x());
	buffer.set_y(left.get_y() + right.get_y());
	return buffer;
}
Point operator-(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() - right.get_x());
	buffer.set_y(left.get_y() - right.get_y());
	return buffer;
}
Point operator*(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() * right.get_x());
	buffer.set_y(left.get_y() * right.get_y());
	return buffer;
}
Point operator/(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() / right.get_x());
	buffer.set_y(left.get_y() / right.get_y());
	return buffer;
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << "\t" << "Y = " << obj.get_y();
	return os;
}
istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x;
	is >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

#define delimiter "\n-------------------------------------------------\n"
//#define DISTANCE
//#define STRUCT_POINT
//#define constructorcs_check
//#define assignmed_check
//#define arithmetical_opertatorc_check
void main()
{
	setlocale(LC_ALL, "Ru");
#ifdef STRUCT_POINT
	int a; // объявление переменной 'a' по инт	
	Point A; // объявление переменной 'A' типа 'Point'
			 // объявление экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

		Point B;
	B.set_x(3);
	B.set_y(4);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Размер объекта" << sizeof(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точка А и B: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точка B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE
#ifdef constructors_check
	Point A; // DEFAULT CONSTRUCTOR
	A.print();
	Point B(2, 3);
	B.print();
	Point C = B; // Copy constructor
	C.print();
	Point D;
	D = B; // Оператор присваивания Copy Assignment
	D.print();
#endif // constructors_check
#ifdef assignmed_check
	int a, b, c;
	a = b = c = 1;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3); 
	// Point(2,3) - явный вызов конструктора
	//таким образом создается временный безымянный объект, который существует только в пределах выражения,
	// и удаляется после заверешения выражения.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif
#ifdef arifmetical_opertatorc_check
	Point A(2, 3);
	Point B(3, 4);
	Point C = A + B; // "
	C.print();
#endif // arithmetical_opertatorc_check
#ifdef DEBUG
	for (Point i(2, 3); i.get_x() < 10; i++)
	{
		i.print();
	}
#endif // DEBUG
#ifdef ostream
	Point A(2, 3);
	A.print();
	Point B = A++;
	B.print();
	cout << A << endl;
	cout << B << endl;
	cout << "Введите координаты точки А: ";
	cin >> A;
	cout << A << endl;
#endif // ostream
#ifdef MINUS
	Point A(3, 4);
	Point B(4, 5);
	Point C = A - B; // чтобы научить оператор + складывать "точки" его нужно перегрузить для класса "точка"
	C.print();
#endif // MINUS
#ifdef multiplication
	Point A(3, 4);
	Point B(4, 5);
	Point C = A * B;
	C.print();
#endif // multiplication
#ifdef division
	Point A(3, 4);
	Point B(4, 5);
	Point C = A / B;
	C.print();
#endif // division

}
