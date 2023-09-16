def main():
    #数学运算符
    a=2;b=3
    result=a**b
    print(result)

    print(b//a)  #整除

    info1='www.'
    info2='baidu.com '
    print(info1+info2)
    print(info2*3)

    age=16
    print(18<=age<30)

    age=18;sex='Woman'
    if age>=18 and sex=='Man':
        print('成年男性')
    elif age>=18 and sex=='Woman':
        print('成年女性')
    else:
        print('未成年')

    a=8;b=3
    print('a:',bin(a))
    print('b：',bin(b))
    result=a & b
    print('按位与结果：',result,bin(result))
    result=a ^ b
    print('按位异或结果:',result,bin(result))
    result=a << b
    print('左移结果:',result,bin(result))

    a=10;b=10.0
    print(id(a),id(b),a is not b)  #身份运算符


if __name__ == '__main__':
    main()