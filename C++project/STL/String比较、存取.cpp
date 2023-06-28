#include<iostream>
#include<string>
using namespace std;

//×Ö·û´®±È½Ï
void test07()
{
	string str1 = "hello";
	string str2 = "xello";

	int r = str1.compare(str2);

	if (r == 0)
		cout << "×Ö·û´®ÏàÍ¬" << endl;
	else if (r == 1)
		cout << "str1´ó" << endl;
	else cout << "str2´ó" << endl;

}

//×Ö·û´®´æÈ¡
void test08()
{
	//È¡£¨¶Á£©
	//[]
	string str = "hello";
	cout << str[4] << endl;

	//at()
	for (int i = 0; i < str.size(); i++)
		cout << str.at(i) << " ";

	//´æ£¨Ð´£©
	str[0] ='x';
	cout << str << endl;

	str.at(1) = 'x';
	cout << str << endl;





}
//int main()
//{
//	test08();
//	
//	return 0;
//}