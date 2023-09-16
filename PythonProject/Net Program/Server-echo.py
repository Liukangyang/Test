import socket
#  服务端主机号和端口号
SERVER_HOST='localhost';
SERVER_PORT=8080;

def main():
    with socket.socket() as server_socket:
        server_socket.bind((SERVER_HOST,SERVER_PORT))
        server_socket.listen()
        print('服务器启动，端口号：%s'%SERVER_PORT)
        print('等待连接')
        con_channel,client_address = server_socket.accept()
        with con_channel:
            print('客户端地址：%s,端口号：%s'%client_address)
            con_channel.send('服务端的连接响应！你好!'.encode('UTF-8'));
            while True:
                recv_data=con_channel.recv(100).decode('UTF-8')
                if  recv_data.upper()=='BYEBYE':
                    con_channel.send('exit'.encode('UTF-8'))
                    break;
                else:
                    con_channel.send(('[ECHO] %s'%recv_data).encode('UTF-8'))


if __name__ == '__main__':
    main()
