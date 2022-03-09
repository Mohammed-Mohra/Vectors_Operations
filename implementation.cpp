
#include "Vector.h"

#include <istream>
using namespace std;

Vector::Vector(const Vector& theOther) {
	*this = theOther;

}

void Vector::clear() {
	delete[]pData;
	this->pData = NULL;
	elementNum = 0;

}
void Vector::erase(unsigned int position) {
	if (position >= elementNum) {
		cout << "wrong postion" << endl;
		return;
	}
	if (elementNum == 1) {
		delete[] pData;
		pData = NULL;
		elementNum = 0;
		return;
	}
	int *temp = new int[elementNum - 1];
	for (int i = 0, j = 0;i < elementNum; i++,j++) {
		if (i == position) {
			j--;
		}
		else
			temp[j] = pData[i];
	}
	elementNum--;

	delete[]pData;
	//pData = new int[elementNum];
	pData = temp;

}

int& Vector::at(unsigned int position) {
	if (position >= elementNum) {
		cout << "wrong postion" << endl;
	}
	return pData[position];
}

bool Vector::insert(unsigned int position, int element) {
	if (position < 0)
		return false;
	if (position <= elementNum) {
		int* ptemp = new int[elementNum + 1];
		for (int i = 0, j = 0;j < elementNum+1 ;i++,j++) {
			if (i == position) {
				ptemp[position] = element;
				j++;
			}
			 if(i<elementNum)
				ptemp[j] = pData[i];
		}
		elementNum++;
		delete[] pData;
		pData = ptemp;
		return true;
	}
	else if (position > elementNum) {
		int* ptemp = new int[position + 1];
		for (int i = 0, j = 0;i < position + 1;i++) {
			if(pData !=NULL && i<elementNum)
				ptemp[i] = pData[i];
			if (i >= elementNum && i == position) {
				ptemp[i] = element;
			}
			else if (i >= elementNum && i != position)
				ptemp[i] = 0;
		}
		elementNum = position + 1;
		
		delete[] pData;
		pData = ptemp;
		return true;
	}
	
}

	

 const Vector & Vector::operator =(const Vector& theOther) {
	 elementNum = theOther.elementNum;
	 this->pData = new int[elementNum];
	 for (int i = 0;i < elementNum;i++)
		 pData[i] = theOther.pData[i];
	 return theOther;
}


 int& Vector::operator [](unsigned int position) {
	 if (position >= elementNum) {
		 cout << "wrong position so returned -1";
		// return -1;

	 }
	 return pData[position];
 }

 const int& Vector::operator [](unsigned int position)const {

	 if (position >= elementNum) {
		 cout << "wrong position so returned -1";
		 // return -1;

	 }
	 return pData[position];

 }


 std::ostream& operator << (std::ostream& os, const Vector& v) {
	 for (int i = 0;i < v.elementNum;i++)
		 os << v.pData[i] << " ";
	 os << endl;
	 return os;
 }



