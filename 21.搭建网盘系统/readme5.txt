登陆注册注销

// 数据库操作
-> win + r
-> sqlite3 + 地址 + .db
-> 用户信息表
-> create table usrInfo(id integer primary key autoincrement, // 用户表 id（整型） 主键 自动增长
   name varchar(32) unique,
   pwd varchar(32),
   online integer default 0);                                 // 判断是否登录过

-> 好友表
-> create table friend(id integer, friendId integer,
   primary key(id, friendId));                                 // 主键的作用，唯一确定一条记录

-> .tables
-> .quit

-> insert into usrInfo(name,pwd) values('jack','jack'),
-> ('rose','rose'),('lucy','lucy');
->  select * from usrInfo;       // 查看创建的数据库
--------------------------------------------------
// 登录注册注销请求
-> 将数据库操作类定义成单例




--------------------------------------------------
// 登录注册注销回复




--------------------------------------------------
