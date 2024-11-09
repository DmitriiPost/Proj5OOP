#ifndef ARRAY_H 
#define ARRAY_H
#include "number.h"

class TArray
{
	
public:
	TArray();
	TArray(int n);
	~TArray();
	void insertElem();
	void midAndSKO();
	void insertionSortAbove();
	void insertionSortBeyond();
	void changeSize(int newSize);
	void changeElement(number, int);
	void print();
	int getSize();
	number getElem(int);
private:
    int sizeArr;
	number* elements;
};


#endif // ARRAY_H 
