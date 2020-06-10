# Имя компилятора
CC=g++

# Стандарт
STD=c++11

.PHONY: all

all: exec clear

exec: MyDoor.o MQTTDoor.o MosqMQTTWrapper.o main.o
	$(CC) -I"/usr/local/include" -L"/usr/local/lib" MosqMQTTWrapper.o MQTTDoor.o MyDoor.o main.o -o exec -lmosquitto -lmosquittopp
MyDoor.o: MyDoor.hpp
	$(CC) -std=$(STD) -c MyDoor.cpp -o MyDoor.o
MQTTDoor.o: MQTTDoor.hpp
	$(CC) -std=$(STD) -c MQTTDoor.cpp -o MQTTDoor.o 
MosqMQTTWrapper.o: MosqMQTTWrapper.hpp
	$(CC) -std=$(STD) -c MosqMQTTWrapper.cpp -o MosqMQTTWrapper.o
main.o: 
	$(CC) -std=$(STD) -c main.cpp -o main.o
clear:
	rm -rf *.o
