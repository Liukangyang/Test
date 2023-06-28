#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include <ctime>
using namespace std;
void print2(int val)
{
	cout << val << " ";
}

//sort+ÂÒĞò
void test8()
{
	vector<int> v;
	v.push_back(2); v.push_back(1); v.push_back(3);
	v.push_back(6); v.push_back(4); v.push_back(5);
	for_each(v.begin(), v.end(), print2);
	cout << endl;
	//ÅÅĞò
	cout << "ÉıĞòÅÅĞò:" << endl;
	sort(v.begin(), v.end());//Ä¬ÈÏÉıĞòÅÅĞò
	for_each(v.begin(), v.end(), print2);
	cout << endl;

	//½µĞòÅÅĞò
	cout << "½µĞòÅÅĞò:" << endl;
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), print2);
	cout << endl;

	//´òÂÒË³Ğò
	cout << "´òÂÒË³Ğò:" << endl;
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), print2);
	cout << endl;

}

void test9()
{
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(10-i);
		v2.push_back(20-i);
	}
	for_each(v1.begin(), v1.end(), print2); cout << endl;
	for_each(v2.begin(), v2.end(), print2); cout << endl;

	vector<int> vDest;
	//¿ª±Ù¿Õ¼ä
	vDest.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vDest.begin(),greater<int>());
	//mergeÄ¬ÈÏÊÇÉıĞòÅÅĞò,ÈôĞè½øĞĞ½µĞòÅÅĞò,ĞèÖØĞÂÖ¸¶¨Î½´Ê.
	for_each(vDest.begin(), vDest.end(), print2);
	cout << endl;

	//ÈİÆ÷·´×ª
	reverse(vDest.begin(), vDest.end());
	for_each(vDest.begin(), vDest.end(), print2);
	cout << endl;


}

//int main()
//{	
//	srand((unsigned int)time(NULL));
//	//test8();
//	test9();
//	return 0;
//}
