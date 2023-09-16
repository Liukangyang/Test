import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestRegressor  #随机森林回归预测
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
if __name__ == '__main__':
    ##导入数据
    data=pd.read_csv(r"C:\Users\Jason\Desktop\data1.csv",encoding='utf-8')
    print(data.columns.values)
    y=data['output'].values  #输出
    x=data.iloc[:,1:].values  #特征因素
    print(x.shape);

    ##切分数据
    x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3)
    print(x_train.shape);
    print(x_test.shape);

    ##数据标准化





    pass




