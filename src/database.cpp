#include "database.h"
#include <iostream>

Database::Database(const std::string& filename) {
    // 尝试打开数据库
    if (sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Cannot open database: " << filename << std::endl;
        db = nullptr;
    } else {
        // 初始化 student 表（如果不存在则创建）
        std::string init_sql =
            "CREATE TABLE IF NOT EXISTS student ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT NOT NULL,"
            "age INTEGER,"
            "score REAL);";

        execute(init_sql);
    }
}

Database::~Database() {
    if (db) {
        sqlite3_close(db);
    }
}

bool Database::execute(const std::string& sql) {
    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}