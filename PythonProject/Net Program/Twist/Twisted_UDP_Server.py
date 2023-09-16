import twisted
import twisted.internet.protocol
import twisted.internet.reactor

SERVER_PORT=8080

class Server(twisted.internet.protocol.DatagramProtocol):

    def datagramReceived(self, datagram, addr):    #覆写接收数据回调函数
        print('消息来源IP:%s,端口号:%s'% addr)
        print('服务端接收到数据:%s'%datagram.decode('UTF-8'))
        self.transport.write( ('[ECHO] %s'%datagram.decode('UTF-8')).encode('UTF-8'),addr)

def main():
    twisted.internet.reactor.listenUDP(SERVER_PORT,Server())   #开启监听
    print('服务器已启动！')
    twisted.internet.reactor.run()  #开启服务端循环监听

if __name__ == '__main__':
    main()