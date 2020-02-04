#include <iostream>
#include "Shapes.h"
using namespace std;
const int INDEX = 10;
void Print_menu();
void Make_circle(Shape** s, int& index);
void Make_rectangle(Shape** s, int& index);
void Print_all(Shape** s, int index);
void Terminate_all(Shape** s, int index);
enum { CIRCLE = 1, RECTANGLE, SHOWALL, EXIT };
int main() {
	Shape* sList[INDEX] = { NULL };
	int index = 0;
	char choice;
	int choice_real;
	while (true) {
		Print_menu();
		cout << "����: ";
		cin >> choice;
		choice_real = choice - '0';
		switch (choice_real) {
			case CIRCLE:
				Make_circle(sList, index);
				break;
			case RECTANGLE:
				Make_rectangle(sList, index);
				break;
			case SHOWALL:
				Print_all(sList, index);
				break;
			case EXIT:
				Terminate_all(sList, index);
				return 0;
				break;
			default:
				cout << "�߸� �Է��ϼ̽��ϴ�!" << endl;
				break;
		}
	}
}

void Print_menu() {
	cout << "1. Circle �߰�" << endl;
	cout << "2. Rectangle �߰�" << endl;
	cout << "3. ��ü �׸���" << endl;
	cout << "4. ����" << endl;
}
void Make_circle(Shape** s, int& index) {
	int x; int y; int radius;
	cout << "x��ǥ, y��ǥ, ������ ���̸� �Է��ϼ���." << endl;
	cin >> x >> y >> radius;
	s[index] = new Circle(x, y, radius);
	index++;
}
void Make_rectangle(Shape** s, int& index) {
	int x; int y; int width; int height;
	cout << "x��ǥ, y��ǥ, �ʺ��� ����, ������ ���̸� �Է��ϼ���." << endl;
	cin >> x >> y >> width >> height;
	s[index] = new Rectangle(x, y, width, height);
	index++;
}
void Print_all(Shape** s, int index) {
	for (int i = 0; i < index; i++) {
		s[i]->Draw();
	}
}
void Terminate_all(Shape** s, int index) {
	for (int i = 0; i < index; i++) {
		if (s[i] != NULL) {
			delete s[i];
			s[i] = NULL;
		}
	}
}