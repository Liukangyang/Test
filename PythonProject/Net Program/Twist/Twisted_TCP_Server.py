import twisted
import twisted.internet.protocol
import twisted.internet.reactor

SERVER_PORT=8080
class Server(twisted.internet.protocol.Protocol):
    def connectionMade(self):    #覆写连接成功回调函数
        print('客户端地址:%s'%self.transport.getPeer().host)


    def dataReceived(self,data):    #覆写接收数据回调函数
        print('服务端接收到数据:%s'%data.decode('UTF-8'))
        self.transport.write( ('ECHO %s'%data.decode('UTF-8')).encode('UTF-8')   )



class DefaultServerFactory(twisted.internet.protocol.ServerFactory):
    protocol=Server   #实现注册回调类

def main():
    twisted.internet.reactor.listenTCP(SERVER_PORT,DefaultServerFactory())   #开启监听
    print('服务器已启动！')
    twisted.internet.reactor.run()  #开启服务端循环监听

if __name__ == '__main__':
    main()

