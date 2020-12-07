#include<iostream>

using namespace std;
int getValue();
class Array {
private:
	int value;
public:
	void SetElement()
	{
		cout << "Введите значение элемента: ";
		value = getValue();
	}
	void GetElement()
	{
		cout << value;
	}
	Array& ReturnElement(Array* array, int i)
	{
		return array[i];
	}
	Array& operator --() // префиксный
	{
		this->value--;
		return *this;
	}
	Array operator-- (int) //постфиксный
	{
		Array prev = *this;
		--* this;
		return prev;
	}
	friend void ShowArray(Array* arr, int size);
};
void ShowArray(Array* array, int size) {
	cout << "Массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		array[i].GetElement();
		cout << endl;
	}
}


int main() {
	setlocale(0, "Rus");
	const int size = 5;
	Array array[size];

	for (int i = 0; i < size; i++)
	{
		array[i].SetElement();
	}
	ShowArray(array, size);
	int num;
	cout << "Введите номер массива, над которым надо провести операцию декремента (0-4): ";
	cin >> num;
	//--array[num].ReturnElement(array, num);
	--array[num];
	ShowArray(array, size);

	return 0;
}

int getValue()
{
	while (true)
	{
		int a;
		cin >> a;

		if (cin.fail())
		{
			cout << "Некорректный ввод, введите число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return a;
	}
}