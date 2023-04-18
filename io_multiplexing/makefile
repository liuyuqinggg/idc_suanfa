all:tcpselect client tcppoll tcpepoll inetd rinetd rinetdin

tcpselect:tcpselect.cpp
	g++ -g -o tcpselect tcpselect.cpp 
client:client.cpp
	g++ -g -o client client.cpp 
tcppoll:tcppoll.cpp
	g++ -g -o tcppoll tcppoll.cpp 
tcpepoll:tcpepoll.cpp
	g++ -g -o tcpepoll tcpepoll.cpp 
inetd:inetd.cpp 
	g++ -g -o inetd inetd.cpp /home/lyq/project/public/_public.cpp
rinetd:rinetd.cpp 
	g++ -g -o rinetd rinetd.cpp /home/lyq/project/public/_public.cpp

rinetdin:rinetdin.cpp 
	g++ -g -o rinetdin rinetdin.cpp /home/lyq/project/public/_public.cpp

clean:
	rm tcpselect client tcppoll tcpepoll inetd rinetd rinetdin