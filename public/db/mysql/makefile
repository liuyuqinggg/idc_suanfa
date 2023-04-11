# mysql头文件存放的目录。
MYSQLINCL = -I/usr/include/mysql

# mysql库文件存放的目录。
MYSQLLIB = -L/usr/lib/x86_64-linux-gnu

# 需要链接的mysql库。
MYSQLLIBS = -lmysqlclient

CFLAGS=-g -Wno-write-strings -Wno-format

all:createtable  inserttable updatetable selecttable deletetable filetoblob blobtofile book1 book2

createtable:createtable.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o createtable createtable.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

inserttable:inserttable.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o inserttable inserttable.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

updatetable:updatetable.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o updatetable updatetable.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

selecttable:selecttable.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o selecttable selecttable.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

deletetable:deletetable.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o deletetable deletetable.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

filetoblob:filetoblob.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o filetoblob filetoblob.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

blobtofile:blobtofile.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o blobtofile blobtofile.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

book1:book1.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o book1 book1.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS)  -lm -lc

book2:book2.cpp _mysql.h _mysql.cpp
	g++ $(CFLAGS) -o book2 book2.cpp _mysql.cpp $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) -lm -lc

clean:
	rm -rf createtable  inserttable updatetable selecttable deletetable filetoblob blobtofile book1 book2
