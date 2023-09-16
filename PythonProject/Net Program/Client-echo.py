import socket
#  服务端主机号和端口号
SERVER_HOST='127.0.0.1';
SERVER_PORT=8080;

def main():
    with socket.socket() as client_socket:
        client_socket.connect((SERVER_HOST,SERVER_PORT))
        print('连接建立成功！')
        #print('客户端接收信息：',client_socket.recv(50).decode('UTF-8'));
        while True:
            input_data=input('请输入发送的消息:')
            client_socket.send(input_data.encode('UTF-8'))
            echo_data=client_socket.recv(100).decode('UTF-8')
            if echo_data.upper()=='EXIT':
                print('结束连接！')
                break;
            else:
                print(echo_data)

if __name__ == '__main__':
    main()