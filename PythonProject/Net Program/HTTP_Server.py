import socket
import multiprocessing

class HTTPServer:
    def __init__(self,port):
        self.server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        self.server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
        self.server_socket.bind(('0.0.0.0',port))
        print('服务器端启动')
        self.server_socket.listen()

    def start(self):
        while True:
           client_con,client_add =self.server_socket.accept()
           print('[客户端连接]客户IP:%s,访问端口:%s'%client_add)
           handle_process=multiprocessing.Process(target=self.handle_response,args=(client_con,))
           handle_process.start()

    def handle_response(self,client_con):
        request_header =client_con.recv(100).decode('UTF-8')
        print('客户端请求头部信息：',request_header)
        response_line='HTTP/1.1 200 OK\r\n'   #响应状态码
        response_headers='Server:Yootk Server\r\nContent-Type:text/html\r\n'   #响应头部信息

        response_body="<html>" \
                      "<head>" \
                        "<title> 吉林大学</title>" \
                      "</head>" \
                      "<body>" \
                      "<h1>毕业快乐！</h1>" \
                      "</body>" \
                      "</html>"
        response_data=response_line+response_headers+'\r\n'+response_body
        client_con.send(response_data.encode('UTF-8'))  #返回响应数据
        client_con.close()   #关闭连接

if __name__ == '__main__':
    http_server= HTTPServer(80);
    http_server.start()


