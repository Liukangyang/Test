#include<iostream>
#include<string>
using namespace std;

int main()
{
	double* f=NULL;
	f = new double;
	*f = 10.402;
	cout << "分配空间为：" << sizeof(*f)<<"个字节"<<endl;
	cout << "值：" << *f << endl;

	delete f;
	f = NULL;
	//cout << "分配空间为：" << sizeof(*f) << "个字节" << endl;

	//分配一维数组
	int* a;
	a = new int[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i+1;
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	
	delete [] a;
	cout << endl << endl;

	//分配二维数组
	int* arr[2];//指针数组
	int (*b)[8];//二维指针
	b = new int[4][8]; //指针数组
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			b[i][j] = (j+1) * (i+1);
		}
	}
	cout << b[1] << endl;
	cout << b[2] << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << b[i][j] << "  ";
			if (j == 7) cout << endl;
		}
	}
	delete [] b;


	return 0;
}