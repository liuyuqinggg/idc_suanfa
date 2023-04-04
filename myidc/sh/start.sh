#启动数据中心后台服务程序的脚本

#检查服务程序是否超时，配置在/etc/rc.local中由root用户执行
#/home/lyq/project/mytools/bin/procctl 10 /home/lyq/project/mytools/bin/checkproc  /home/lyq/project/tem/log/checkproc.log

#压缩数据中心后台服务程序的日志
/home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/gzipfiles /home/lyq/project/tem/surfdata/ "*" 0.01

#生成观测数据
/home/lyq/project/mytools/bin/procctl 60 /home/lyq/project/myidc/bin/crtsurfdata /home/lyq/project/myidc/ini/stcode.ini /home/lyq/project/tem/surfdata\
  /home/lyq/project/myidc/log/crtsurfdata.log xml,json,csv 

#清理观测数据历史文件
/home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/deletefiles /home/lyq/project/tem/surfdata/ "*" 0.02

