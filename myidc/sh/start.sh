#启动数据中心后台服务程序的脚本

#检查服务程序是否超时，配置在/etc/rc.local中由root用户执行
#sudo /home/lyq/project/mytools/bin/procctl 10 /home/lyq/project/mytools/bin/checkproc  /home/lyq/project/log/checkproc.log

#压缩数据中心后台服务程序的日志
/home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/gzipfiles /home/lyq/project/surfdata/ "*" 0.01

#生成观测数据
/home/lyq/project/mytools/bin/procctl 60 /home/lyq/project/myidc/bin/crtsurfdata /home/lyq/project/myidc/ini/stcode.ini /home/lyq/project/surfdata\
  /home/lyq/project/log/crtsurfdata.log xml,json,csv 

#清理观测数据历史文件
/home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/deletefiles /home/lyq/project/surfdata/ "*" 0.02

#下载全国气象站点观测的分钟数据
/home/lyq/project/mytools/bin/procctl 30 /home/lyq/project/mytools/bin/ftpgetfiles /home/lyq/project/log/ftpgetfiles.log "<host>127.0.0.1:21</host><mode>1</mode><username>lyq</username><password>6</password><localpath>/home/lyq/project/idcdata/</localpath><remotepath>/home/lyq/project/surfdata/</remotepath><matchname>*.xml</matchname><listfilename>/home/lyq/project/idcdata/list.data</listfilename><ptype>1</ptype><remotepathbak>/home/lyq/project//tem/surfdata/surfdatabak/</remotepathbak><okfilename>/home/lyq/project/idcdata/ftplist/ftpgetfiles_surfdata.xml</okfilename><checktime>true</checktime><timeout>20</timeout><pname>ftpgetfile_</pname>"

#上传全国气象站点观测的分钟数据
/home/lyq/project/mytools/bin/procctl 30 /home/lyq/project/mytools/bin/ftpputfiles /home/lyq/project/log/ftpputfiles.log "<host>127.0.0.1:21</host><mode>1</mode><username>lyq</username><password>6</password><localpath>/home/lyq/project/surfdata/</localpath> <remotepath>/home/lyq/project/surfdatabak/</remotepath><matchname>*.xml,*.csv</matchname><listfilename>/home/lyq/project/surfdata/list/list.data</listfilename><ptype>1</ptype><remotepathbak>/home/lyq/project/surfdatabak/</remotepathbak><okfilename>/home/lyq/project/idcdata/ftplist/ftpputfiles_surdata.xml</okfilename><checktime>true</checktime><timeout>20</timeout><pname>ftpgetfile_</pname>"

#清理下载的观测数据历史文件
/home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/deletefiles /home/lyq/project/idcdata/ "*" 0.01

#清理上传的观测数据历史文件
/home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/deletefiles /home/lyq/project/surfdatabak/ "*" 0.01

#将站点参数文件入库
/home/lyq/project/tools1/bin/procctl 120 /home/lyq/project/myidc/bin/obtcodetodb /home/lyq/project/myidc/ini/stcode.ini "127.0.0.1,root,mysql,mysql,3306" utf8 /home/lyq/project/log/obtcodetodb.log

#定期清理数据库历史数据
/home/lyq/project/mytools/bin/procctl 120 /home/lyq/project/mytools/bin/execsql /home/lyq/project/myidc/sql/cleardata.sql "127.0.0.1,root,mysql,mysql,3306" utf8 /home/lyq/project/log/execsql.log

#定期入库站点分钟数据
/home/lyq/project/mytools/bin/procctl 10 /home/lyq/project/myidc/bin/obtmindtodb /home/lyq/project/surfdatabak "127.0.0.1,root,mysql,mysql,3306" utf8 /home/lyq/project/log/obtmindtodb.log