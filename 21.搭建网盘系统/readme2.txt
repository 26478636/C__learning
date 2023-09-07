数据库安装及表设计

SQLite3数据库 dll-win64-x64 / tools-wim32-x86压缩包
    1. 将该文件，添加到系统的环境变量当中去，这样才能正常运行SQLite3
        将此路径D:\SQLite3添加到系统环境变量path中
        我的电脑->属性->高级系统设置->环境变量（需要重启）
    2. 判断是否安装成功
        打开终端输入sqlite3

数据表设计
    1. 用户信息表
        id name pwd(密码)
    2. 用户好友表
        id friendId
    ---------------------------------------------------
    打开终端 
    sqlite3 输入想要创建表格的地址/cloud.db 回车 （.db数据库文件）
    create table usrInfo(id integer primary key autoincrement,  // id 整形 主键 自动增长 
                        name varchar(32),                       // ...
                        pwd varchar(32));                       // ...
    .tables                                                     // 查看表格
    create table friendInfo(id integer not null,
    friendId integer not null,
    primary key(id friendId));
    ---------------------------------------------------
    insert into usrInfo(name,pwd) value('jack','jack'),
                                       ('rose','rose'),('lucy','lucy');
                                                                // 往表格里，插入信息
    select * from usrInfo;                                      // 查看表格信息
    .quit                                                       // 退出

