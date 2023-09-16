import socket
#  服务端主机号和端口号
SERVER_HOST = '127.0.0.1';
SERVER_PORT = 8080;

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
        while True:
            input_data=input('请输入发送的消息:')
            data=client_socket.sendto(input_data.encode('UTF-8'),(SERVER_HOST,SERVER_PORT))
            echo_data=client_socket.recv(50).decode('UTF-8')
            if echo_data.upper()=='EXIT':
                print('客户端结束发送！')
                break;
            else:
                print('服务器响应：%s'% echo_data)



if __name__ == '__main__':
    main()