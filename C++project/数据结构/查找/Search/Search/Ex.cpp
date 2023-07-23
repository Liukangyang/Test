#include "Ex1.h"

/*
 在有序序列中查找关键字的区间
假设在有序序列中存在相同关键字，要求输出所查找关键字的区间（多个匹配项的左右下标）
分析：利用改进的折半查找法，首先每次往左边缩小区间，查找到第一个匹配关键字，记录下标a，
然后再往右边缩小区间，直至查找到最后匹配的关键字，记录下标b，[a,b]即为匹配区间
*/
void BinSearch_Ex(RecType R[], int n, int k)
{
	int count = 0;
	int low = 0, high = n - 1;  // 区间左右端点
	int mid = -1;
	int s1 = -1, s2 = -1;
	//获取左端点
	while (low <= high)
	{
		mid = (low + high) / 2;   //取中间值
		if (k <= R[mid].key)
		{
			high = mid - 1;
			if (k == R[mid].key)
				s1 = mid;
		}
		else low = mid + 1;
	}
	//获取右端点
	low = 0; high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;   //取中间值
		if (k >= R[mid].key)
		{
			low = mid + 1;
			if (k == R[mid].key)
				s2 = mid;
		}
		else high = mid - 1;
	}
	//输出区间
	if (s1 == -1 && s2 == -1) cout << "表中不存在该关键字！" << endl;
	else if (s1 == s2 && s1 != -1) cout << "关键字区间为:[" << s1 << "]" << endl;
	else  cout << "关键字区间为:[" << s1<<","<<s2 << "]" << endl;
}