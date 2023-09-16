import socket
#  服务端主机号和端口号
from time import sleep
import string

SERVER_HOST='192.168.1.101';
SERVER_PORT=2026;
def main():
    SERVER_HOST=socket.gethostbyname(socket.gethostname());#自动获取本机IP地址
    print("本机局域网IP地址为：",SERVER_HOST);
    #print("请输入服务器IP地址和端口号!");
    #SERVER_HOST=input("IP地址：");
    SERVER_PORT=int(input("端口号："));

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        #sleep(5);
        server_socket.bind((SERVER_HOST,SERVER_PORT))
        server_socket.listen()
        print('服务器启动，IP地址 %s,端口号 %s' % (SERVER_HOST, SERVER_PORT))
        while (True):
            con_channel,client_address = server_socket.accept()
            with con_channel:
                print('客户端地址：%s,端口号：%s'%client_address);
                con_channel.send(bytes('{Echo:TCP Connection Established}','utf-8'));
                data=con_channel.recv(100);
                print("接收到数据: %s"%data);
                print();
                con_channel.close();

if __name__ == '__main__':
    main()
