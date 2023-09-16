from copy import deepcopy
import numpy as np

'''函数模块定义

输入电池电量数组和选择电池数量
输出个电池的开关状态数组
'''
def battery_selet(battery,select_num):
    remain_num=len(battery)-select_num
    status=list(np.ones((1,len(battery))))
    listbatt = []
    for j in range(remain_num):
        minbatt = 100
        for i in range(num):
            if battery[i] <= minbatt and battery[i] != -1:
                minbatt = battery[i]
                min = deepcopy(i)
        listbatt.append(minbatt)
        battery[min] = -1
        status[0][min] = 0
    return status,listbatt

battery1=[100,90,55,60,24,90,92,10]
num=len(battery1)
print('总电池个数：',num)
print('各电池电量：',battery1)
select=int(input('选择电池数量:'))#选取电池数
battery2=deepcopy(battery1)

status,listbatt=battery_selet(battery1,select_num=select)

print('最低的电池电量数组：',listbatt)
print('电池开关状态：',status)















