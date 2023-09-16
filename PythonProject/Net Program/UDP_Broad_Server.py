import socket
#  服务端主机号和端口号
BOARDCAST_SERVER_ADDR=('<broadcast>',2121)
def main():
    with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as server_socket:
        server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_BROADCAST,1)
        while True:
            send_data=input('请输入要发送的数据：')
            if send_data:
                server_socket.sendto(send_data.encode('UTF-8'),BOARDCAST_SERVER_ADDR)
            else:
                print('无发送数据！')

        #server_socket.sendto('你好我是刘康杨！'.encode('UTF-8'),BOARDCAST_SERVER_ADDR)

if __name__ == '__main__':
    main()