def main():
    num=100
    print(num)
    print(id(num))
    del num  #del关键字删除变量，回收内存空间

    a=10;b=4;
    print(b/a)
    c=None
    print(type(c))

   #科学计数法
    a=10e2
    b=2.2e3

    # 复数操作
    print(a*b)
    num_com=complex(6,2)
    print('实部',num_com.real)
    print('虚部：',num_com.imag)
    print('共轭复数：',num_com.conjugate())

#字符串

    #字符串连接
    Info='LKY'
    Info+=' love YY!\" '
    print(Info)

   #多行定义
    Info='www.baidu.com'\
         ' jlu.edu.cn'\
         ' www.google.com'
    print(Info)

#引号嵌套定义
    Info='网址："www.baidu.com"'
    print(Info)

    Info="""
      网址1：'www.baidu.com'
      网址2：'jlu.edu.cn'
      网址3：'www.google.com'
    """
    print(Info)

#输入
    # num=input('请输入一个数字:')
    # print(type(num))
    # print(num)
    # num=float(num)
    # print(type(num))
    # print(num)

#格式化输出
    num=203020
    print('数值是：%10.2E'%num)
    print('数值是：%(num)f'%vars())

    print('自定义结束字符',end='。')





if __name__ == '__main__':
    main()