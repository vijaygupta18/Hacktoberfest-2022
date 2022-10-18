#include <iostream>
using namespace std;

class coord {
	float x, y;
public:
	coord() { x = 0; y = 0; };
	coord(float i, float j) { x = i; y = j; }
	void get_xy(float &i, float &j) { i = x; j = y; }
	friend coord operator*(const coord &obj, int i);
	friend coord operator*(int i, const coord &obj);
	friend coord operator-(const coord &obj, int i);
	friend coord operator-(int i, const coord &obj);
};

coord operator*(const coord &obj, int i) {
	coord temp;
	temp.x = obj.x * i;
	temp.y = obj.y * i;
	return temp;
}

coord operator*(int i, const coord &obj) {
	coord temp;
	temp.x = obj.x * i;
	temp.y = obj.y * i;
	return temp;
}

coord operator-(const coord &obj, int i) {
	coord temp;
	temp.x = obj.x - i;
	temp.y = obj.y - i;
	return temp;
}
coord operator-(int i, const coord &obj) {
	coord temp;
	temp.x = i - obj.x;
	temp.y = i - obj.y;
	return temp;
}
int main() {
	coord obj(12, 33);
	float x, y;
obj.get_xy(x, y);
	cout << "obj(" << x << ", " << y << ")" << endl;

	int value;
	cout << "Enter value: ";
	cin >> value;

	obj = obj * value;
	obj.get_xy(x, y);
	cout << "(obj * " << value << "): X = " << x << ", Y = " << y << endl;
	obj.get_xy(x, y);
	cout << "obj(" << x << ", " << y << ")" << endl;

	obj = value * obj;
	obj.get_xy(x, y);
	cout << "(" << value << " * obj): X = " << x << ", Y = " << y << endl;
	obj.get_xy(x, y);
	cout << "obj(" << x << ", " << y << ")" << endl;

	obj = obj - value;
	obj.get_xy(x, y);
	cout << "(obj - " << value << "): X = " << x << ", Y = " << y << endl;
	obj.get_xy(x, y);
	cout << "obj(" << x << ", " << y << ")" << endl;

	obj = value - obj;
	obj.get_xy(x, y);
	cout << "(" << value << " - obj): X = " << x << ", Y = " << y << endl;
	return 0;
}
