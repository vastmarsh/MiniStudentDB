#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
private:
    sqlite3* db;  // SQLite 数据库句柄

public:
    // 构造函数：打开数据库
    Database(const std::string& filename);

    // 析构函数：关闭数据库
    ~Database();

    // 执行 SQL 语句
    bool execute(const std::string& sql);
};

#endif