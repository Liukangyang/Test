from dingyi.tt import *
def main():
   '''
   mem=Member(name='LKY',age='22')  #不需要使用dict方法
   print('我的名字是：',mem.get_name(),'今年我:',mem.get_age())
   print(id(mem))
   mem.info='修改后的共有属性'
   mem.height=180;
   print(mem.info)
   print(Member.info)

   Member.url='www.baidu.com'
   mem.url='www.jlu.edu.cn'
   print(mem.url)
   print(Member.url)
   mem2=Member2('LKY',22)
   print(mem2.get_name())
   print(mem2.get_age())
   mem2.fun()
'''
   '''
   #一对一关联结构
   people=People(name='LKY',age=22)
   car=Car(brand='奔驰',price=1588800.00)
   people.set_car(car)
   car.set_people(people)
   print(people.get_car().get_info())
   print(car.get_people().get_info())
   # 自身关联结构
   fubei=People(name='LKY',age=40)
   car_fu=Car(brand='奔驰',price=1588800.00)
   fubei.set_car(car_fu)
   chil1=People(name='LY',age=20)
   car1=Car(brand='劳斯莱斯',price=4929409.00)
   chil1.set_car(car1)
   chil2 = People(name='KY', age=22)
   car2 = Car(brand='大众', price=213798.00)
   chil2.set_car(car2)

  

   fubei.get_children().append(chil1)
   fubei.get_children().append(chil2)
   print(fubei.get_info(),fubei.get_car().get_info())
   for child in fubei.get_children():
      print(child.get_info())
      print(child.get_car().get_info())

  #一对多关联
   people1=People(name='LKY',age=40)
   people2=People(name='YY',age=40)
   people3=People(name='SS',age=55)
   car=Car(brand='宾利',price=2132440.00)
   people1.set_car(car)
   people2.set_car(car)
   people3.set_car(car)
   print(people1.get_info(),people1.get_car().get_info())
   print(people2.get_info(),people2.get_car().get_info())
   print(people3.get_info(),people2.get_car().get_info())
'''
'''
   #获取继承信息
   worker=Worker()
   print(worker.__class__)
   print(Worker.__bases__)
   print(Person.__subclasses__())
   print(issubclass(Worker,Person))
   print(issubclass(Worker,People))
   print(issubclass(Worker,Member))
'''
'''
person=Person()
stu=Student()
channel=Channel()
stu.Achieve()
channel.printf(stu)
print(stu.__class__.mro())

person2=get_person_instace('student')
person2.Achieve()
'''

channel=Channel()
print(channel)
print(channel.__str__())
print(repr(channel))
print(str(channel))

peo1=People('LKY',22)
peo2=People('YY',20)
if peo1:
    print('成年了！')
else:
    print('还未成年')

if peo1<=peo2:
    print('peo1年龄小')
else:
    print('peo1年龄大')

print(format(peo1,'我是%name，今年%age岁'))
print(callable(peo1))
print(peo1())
'''
#动态引入模块
util=__import__('dingyi.tt')
ADD=getattr(util,'add')
print(ADD(1,2,3,4,5,6))
'''

peo3=People('LKIO',20)
print(peo3.name)
print(peo3.age)
peo3.content='peo3的信息'
print(peo3.__dict__)
print(peo3.add)
'''
messge=Message()
messge.content='www.baidu.com'
print(messge.content)
messge.send('LKY')
'''

mess=Message(10)
for v in mess:  #对象的迭代遍历
    print(v,end=',')

print()
print(mess.list)
reversed(mess)
for i in mess.list :
    print(i,end=',')
mess['url']='www'
mess['name']='sdad'
print(mess['url'])
print(len(mess))
del mess['name']
print(len(mess))






if __name__ == '__main__':
    main()







