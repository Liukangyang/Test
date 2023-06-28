#pragma once
#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//通用数组类
template <class T=int>
class MyArray
{
private:
	T* pAddress;

	int m_Capacity;
		
	int m_Size;

public:
	//构造函数
	//无参构造
	MyArray()
	{	
		this->m_Capacity = 1;
		//cout << "有参构造调用！" << endl;
		pAddress = new T[this->m_Capacity];  //开辟到堆区
		this->m_Size = 0;
	}

	//有参构造
	MyArray(int capacity)
	{
		//cout << "有参构造调用！" << endl;
		pAddress = new T[capacity];  //开辟到堆区
		this->m_Capacity = capacity;
		this->m_Size = 0;
	}

	//拷贝构造(深拷贝)
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造调用！" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		this->pAddress = new T[this->m_Capacity];//深拷贝
		//元素赋值
		for (int i = 0; i < this->m_Capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}


	//赋值符号重载
	MyArray& operator=(const MyArray& arr)
	{
		//有东西先消除
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = this->m_Capacity = 0;

		}

		//重新赋值
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		this->pAddress = new T[this->m_Capacity];//深拷贝
		//元素赋值
		for (int i = 0; i < this->m_Capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		//cout << "对象赋值重载" << endl;
		return *this;  //返回对象本身
	}

	//析构
	~MyArray()
	{
		//cout << "析构函数调用！" << endl;
		if (pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_Size = m_Capacity = 0;
		}
	}

	//其他操作
	//1.添加元素（尾插法）
	void Push_Back(T a)
	{
		if (this->m_Size == this->m_Capacity)
		{
			cout << "错误：数组内存已满，无法再进行添加操作！"<<endl;
			return;
		}
		this->pAddress[this->m_Size++] = a;

	}

	//2.删除元素（尾删法）
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			cout << "错误：数组中已经没有元素，无法再进行删除操作！" << endl;
			return;
		}
		this->m_Size--;  //逻辑上删除
	}

	//3.通过下标访问数组元素
	T& Get_element(int index)
	{
		if (index < 0 || index >= this->m_Size)
		{
			cout << "错误：下标超过了数组可访问的界限" << endl;
			//return ;
		}
		return this->pAddress[index];

		
	}

	//4.获取数组的所有元素
	void Get_allelement()
	{
		cout << "----------------------------------------" << endl;
		cout << "当前数组内容为：" << endl;
		for (int i = 0; i < this->m_Size; i++)
		{
			cout << this->pAddress[i]<<" 、";
		}
		cout << endl;
		cout << "----------------------------------------" << endl;
	}

	//5.获取数组容量和数组大小
	void Get_CapacityandSize()
	{
		cout << "----------------------------------------" << endl;
		cout << "数组容量为：" << this->m_Capacity << endl;
		cout << "当前数组大小为：" << this->m_Size << endl;
		cout << "----------------------------------------" << endl;
	}

	//6.通过对象直接访问数组
	T& operator[](int index)
	{
		return  this->Get_element(index);
	}

	//7。获取数组大小
	int Ger_Size()
	{
		return this->m_Size;
	}

};




