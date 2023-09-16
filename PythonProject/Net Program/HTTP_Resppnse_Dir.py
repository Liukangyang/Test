import socket,re,os,multiprocessing
HTML_ROOT_DIR='H:\PythonProject\html'   #HTML文件根目录

class HTTPServer:
    def __init__(self, port):
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.bind(('0.0.0.0', port))
        print('服务器端启动')
        self.server_socket.listen()

    def start(self):
        while True:
            client_con, client_add = self.server_socket.accept()
            print('[客户端连接]客户IP:%s,访问端口:%s' % client_add)
            handle_process = multiprocessing.Process(target=self.handle_response, args=(client_con,))
            handle_process.start()

    def handle_response(self, client_con):
        request_header = client_con.recv(1024).decode('UTF-8')
        print('客户端请求头部信息：', request_header)

        filename=re.match(r'\w+ +(/[^ ]*)',request_header.split('\r\n')[0]).group(1)
        if filename == '/':
            filename='index.html'

        if filename.endswith('.html') or filename.endswith('.htm'):
            client_con.send( bytes(self.get_html_data(filename),'UTF-8'))  #发送HTML文件
        else:
            client_con.send(self.get_binary_data(filename))     #发送二进制文件

        client_con.close()     #关闭连接

    def read_file(self,filename):   #读取文件
        filepath=os.path.normpath(HTML_ROOT_DIR+filename)
        file=open(filepath,'rb')
        file_data = file.read()
        file.close()
        return file_data  #返回读取的二进制文件数据

    def get_html_data(self,filename):        #获取HTML文件
        response_line = 'HTTP/1.1 200 OK\r\n'  # 响应状态码
        response_headers = 'Server:Yootk Server\r\nContent-Type:text/html\r\n'  # 响应头部信息
        response_body = self.read_file(filename).decode('UTF-8')  #响应数据

        response_data = response_line + response_headers + '\r\n' + response_body
        return response_data

    def get_binary_data(self,filename):   #获取其他二进制文件
        response_body=self.read_file(filename)
        return response_body


if __name__ == '__main__':
    http_server = HTTPServer(80);
    http_server.start()
