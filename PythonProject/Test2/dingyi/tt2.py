#import wrapt
def record():
    import inspect
    name = inspect.stack()[1][3]
    print('进入{fun}()'.format(fun=name))

#装饰器
def loggin(func):
    def wrapper(*args, **kwargs):
        print('进入{fun}()'.format(fun=func.__name__))
        return func(*args, **kwargs)

    return wrapper

#带有接收参数的装饰器
def loggin2(level='INFO'):
    def wrapper(func):
        def inner_wrapper(*args, **kwargs):
          print('[loggin-{lel}]进入{fun}()'.format(lel=level,fun=func))
          return func(*args, **kwargs)
        return inner_wrapper
    return wrapper

#定义装饰器类
class Loggin:
    def __init__(self,level='INFO'):
        self.__level=level

    def __call__(self, func):
        def wrapper(*args, **kwargs):
            print('[Loggin={lel}]进入{fun}()'.format(lel=self.__level,fun=func.__name__))
            return func(*args, **kwargs)
        return  wrapper

#通过wrapt模块来实现装饰器，避免嵌套
'''
def logging(level):
    @wrapt.decorator
    def wrapper(wrapped, instance, args, kwargs):
        print "[{}]: enter {}()".format(level, wrapped.__name__)
        return wrapped(*args, **kwargs)
    return wrapper
'''

class Message:
    def __init__(self,name,age):
        self.__name=name
        self.__age=age

    #@loggin2(level='DEBUG')  #装饰器说明
    @Loggin('TITLE')
    def print_title(self):
        #record()
        print('吉大通信')

    #@loggin2()
    @Loggin('URL')
    def print_url(self):
        #record()
        print('www.jlu,edu.cn')

#静态方法
    @staticmethod
    def get_info():
        return 'www.baidu.com'

    #类方法装饰
    @classmethod
    def get_instance(cls,info):
        result=info.split('-')
        return cls(result[0],result[1])

    def get_info2(self):
        print(self.__name,self.__age)

    #属性装饰器简化属性访问
    @property
    def info(self):
        return self.__name

    @info.setter
    def info(self,info):
        self.__name=info

    @info.deleter
    def info(self):
        del self.__name

    def send(self):
        print('发送消息！')

    def __enter__(self):
        print('with语句开始执行')
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print('with语句执行完毕')

#自定义异常类型
class Bomb(Exception):
    def __init__(self,msg='Bomb'):
        self.msg=msg

    def __str__(self):
        return self.msg

class Food:
    @staticmethod
    def eat(num):
        if num>99:
            raise Bomb()
        else:
            print('刚刚好！')








