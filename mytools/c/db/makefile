# mysql head file directory
MYSQLINCL = -I/usr/local/mysql/include

#需要链接的mysql库
MYSQLLIBS = -lmysqlclient

CFLAGS = -g

all : createtable

createtable:createtable.cpp 
	g++ $(CFLAGS) -o createtable createtable.cpp $(MYSQLINCL) $(MYSQLLIBS)  _mysql.cpp -lm -lc
clean:
	rm -rf createtable