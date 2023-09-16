import urllib3

YOOTK_URL='http://www.yootk.com/video/3'

request_header={'User-Agent':'Yootk Python'}

http=urllib3.PoolManager(num_pools=10,headers=request_header)
response = http.urlopen('GET',YOOTK_URL)
print('响应头部信息：',response.headers)
print('响应内容:',response.data.decode('UTF-8'))
