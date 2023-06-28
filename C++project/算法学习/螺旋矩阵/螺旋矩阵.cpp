#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
	//创建二位数组(n*n)
	vector<vector<int>> res(n, vector<int>(n, 0));
	int startx = 0, starty = 0;//每一圈起始位置
	int loop = n / 2;//循环次数
	int mid = n / 2;//矩阵中间位置
	int count = 1;//计数值
	int offset = 1;//右界偏移量，控制每条边遍历的长度
	int i = 0, j = 0;

	for (int k = 0; k < loop; k++)
	{
		i = startx; j = starty;

		//最上面一行
		for (j=starty;j<n-offset;j++)
		{
			res[i][j] = count++;
			
		}
		//最右边一列
		for (i=startx;i<n-offset;i++)
		{
			res[i][j] = count++;
			
		}
		//最下面一行
		for (j=n-offset;j>starty;j--)
		{
			res[i][j] = count++;
			
		}
		//最左边一列
		for (i=n-offset;i>startx;i--)
		{
			res[i][j] = count++;
			
		}

		startx++;
		starty++;
		offset++;

	}

	if (n % 2)
	{
		res[mid][mid] = count;
	}

	return res;

}

void Printmatrix(vector<vector<int>>& res)
{
	int n = res.size();
	int startx = 0, starty = 0;//每一圈起始位置
	int loop = n / 2;//循环次数
	int mid = n / 2;//矩阵中间位置
	int count = 0;//计数值
	int offset = 1;//右界偏移量，控制每条边遍历的长度
	int i = 0, j = 0;

	for (int k = 0; k < loop; k++)
	{
		i = startx; j = starty;

		//最上面一行
		for (j = starty; j < n - offset; j++)
		{
			Sleep(500);
			cout << res[i][j] << " ";
			count++;
			if (count % n == 0) cout << endl;
		}
		//最右边一列
		for (i = startx; i < n - offset; i++)
		{
			Sleep(500);
			cout << res[i][j] << " ";
			count++;
			if (count % n == 0) cout << endl;
		}
		//最下面一行
		for (j = n - offset; j > starty; j--)
		{
			Sleep(500);
			cout << res[i][j] << " ";
			count++;
			if (count % n == 0) cout << endl;
		}
		//最左边一列
		for (i = n - offset; i > startx; i--)
		{
			Sleep(500);
			cout << res[i][j] << " ";
			count++;
			if (count % n == 0) cout << endl;
		}

		startx++;
		starty++;
		offset++;
	}

	if (n % 2)
	{
		Sleep(500);
		cout << res[mid][mid] << " ";
	}

}
int main()
{
	vector<vector<int>> res = generateMatrix(4);
	
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}

		cout<< endl;
	}
	//Printmatrix(res);






	return 0;
}