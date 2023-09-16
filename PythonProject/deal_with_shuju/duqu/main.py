from duqu import *
from Chu_Li import *

'''
所有函数定义都在引入的函数文件中
'''
def main():

    # 导入文件读取数据
    # filename='ay_left_data0.xlsx'  #文件名/文件路径
    data, U, A, IT, Wheel = Duqu(filename='ay_left_data0.xlsx')
    time = data[0]  # 获取时间
    print('数据长度:', len(time))

    # 截取数据的长度（测试）
    time = export_result(time, 4)
    Ux = export_result(U[0], 4)
    Uy = export_result(U[1], 4)


    ###数据预处理
    #去除零漂：Ling_Piao(P_kong, P_ce)

    #hample去噪：hampel(X,k=3)

    #数据集分割：
    data,U,A,IT,Wheel=Fen_ge(data, U, A, IT, Wheel, tacc=0.33, tsld=1.73,del_time=0.01)

    #测试
    print('加速段:',data[1][0])
    print('驾驶段:',data[1][1])
    print('减速段:',data[1][2])






if __name__ == '__main__':
    main()