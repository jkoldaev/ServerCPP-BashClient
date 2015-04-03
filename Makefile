#CC=g++

#CFLAGS=-c -Wall -lboost_system -lboost_thread

all: 
	g++ -L/usr/local/lib/ -lboost_system -lboost_thread-mt main.cpp LogicServer.cpp SocketCommand.cpp FakeDiodCApi.cpp -o server