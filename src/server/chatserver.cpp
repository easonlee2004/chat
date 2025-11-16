#include "chatserver.hpp"
#include "json.hpp"
#include <functional>
#include <string>
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

// 初始化聊天服务器对象
ChatServer::ChatServer(EventLoop* loop, const InetAddress& listenAddr,
                       const string& nameArg)
    : _server(loop, listenAddr, nameArg), _loop(loop)
{
    // 注册链接回调
    _server.setConnectionCallback(bind(&ChatServer::onConnection, this, _1));

    // 注册消息回调
    _server.setMessageCallback(bind(&ChatServer::onMessage, this, _1, _2, _3));

    // 设置线程数量
    _server.setThreadNum(4);
}

// 启动服务
void ChatServer::start()
{
    _server.start();
}

// 连接和断开回调函数
void ChatServer::onConnection(const TcpConnectionPtr& conn)
{
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

// 读写事件回调函数
void ChatServer::onMessage(const TcpConnectionPtr& conn,
                   Buffer* buffer,
                   Timestamp time)
{
    string buf = buffer->retrieveAllAsString();
    // 反序列化
    json js = json::parse(buf);
}
