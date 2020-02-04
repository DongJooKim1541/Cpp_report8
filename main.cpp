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
		cout << "선택: ";
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
				cout << "잘못 입력하셨습니다!" << endl;
				break;
		}
	}
}

void Print_menu() {
	cout << "1. Circle 추가" << endl;
	cout << "2. Rectangle 추가" << endl;
	cout << "3. 전체 그리기" << endl;
	cout << "4. 종료" << endl;
}
void Make_circle(Shape** s, int& index) {
	int x; int y; int radius;
	cout << "x좌표, y좌표, 반지름 길이를 입력하세요." << endl;
	cin >> x >> y >> radius;
	s[index] = new Circle(x, y, radius);
	index++;
}
void Make_rectangle(Shape** s, int& index) {
	int x; int y; int width; int height;
	cout << "x좌표, y좌표, 너비의 길이, 높이의 길이를 입력하세요." << endl;
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