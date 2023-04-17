PUBINCL = -I/home/lyq/project/public

PUBCPP = /home/lyq/project/public/_public.cpp

#需要链接的mysql库
MYSQLLIBS = -lmysqlclient

# 开发框架mysql的cpp文件名，这里直接包含进来，没有采用链接库，是为了方便调试。
MYSQLCPP = /home/lyq/project/public/db/mysql/_mysql.cpp

# mysql头文件存放路径
MYSQLINCL = -I/home/lyq/project/public/db/mysql

CFLAGS = -g

all:procctl checkproc 进程维护自己的心跳信息_封装成类  gzipfiles deletefiles \
 ftpgetfiles  ftpputfiles tcpputfiles tcpserver tcpgetfiles execsql dminingmysql \
 xmltodb

procctl:procctl.cpp 
		g++ -g -o procctl procctl.cpp $(PUBINCL) $(PUBCPP)  -lm -lc
		mv procctl ../bin/

checkproc: checkproc.cpp
		g++ $(CFLAGS) -o checkproc checkproc.cpp  $(PUBINCL) $(PUBCPP)  -lm -lc
		mv checkproc ../bin/
进程维护自己的心跳信息_封装成类: 进程维护自己的心跳信息_封装成类.cpp
		g++ $(CFLAGS) -o 进程维护自己的心跳信息_封装成类 进程维护自己的心跳信息_封装成类.cpp $(PUBINCL) $(PUBCPP)  -lm -lc

gzipfiles: gzipfiles.cpp
		g++ $(CFLAGS) -o gzipfiles gzipfiles.cpp $(PUBINCL) $(PUBCPP)  -lm -lc
		mv gzipfiles ../bin/

deletefiles: deletefiles.cpp
		g++ $(CFLAGS) -o deletefiles deletefiles.cpp $(PUBINCL) $(PUBCPP)  -lm -lc
		mv deletefiles ../bin/
ftpgetfiles: ftpgetfiles.cpp
		g++ $(CFLAGS) -o ftpgetfiles ftpgetfiles.cpp $(PUBINCL) $(PUBCPP)  /home/lyq/project/public/_ftp.cpp /home/lyq/project/public/ftplib.c -L/home/lyq/project/public  -lm -lc
		mv ftpgetfiles ../bin/

ftpputfiles: ftpputfiles.cpp
		g++ $(CFLAGS) -o ftpputfiles ftpputfiles.cpp $(PUBINCL) $(PUBCPP)  /home/lyq/project/public/_ftp.cpp /home/lyq/project/public/ftplib.c -L/home/lyq/project/public  -lm -lc
		mv ftpputfiles ../bin/
tcpputfiles: tcpputfiles.cpp
		g++ $(CFLAGS) -o tcpputfiles tcpputfiles.cpp $(PUBINCL) $(PUBCPP)    -lm -lc
		mv tcpputfiles ../bin/
tcpgetfiles: tcpgetfiles.cpp
		g++ $(CFLAGS) -o tcpgetfiles tcpgetfiles.cpp $(PUBINCL) $(PUBCPP)    -lm -lc
		mv tcpgetfiles ../bin/
tcpserver: tcpserver.cpp
		g++ $(CFLAGS) -o tcpserver tcpserver.cpp $(PUBINCL) $(PUBCPP)    -lm -lc
		mv tcpserver ../bin/

execsql:execsql.cpp 
	g++ $(CFLAGS) -o execsql execsql.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLCPP)  $(MYSQLLIBS) -lm -lc
	mv execsql ../bin/

dminingmysql:dminingmysql.cpp 
	g++ $(CFLAGS) -o dminingmysql dminingmysql.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLCPP)  $(MYSQLLIBS) -lm -lc
	mv dminingmysql ../bin/

xmltodb:xmltodb.cpp 
	g++ $(CFLAGS) -o xmltodb xmltodb.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLCPP)  $(MYSQLLIBS) -lm -lc
	mv xmltodb ../bin/

clean:
	rm -f procctl checkproc 进程维护自己的心跳信息_封装成类 gzipfiles deletefiles ftpgetfiles ftpputfiles tcpputfiles tcpserver tcpgetfiles 
	rm execsql dminingmysql xmltodb

