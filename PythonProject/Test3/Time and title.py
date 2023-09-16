import re
from win32com.client.gencache import EnsureDispatch as Dispatch
import pandas as pd
import xlrd,xlwt
#获取邮件内容中的时间
def Get_time(str_body):
    pattern='\d+ [a-zA-Z]+ \d+'
    index=re.search(pattern,str).span()
    return str_body[index[0]:index[1]]

def read_mail():
    #首先创建以一个工作表
    workbook = xlwt.Workbook(encoding='UTF-8')
    worksheet = workbook.add_sheet('sheet1')
    path='test.xlsx'   #工作表路径，可修改
    i=0;

    # 固定写法
    outlook = Dispatch("Outlook.Application").GetNamespace("MAPI")
    # 根级目录（邮箱名称，包括Outlook读取的存档名称）
    Accounts = outlook.Folders
    for Account_Name in Accounts:
        print('>> 正在查询的帐户名称：{}'.format(Account_Name.Name))
        # 一级目录集合（与inbox同级）['收件箱', '发件箱', '已发送', 'xxx', 'xxx']
        Level_1_Names = Account_Name.Folders
        for Level_1_Name in Level_1_Names:
            if Level_1_Name.Name=='Inbox':  #收件箱
                print('- 正在查询一级目录：{}'.format(Level_1_Name.Name))
                # 一级文件夹的mail合集[所有邮件对象]
                Mail_1_Messages = Level_1_Name.Items
                # 将邮件按接收时间排序
                Mail_1_Messages.Sort("[ReceivedTime]", True)
                # 开始查看单个邮件的信息
                for xx in Mail_1_Messages:
                    Root_Directory_Name_1 = Account_Name.Name # 记录根目录名称
                    Level_1_FolderName_1 = Level_1_Name.Name # 记录一级目录名称
                    Level_2_FolderName_1 = ''  # 一级目录肯定没有二级目录，顾留为空
                    '''
                    # 接收时间
                    if (hasattr(xx, 'ReceivedTime')):
                        ReceivedTime_1 = str(xx.ReceivedTime)[:-6]
                    else:
                        ReceivedTime_1 = ''
                    # 发件人
                    if (hasattr(xx, 'SenderName')):
                        SenderName_1 = xx.SenderName
                    else:
                        SenderName_1 = ''
                    # 收件人
                    if (hasattr(xx, 'To')):
                        to_to_1 = xx.To
                    else:
                        to_to_1 = ''
                    # 抄送人
                    if (hasattr(xx, 'CC')):
                        cc_cc_1 = xx.CC
                    else:
                        cc_cc_1 = ''
                    # 主题
                    if (hasattr(xx, 'Subject')):
                        Subject_1 = xx.Subject
                    else:
                        Subject_1 = ''
                    # 邮件MessageID
                    if (hasattr(xx, 'EntryID')):
                        MessageID_1 = xx.EntryID
                    else:
                        MessageID_1 = ''
                    # 会话主题
                    if (hasattr(xx, 'ConversationTopic')):
                        ConversationTopic_1 = xx.ConversationTopic
                    else:
                        ConversationTopic_1 = ''
                    # 会话ID
                    if (hasattr(xx, 'ConversationID')):
                        ConversationID_1 = xx.ConversationID
                    else:
                        ConversationID_1 = ''
                    # 会话记录相对位置
                    if (hasattr(xx, 'ConversationIndex')):
                        ConversationIndex_1 = xx.ConversationIndex
                    else:
                        ConversationIndex_1 = '' 
                        '''
                    # 邮件内容
                    if (hasattr(xx, 'Body')):
                        EmailBody_1 = xx.Body
                    else:
                        EmailBody_1 = ''
                    if EmailBody_1 != '':
                        time1 = Get_time(EmailBody_1)#获取邮件时间

                    # 主题
                    if (hasattr(xx, 'Subject')):
                        Subject_1 = xx.Subject
                    else:
                        Subject_1 = ''

                    worksheet.write(i,0,Subject_1)  #写入主题
                    worksheet.write(i,1, time1)   #写入时间
                    i+=1;

                worksheet.save(path)  #将工作表保存到指定路径


                '''
                # 判断当前查询的一级邮件目录是否有二级目录（若有多级目录，可以参考此段代码)
                if Level_1_Name.Folders:
                    # 二级目录的集合
                    Level_2_Names = Level_1_Name.Folders
                    for Level_2_Name in Level_2_Names:
                        print(' - - 正在查询二级目录：' , Level_1_Name.Name , '//' , Level_2_Name.Name)
                        # 二级目录的邮件集合
                        Mail_2_Messages = Level_2_Name.Items
                        # 开始查看单个邮件的信息
                        for yy in Mail_2_Messages:
                            # 记录根目录名称
                            Root_Directory_Name_2 = Account_Name.Name
                            # 记录一级目录名称
                            Level_1_FolderName_2 = Level_1_Name.Name
                            # 记录二级目录名称
                            Level_2_FolderName_2 = Level_2_Name.Name
                            
                            # 接收时间
                            if (hasattr(yy, 'ReceivedTime')):
                                ReceivedTime_2 = str(yy.ReceivedTime)[:-6]
                            else:
                                ReceivedTime_2 = ''
                            # 发件人
                            if (hasattr(yy, 'SenderName')):
                                SenderName_2 = yy.SenderName
                            else:
                                SenderName_2 = ''
                            # 收件人
                            if (hasattr(yy, 'To')):
                                to_to_2 = yy.To
                            else:
                                to_to_2 = ''
                            # 抄送人
                            if (hasattr(yy, 'CC')):
                                cc_cc_2 = yy.CC
                            else:
                                cc_cc_2 = ''
                            # 主题
                            if (hasattr(yy, 'Subject')):
                                Subject_2 = yy.Subject
                            else:
                                Subject_2 = ''
                            # 邮件MessageID
                            if (hasattr(yy, 'EntryID')):
                                MessageID_2 = yy.EntryID
                            else:
                                MessageID_2 = ''
                            # 会话主题
                            if (hasattr(yy, 'ConversationTopic')):
                                ConversationTopic_2 = yy.ConversationTopic
                            else:
                                ConversationTopic_2 = ''
                            # 会话ID
                            if (hasattr(yy, 'ConversationID')):
                                ConversationID_2 = yy.ConversationID
                            else:
                                ConversationID_2 = ''
                            # 会话记录相对位置
                            if (hasattr(yy, 'ConversationIndex')):
                                ConversationIndex_2 = yy.ConversationIndex
                            else:
                                ConversationIndex_2 = ''
                            
                            # 邮件正文内容
                            if (hasattr(yy, 'Body')):
                                EmailBody_2 = yy.Body
                            else:
                                EmailBody_2 = ''
                            if EmailBody_2 != '':
                                time2 = Get_time(EmailBody_2)
                '''



if __name__ == '__main__':
    read_mail()




