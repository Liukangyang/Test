import twisted
import twisted.internet.protocol
import twisted.internet.reactor
import re

SERVER_HOST='localhost'
SERVER_PORT=8080

class Client(twisted.internet.protocol.Protocol):
    def connectionMade(self):  # 覆写连接成功回调函数
        print('服务器连接成功!');
        self.sendData()

    def dataReceived(self, data):  # 覆写接收数据回调函数
        data=data.decode('UTF-8')
        if re.match("ECHO",data) != None:
            print('接收到响应数据：%s'%data)
        else:
            print('接收到服务器发送的数据：%s'%data)

        self.sendData()

    def sendData(self):
        inputdata=input('请输入传送消息：')
        if inputdata:
            self.transport.write(inputdata.encode('UTF-8'))
        else:
            print('客户端连接结束！')
            self.transport.loseConnection()

class DefaultClientFactory(twisted.internet.protocol.ClientFactory):
    protocol=Client   #实现注册回调类
    clientConnectionLost=clientConnectionFailed=lambda self,connector,reason:\
        twisted.internet.reactor.stop()

def main():
    twisted.internet.reactor.connectTCP(SERVER_HOST,SERVER_PORT,DefaultClientFactory())  #
    twisted.internet.reactor.run()

if __name__ == '__main__':
    main()