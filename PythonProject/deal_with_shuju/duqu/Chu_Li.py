import numpy as np


'''
@零漂处理

输入：
P_kong：空转下的测量值
P_ce：特征测量值

返回：
P_zhen：去除零漂后的真实值
'''
def Ling_Piao(P_kong, P_ce):
    sum = 0
    P_zhen=np.zeros((len(P_kong),1))
    for i in range(0, len(P_kong)):
        sum += P_kong[i]
    Aver=sum/float(len(P_kong))  #误差平均值

    for i in range(0, len(P_kong)):
        P_zhen[i]=P_ce[i]-Aver

    return P_zhen   #返回真实值向量




'''
@hampel去噪处理
输入参数：
X:数据集
K:串口单边长度:默认3

返回参数：
xf:处理后的数据
'''
def hampel(X,k=3):
 length = X.shape[0] - 1
 nsigma = 3
 iLo = np.array([i - k for i in range(0, length + 1)])    #窗口左
 iHi = np.array([i + k for i in range(0, length + 1)])    #窗口右
 iLo[iLo < 0] = 0
 iHi[iHi > length] = length
 xmad = []           #记录窗口的标准差
 xmedian = []        #记录窗口中值

 for i in range(length + 1):
    w = X[iLo[i]:iHi[i] + 1]   #取窗口(从i=3开始形成2k+1长度的窗口)
    medj = np.median(w)         #计算中值
    mad = np.median(np.abs(w - medj))  #计算标准差
    xmad.append(mad)
    xmedian.append(medj)
 xmad = np.array(xmad)
 xmedian = np.array(xmedian)
 scale = 1.4826  # 缩放
 xsigma = scale * xmad
 xi = (np.abs(X - xmedian) > nsigma * xsigma)  # 找出离群点（即超过nsigma个标准差）

# 将离群点替换为中值
 xf = X.copy()
 xf[xi] = xmedian[xi]
 return xf



###-----------------------------------数据分割出处理
'''
@数据分割（按时间段划分）

输入参数:
jiasu_k：加速点对应的下标
jiansu_k：减速点对应的下标
jiashi_start_k:驾驶开始
jiashi_start_k:驾驶结束
Shuju：要分割的数据集

返回参数：
Shuju1：加速段数据
Shuju2：驾驶段数据
Shuju3：减速段数据
最终将3个列表整合为一个大列表返回
'''
def Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,Shuju):
    Shuju1=[]
    Shuju2=[]
    Shuju3=[]
    if jiasu_k < jiansu_k:
        Shuju1.append(Shuju[:jiasu_k+1])
        Shuju2.append(Shuju[jiashi_start_k:jiashi_off_k+1])
        Shuju3.append(Shuju[jiansu_k:])
        return [Shuju1,Shuju2,Shuju3]
    else:
        return None


'''
@获取时间点的下标

输入参数：
time:时间列表
time_k:待测定时间点

返回参数
k:测定时间点在time中对应的下标
'''
def Get_biao(time,time_k):

    for i in range(0,len(time)):
        if time[i] >= time_k:
           return i


'''
@全数据集分割

输入参数：
data,U,A,IT,Wheel:驾驶特征参数
tacc：加速结束时间,
tsld：减速开始时间
del_time:时间偏移量
这两个时间点需要同作图得出


返回参数：
data,U,A,IT,Wheel
按照时间段被分割的数据，
其中data包含了多个数据集，每个数据集都由3个分段列表组成
故data是3维的,如:data[0][0][]=time[0][]
U,A,IT,Wheel也是3维的

'''
def Fen_ge(data,U,A,IT,Wheel,tacc=0,tsld=1.5,del_time=0.1):

  jiasu=tacc-del_time   #加速结束
  jiansu=tsld+del_time   #减速开始
  jiashi_start=tacc+del_time  #驾驶开始
  jiashi_off=tsld-del_time    #驾驶结束

  time=data[0]

  jiasu_k=Get_biao(time,jiasu)
  jiansu_k=Get_biao(time,jiansu)
  jiashi_start_k=Get_biao(time,jiashi_start)
  jiashi_off_k=Get_biao(time,jiashi_off)

  time=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[0])
  acclrn=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[1])
  beta=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[2])
  clutch=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[3])
  Sw=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[4])
  fire=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[5])
  gate=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[6])
  control=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[7])
  eng=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[8])
  phi=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[9])
  pow=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[10])
  R=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[11])
  theta=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[12])
  trq=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,data[13])
  data = [time, acclrn, beta, clutch, Sw, fire, gate, control, eng, phi, pow, R, theta, trq]

  Ux=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,U[0])
  Uy=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,U[1])
  U=[Ux,Uy]

  Ax=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,A[0])
  Ay=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,A[1])
  Ay_s=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,A[2])
  A=[Ax,Ay,Ay_s]

  IT1=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,IT[0])
  IT2=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,IT[1])
  IT3=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,IT[2])
  IT4=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,IT[3])
  IT=[IT1,IT2,IT3,IT4]

  Wheel_LF=Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,Wheel[0])
  Wheel_LR= Fen(jiasu_k,jiansu_k,jiashi_start_k,jiashi_off_k,Wheel[1])
  Wheel=[Wheel_LF,Wheel_LR]

  return data,U,A,IT,Wheel





