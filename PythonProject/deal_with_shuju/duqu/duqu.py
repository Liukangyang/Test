import xlrd as xls
import matplotlib.pyplot as plt
import numpy as np
#xlrd的版本：1.2.0 才能读取xlsx的文件，最新的2.0.1只能读取xls后缀的文件

import pandas as pd

import matplotlib.pyplot as py

'''
filename='data1.xlsx'
df=pd.read_excel(filename,sheet_name='U')
df=pd.DataFrame(df)

height,width=df.shape
print('行：%d,列：%d'%(height,width))
print('读入类型:',type(df))
print(df.columns)   #返回列名  index的集合


#直接获取数据
data=df.values
# print('数据：')
# print(data)

Ux=df.loc[0:99,'Data1_Ux___']
# Ux=Ux.values
Uy=df.loc[0:99,'Data1_Uy___']
# Uy=Uy.values
print('Ux:');print(Ux)
print('Uy');print(Uy)
time=np.zeros((100,1))
for i in range(1,len((time))+1):
    time[i-1,0]=i
    pass
print(time)

py.plot(time,Ux,c='b')
py.show()
'''


#从DataFrame结构的数据中取值有三种常用的方法：
'''
#第一种方法：ix
df.ix[i,j]		# 这里面的i,j为内置数字索引，行列均从0开始计数
df.ix[row,col]	# 这里面的row和col为表格行列索引，也就是表格中的行与列名称

#第二种方法：loc
df.loc[row,col]	# loc只支持使用表格行列索引，不能用内置数字索引
'''



#读取表格文件数据
def Duqu(filename):
    data=xls.open_workbook(filename)

    #每个文件里有5个表格（sheet）
    table1=data.sheet_by_index(0)
    table2=data.sheet_by_index(1)
    table3=data.sheet_by_index(2)
    table4=data.sheet_by_index(3)
    table5=data.sheet_by_index(4)

    time=table1.col_values(0)
    acclrn=table1.col_values(1)
    beta=table1.col_values(2)
    clutch=table1.col_values(3)
    Sw=table1.col_values(4)
    fire=table1.col_values(5)
    gate=table1.col_values(6)
    control=table1.col_values(7)
    eng=table1.col_values(8)
    phi=table1.col_values(9)
    pow=table1.col_values(10)
    R=table1.col_values(11)
    theta=table1.col_values(12)
    trq=table1.col_values(13)
    data=[time,acclrn,beta,clutch,Sw,fire,gate,control,eng,phi,pow,R,theta,trq]

    Ux=table2.col_values(0)
    Uy=table2.col_values(1)
    U=[Ux,Uy]

    Ax=table3.col_values(0)
    Ay=table3.col_values(1)
    Ay_s=table3.col_values(2)
    A=[Ax,Ay,Ay_s]

    IT1=table4.col_values(0)
    IT2=table4.col_values(1)
    IT3=table4.col_values(2)
    IT4=table4.col_values(3)
    IT=[IT1,IT2,IT3,IT4]

    Wheel_LF=table5.col_values(0)
    Wheel_LR=table5.col_values(1)
    Wheel=[Wheel_LF,Wheel_LR]

    return data,U,A,IT,Wheel

#截取小数点后几位
def export_result(num,n):
  for i in range(0,len(num)):
        num_x , num_y = str(num[i]).split('.')
        num[i] = float(num_x+'.'+num_y[0:n])
  return num



