import enum

from dingyi.tt2 import *
# 枚举
from enum import Enum

@enum.unique
class Week(Enum):
    MONDAY = 0
    TUESDAY = 1
    WEDNESDAY = 2
    THURSDAY = 3
    FRIDAY = 4
    SATURDAY = 5
    SUNDAY = 6

#生成器
def genertor(maxnum):
    for num in range(1,maxnum):
        if num==3 :
            return '结束'
        else:
            yield '{num}'.format(num=num)

def wrap_generator(iterable):
    yield from iterable

def gene():
    print('step1')
    res=yield'yootk-001'#接收数据
    print('step2')
    yield 'yootk-%s'%res

def main():
    '''
    mess=Message('lky',22)
    mess.print_title()
    mess.print_url()

    print(Message.get_info())

    mess2=Message.get_instance('lky-22')
    mess2.get_info2()

    mess2.__name='yy'
    print(mess2.__name)
    print(mess2.__dict__)
    del mess2.__name
    print(mess2.__dict__)
    '''

    # #异常处理
    # try:
    #     '''
    #     numa=float(input('输入被除数:'))
    #     numb=float(input('输入除数:'))
    #     result=numa/numb
    #     print('结果：%d'%result)
    #     '''
    #     raise NameError('名称错误')
    # except Exception as err:
    #     print('程序出现异常：%s'%err)
    # else:
    #     print('程序正常执行')
    # finally:
    #     print('程序执行完毕')
    #
    # with Message('LKY',22) as mess:
    #     mess.send()
    #     mess.get_info2()
    #
    # try:
    #     Food.eat(98)
    # except Bomb as err:
    #     print('产生异常：%s'%err)
#集合
    # seta=set('abcd')
    # setb=set('acxy')
    # #seta.add('www.baidu.com')
    # #print(seta)
    # print('交集:%s'%seta.intersection(setb))
    # print('差集:%s'%seta.difference(setb))
    # print('对称差集:%s'%seta.symmetric_difference(setb))
    # print('并集%s'%seta.union(setb))
    #
    # seta.clear()
    # print(seta)

#双端队列
# from collections import deque
# info_deque=deque(('hello','LKY'))
# info_deque.append('后端数据')
# info_deque.appendleft('前端数据')
# print(info_deque)
# print('队列长度：%d'%info_deque.__len__())
# print('从队列右边弹出数据:%s'%info_deque.pop())
# print('从队列左边弹出数据:%s'%info_deque.popleft())
# print(info_deque)
# print('队列长度：%d'%info_deque.__len__())
# info_deque.reverse()
# print(info_deque)

#heapq堆
# import heapq
# data=[4,6,2,7,9,1]
# heapq.heapify(data)
# heapq.heappush(data,0)
# print(data)
# print(heapq.nlargest(7,data))
# print(heapq.nsmallest(7,data))
# heapq.heappop(data)
# print(data)

#枚举类型
'''
2. 枚举取值
2.1 通过成员的名称来获取成员
Color['red']
2.2 通过成员值来获取成员
Color(2)
2.3 通过成员，来获取它的名称和值
red_member = Color.red red_member.name red_member.value
'''
# Friday=Week.FRIDAY
# print(Friday)
# print(Friday.name,Friday.value)
#
# en=Week(0)
# print(en)
# print(en.name)


#生成器
'''格式
g = fib(6)
>>> while True:
...     try:
...         x = next(g)
...         print('g:', x)
...     except StopIteration as e:
...         print('Generator return value:', e.value)
...         break
'''
# for item in genertor(10):
#     print(item)
#
# g=genertor(9)
# for item in wrap_generator(g):
#     print(item)
#
# gg=gene()
# print('通过next函数调用返回的结果：%s'%next(gg))
# print('通过send函数向yiedl发送数据，返回结果:%s'%gg.send(666))

'''压制异常
from contextlib import suppress
with suppress(异常类型):
 代码块
 
意义：代码块中一旦出现特定的异常类型，则直接跳过，不报错

'''
#
# from contextlib import contextmanager
# class message:
#     def send(self,info):
#         print('[message]发送消息：%s'%info)
#
# @contextmanager
# def message_wrap():
#     class __connect:
#         def build(self):
#             print('连接建立')
#             return True
#
#         def close(self):
#             print('连接通道关闭')
#
#     try:
#         conn=__connect()
#         if conn.build():
#             yield message()
#         else:
#             yield None
#     except:
#         print('连接出现异常')
#     finally:
#         conn.close()
#
# with message_wrap() as msg:
#     msg.send('helloworld!')

'''
#正则表达式
from re import *
print('字符串匹配结果:%s'%match('yootk','yootk.com'))
print('字符串匹配结果:%s'%match('yootk','www.yootk.com'))
print('字符串匹配结果:%s'%search('yootk','www.yootk.com'))

#正则匹配符
str1='food'
str2='fo[ol][dl]'
#print(match(str2,str1,I))

str1='hello food'
pattern='food'
print(findall(pattern,str1))

input_data=(input('输入日期：'))
pattern='[0-9]{4}-[0-9]{2}-[0-9]{2}'
if match(pattern,input_data,I):
    print('日期格式输入正确!')
else:
    print('格式输入错误！')
'''
from re import *
# tel=input('输入电话号码')
# pattern=r'((\d{3,4})|(\(\d{3,4}\)-))?\d{7,8}'
# if match(pattern,tel):
#     print('号码输入格式正确')
# else:
#    print('输入格式错误')


#正则模式
data="""
 a is Food
 Food is b
 Food is c
 """
pattern1='Fo{2}d'
result=findall(pattern1,data,I|M)
print('匹配结果:%s'%result)

pattern2='.+'
print(findall(pattern2,data))
print(findall(pattern2,data,S))


pattern3=r"""
  [a-zA-Z0-9]
  \w+@\w+
  \.
  (cn|con|com|net)
"""
# data=input('请输入邮箱地址：')
# if match(pattern3,data,I|X):
#     print('输入格式正确')
# else:
#     print('格式错误')


#正则分组
'''
pattern4=r'(?P<year>\d{4})-(?P<month>\d{2})-(?P<day>\d{2})'
data=input('输入日期')
result=match(pattern4,data)
print(result)
print('year:%s'%result.group('year'))
print('month:%s'%result.group('month'))
print('day:%s'%result.group('day'))
'''

info='id:yootk,tel:110;id:LKY,tel:120'
pattern4=r'(?<=id:)(?P<name>\w+)'
pattern5=r'(?=L)(?P<name>\w+)'
result1=findall(pattern4,info)
result2=findall(pattern5,info)
print(result1)
print(result2)




if __name__=='__main__':
    main()