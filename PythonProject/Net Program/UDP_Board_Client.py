import socket
#  服务端主机号和端口号
BOARDCAST_CLIENT_ADDR=('0.0.0.0',2121)

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
        client_socket.setsockopt(socket.SOL_SOCKET,socket.SO_BROADCAST,1)  #设置为广播模式
        client_socket.bind(BOARDCAST_CLIENT_ADDR)
        print('客户端已启动！')
        while True:
            echo_data,address=client_socket.recvfrom(100)
            print('消息内容：%s,消息来源IP:%s,端口号：%s'%(echo_data.decode('UTF-8'),address[0],address[1]))



if __name__ == '__main__':
    main()