import socket
#  服务端主机号和端口号
SERVER_HOST='127.0.0.1';
SERVER_PORT=8080;

def main():
    with socket.socket() as client_socket:
        client_socket.connect((SERVER_HOST,SERVER_PORT))
        print('连接建立成功！')
        print('客户端接收信息：',client_socket.recv(50).decode('UTF-8'));

if __name__ == '__main__':
    main()