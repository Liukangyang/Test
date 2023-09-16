def add(*numbers):
    """

    :param numbers: 对多个数据进行累加
    :return: 累加结果
    """
    sum=0
    for item in numbers:
        sum+=item
        pass
    return sum


#Student类定义
class Student:
    def set_info(self,name,age):
        self.name=name
        self.age=age
        pass

    def get_info(self):
        print('学生信息：名字%s 年龄：%d'%(self.name,self.age))
        pass
    pass

#属性封装
class Member:
    '''
    #构造方法
    def __init__(self,name,age):
        self.__name=name
        self.__age=age'''
    info = '共享属性'
    #同时支持有参和无参构造方法：使用关键字参数
    def __init__(self,**info):
      self.__name=info.get("name")
      self.__age=info.get("age")

    def set_name(self,name):
        self.__name=name

    def set_age(self,age):
        self.__age=age

    def get_name(self):
        return self.__name

    def get_age(self):
        return self.__age

    def change(self,temp):
        temp.__name='YY'

        #析构方法
    def __del__(self):
        print('该对象将被释放，对象地址为'+str(id(self)))


class Member2:
    __slots__ = ('name','age')#用于限定实例对象的属性范围，使得对象不可以添加自己的属性
    def __init__(self,name,age):
      self.name=name
      self.age=age

    def get_name(self):
          return self.name

    def get_age(self):
          return self.age

    def send(self):
        con=Member2
        con.printf()

    def fun(self):
        out_obj=self
        class inner:
            def printf(self):
                print(out_obj.get_name())
        inner().printf()


class People:
    def __init__(self,**kk):
        self.__name=kk.get('name')
        self.__age = kk.get('age')
        self.__children=[]

    def set_car(self,car):
        self.__car=car

    def get_car(self):
        return self.__car

    def get_info(self):
         return '[People类]姓名：%s 年龄：%d'%(self.__name,self.__age)

    def get_children(self):
        return self.__children

class Car:
    def __init__(self, **kk):
        self.__brand = kk.get('brand')
        self.__price= kk.get('price')

    def set_people(self, people):
        self.__people = people

    def get_people(self):
        return self.__people

    def get_info(self):
        return '[Car类]牌子：%s 价格：%d' % (self.__brand, self.__price)


class Person:
    '''def __init__(self,name,age):   #当父类构造函数有参数时，需通过子类将参数传递至父类的构造方法
        self.__name=name
        self.__age=age
        print('父类构造方法')'''
    def __init__(self):
        print('Person类构造')


    def set_name(self,name):
        self.__name=name

    def get_name(self):
        return self.__name

    def set_age(self,age):
        self.__age=age

    def get_age(self):
        return self.__age

    def Achieve(self):
        print('人的成就')

    def __init_subclass__(cls, **kwargs):
        print('cls=%s'%cls)
        print('kwargs=%s'%kwargs)

class Student(Person,info='Student',teacher='LJ'):
    '''def __init__(self,name,age):
        self.__school=None
        super().__init__(name,age)#调用父类构造方法
        print('子类构造方法')'''
    def __init__(self):
        print('Student类构造')

    def set_school(self,school):
        self.__school=school

    def get_school(self):
        return self.__school

    def Achieve(self):
        #super().Achieve()
        print('考上清华北大！')#在父类方法的基础上子类再进行扩充


class Worker(Person):
    def __init__(self):
      print('worker类构造')
    def Achieve(self):
        print('造出大国重器')

class Channel:
    def __new__(cls, *args, **kwargs):
        print('[new]cls=%s'%cls)
        return object.__new__(cls)

    def __init__(self):
        print('[init]')

    def __str__(self):
        return 'str方法覆写'

    def __repr__(self):
        return 'repr方法覆写'

    def printf(self,person):
        if isinstance(person,Person):
             print(person.Achieve())
        else:
            print('传入对象错误')
#多继承
class People:
    info='公共属性'
    def __init__(self,name,age):
        self.name=name
        self.age=age
        print('People类构造')
#对象比较实现
    def __le__(self, other):
        if not isinstance(other,People) or other==None:
            return False
        else:
            return self.age<=other.age
   # 对象直接调用函数实现
    def __bool__(self):
     return self.age > 18

#对象格式化定义
    def __format__(self, format_spec):
        if format_spec=='':
            return str(self)
        format_data=format_spec.replace('%name',self.name).replace('%age',str(self.age))

        return format_data
 #可调用对象函数call
    def __call__(self, *args, **kwargs):
        return '对象的直接调用'

    def __getattr__(self, item):#属性不存在时的捕获
        print('%s属性不存在!'%item)

'''
    def __getattribute__(self, item):
        if item == 'name':
            return self.name
        elif item=='age':
            return self.age
        else:
            return object.__getattribute__(self,item)
'''

#工厂设计模式：工厂函数
def get_person_instace(cls):
    if cls=='student':
        return Student()
    elif cls=='worker':
        return Worker()
    else :
        print('无对应的类别！')

class Message:
    def __init__(self,max):
        self.max=max
        self.value=0
        self.list=[1,2,3,4,5,6]
        self.dict={}

    def __iter__(self):   #允许通过对象直接迭代
        return self


    def __next__(self):
        if self.max<=self.value:  #实际循环判断条件
            raise StopIteration()#抛出异常，实现自动退出for循环
        else:
            val=self.max-self.value
            self.value+=1   #循环中的变量自增
            return val
    #捕获器
    def __getattribute__(self, item):
        if item=='content':
           print('shuxing')
        elif item=='send':
            print('send')
        else:
            return object.__getattribute__(self,item)

    def send(self,info):
        print('Message:%s'%info)

    def __reversed__(self):
        self.list=reversed(self.list)

    def __setitem__(self, key, value):
        print('设置字典元素')
        self.dict[key]=value

    def __getitem__(self, item):
        print('获取字典元素')
        return self.dict[item]

    def __delitem__(self, key):
        print('删除字典元素')
        self.dict.pop(key)

    def __len__(self):
        return len(self.dict)























