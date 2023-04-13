
#需要链接的mysql库
MYSQLLIBS = -lmysqlclient

CFLAGS = -g -Wno-write-strings

all : createtable inserttable updatetable selecttable deletetable filetoblob blobtofile

createtable:createtable.cpp 
	g++ $(CFLAGS) -o createtable createtable.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc

inserttable:inserttable.cpp 
	g++ $(CFLAGS) -o inserttable inserttable.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc

updatetable:updatetable.cpp 
	g++ $(CFLAGS) -o updatetable updatetable.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc

selecttable:selecttable.cpp 
	g++ $(CFLAGS) -o selecttable selecttable.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc

deletetable:deletetable.cpp 
	g++ $(CFLAGS) -o deletetable deletetable.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc


filetoblob:filetoblob.cpp 
	g++ $(CFLAGS) -o filetoblob filetoblob.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc

blobtofile:blobtofile.cpp 
	g++ $(CFLAGS) -o blobtofile blobtofile.cpp  _mysql.cpp  $(MYSQLLIBS)   -lm -lc

clean:
	rm -rf createtable inserttable updatetable selecttable deletetable filetoblob blobtofile