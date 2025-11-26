#ifndef __FRIENDMODEL_HPP__
#define __FRIENDMODEL_HPP__

#include "user.hpp"
#include <vector>
using namespace std;

// 维护好友关系操作类
class FriendModel
{
public:
    // 添加好友关系
    void insert(int userid, int friendid);

    // 查询并返回用户好友列表
    vector<User> query(int userid);
};

#endif