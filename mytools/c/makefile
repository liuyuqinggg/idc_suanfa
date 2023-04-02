PUBINCL = -I/home/lyq/project/public

PUBCPP = /home/lyq/project/public/_public.cpp

CFLAGS = -g

all:procctl checkproc 进程维护自己的心跳信息_封装成类  gzipfiles deletefiles

procctl:procctl.cpp 
		g++ -o procctl procctl.cpp
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

clean:
	rm -f procctl checkproc 进程维护自己的心跳信息_封装成类 gzipfiles deletefiles

