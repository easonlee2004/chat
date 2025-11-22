#ifndef __CHATSERVER_HPP__
#define __CHATSERVER_HPP__

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
using namespace muduo;
using namespace muduo::net;
using namespace std;

// 服务器主类
class ChatServer
{
public:
    // 初始化聊天服务器对象
    ChatServer(EventLoop* loop,
               const InetAddress& listenAddr,
               const string& nameArg);

    // 启动服务
    void start();

private:
    // 连接和断开回调函数
    void onConnection(const TcpConnectionPtr& conn);

    // 读写事件回调函数
    void onMessage(const TcpConnectionPtr& conn,
                   Buffer* buffer,
                   Timestamp time);

    TcpServer _server; // 实现服务器功能的类对象
    EventLoop* _loop; // 指向事件循环的指针
};

#endif