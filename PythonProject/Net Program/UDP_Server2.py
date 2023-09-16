import socket
#  服务端主机号和端口号
SERVER_HOST='127.0.0.1';
SERVER_PORT=2020;

def main():
    SERVER_HOST=socket.gethostbyname(socket.gethostname());#自动获取本机IP地址
    print("本机局域网IP地址为：",SERVER_HOST);
    #print("请输入服务器IP地址和端口号!");
    #SERVER_HOST=input("IP地址：");
    SERVER_PORT=int(input("端口号："));

    with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as server_socket:
        server_socket.bind((SERVER_HOST,SERVER_PORT))
        print('服务器启动，IP地址 %s,端口号 %s' % (SERVER_HOST,SERVER_PORT))
        while True:
            data,client_addr=server_socket.recvfrom(50)
            data=data.decode('UTF-8')
            print('客户端地址：%s,端口号：%s'%client_addr);
            print("接收到数据： %s"%data);
            print();

            echo_data=('{[ECHO] %s}'%data).encode('UTF-8')
            if data.upper()=='BYEBYE':
                server_socket.sendto('exit'.encode('UTF-8'), client_addr)
            else:
                server_socket.sendto(echo_data,client_addr)


if __name__ == '__main__':
    main()