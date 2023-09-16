import twisted
import twisted.internet.protocol
import twisted.internet.reactor

CLIENT_PORT = 0
SERVER_HOST='127.0.0.1'

class Client(twisted.internet.protocol.DatagramProtocol):

    def startProtocol(self):
        self.transport.connect(SERVER_HOST,8080)
        print('服务器连接成功！')
        self.send()

    def datagramReceived(self, datagram, addr):  # 覆写接收数据回调函数
        print('响应数据:%s' % datagram.decode('UTF-8'))
        self.send()

    def send(self):
        inputdata = input('请输入传送消息：')
        if inputdata:
            self.transport.write(inputdata.encode('UTF-8'))
        else:
            print('客户端连接结束！')
            twisted.internet.reactor.stop()


def main():
    twisted.internet.reactor.listenUDP(CLIENT_PORT, Client())  # 开启监听
    twisted.internet.reactor.run()  # 开启服务端循环监听


if __name__ == '__main__':
    main()