import twisted
import twisted.internet.threads  #defer线程处理
import twisted.internet.reactor
import twisted.internet.protocol
import time

SERVER_HOST='localhost'
SERVER_PORT=8080

class DeferClient(twisted.internet.protocol.Protocol):
    def connectionMade(self):  # 覆写连接成功回调函数
        print('服务器连接成功,可进行数据交互！ ');
        self.sendData()

    def dataReceived(self, data):  # 覆写接收数据回调函数
        content = data.decode('UTF-8')
       # print('接收到响应数据：%s' % content)

        twisted.internet.threads.deferToThread(self.handle_request,content).addCallback(self.handle_success)

    def handle_request(self,content):
        print('客户端接收服务端响应数据，正在进行处理...')
        time.sleep(3)   #模拟客户端处理延时
        return content

    def handle_success(self,content):
        print('处理完成！接收参数：%s'%content)
        self.sendData()


    def sendData(self):
        inputdata = input('请输入传送消息：')
        if inputdata:
            self.transport.write(inputdata.encode('UTF-8'))
        else:
            print('客户端连接结束！')
            self.transport.loseConnection()


class DefaultClientFactory(twisted.internet.protocol.ClientFactory):
    protocol = DeferClient  # 实现注册回调类
    clientConnectionLost = clientConnectionFailed = lambda self, connector, reason: \
        twisted.internet.reactor.stop()

def main():
    twisted.internet.reactor.connectTCP(SERVER_HOST,SERVER_PORT,DefaultClientFactory())  #
    twisted.internet.reactor.run()

if __name__ == '__main__':
    main()