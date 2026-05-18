hepsi: hatalar derle calistir

hatalar:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp

derle:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Stack.o ./lib/Hata.o ./src/test.cpp
	
calistir:
	./bin/test