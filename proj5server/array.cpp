#include <iostream> 
#include "array.h" 
#include "number.h" 

using namespace std;

TArray::TArray()
{
    sizeArr = 0;
    elements = nullptr;
}

TArray::TArray(int n) {
    sizeArr = n;
    elements = new number[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
		elements[i] = 0;
	}
}

void TArray::insertElem() {
    for (int i = 0; i < sizeArr; i++) {
		cin >> elements[i];
	}
	system("cls");
}

void TArray::midAndSKO() {
	number sum = 0;
	number average = 0;
	number sumSko = 0;
	number sko = 0;
    for (int i = 0; i < sizeArr; i++)
	{
		sum += elements[i];
	}
    average = sum / sizeArr;
    for (int i = 0; i < sizeArr; i++)
	{
		sumSko += ((elements[i] - average) * (elements[i] - average));
	}
    sko = sqrt((number)1 / (sizeArr - 1) * sumSko);
    cout << "Среднее: " << average << "\n";
    cout << "СКО: " << sko << "\n";
	system("pause");
}

void TArray::insertionSortAbove() {
    for (int i = 1; i < sizeArr; i++) {
		number key = elements[i];
		int j = i - 1;


			while (j >= 0 && elements[j] > key) {
				elements[j + 1] = elements[j];
				j--;
			}
		elements[j + 1] = key;
	}
}

void TArray::insertionSortBeyond() {
    for (int i = 1; i < sizeArr; i++) {
		number key = elements[i];
		int j = i - 1;

		while (j >= 0 && elements[j] < key) {
			elements[j + 1] = elements[j];
			j--;
		}
		elements[j + 1] = key;
	}
}

void TArray::changeSize(int newSize) {
	number* newElements = new number[newSize];
    for (int i = 0; i < (newSize < sizeArr ? newSize : sizeArr); i++) {
		newElements[i] = elements[i];
	}


    if (newSize > sizeArr) {
        for (int i = sizeArr; i < newSize; i++) {
			newElements[i] = 0;
		}
	}


	delete[] elements;


	elements = newElements;

    sizeArr = newSize;

    //cout << "Размер массива изменен на " << newSize << " элементов.\n"
    //system("pause");
}

void TArray::changeElement(number elem, int index) {
    if (index >= 0 && index <= sizeArr - 1) {
		elements[index] = elem;
        //cout << "Успешно\n;
	}
	else {
        cout << "Элемента с таким индексом не существует\n";
    }
	//system("pause");
}

void TArray::print() {
    for (int i = 0; i < sizeArr; i++) {
		cout << elements[i] << " ";
	}
	cout << endl;
}

int TArray::getSize()
{
    return sizeArr;
}

number TArray::getElem(int index)
{
	return elements[index];
}

TArray::~TArray()
{
    if(elements != nullptr) delete[] elements;
}
