hespi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./bin/InfixPostfix ./lib/Hata.o ./lib/Stack.o ./src/InfixPostfix.cpp
	
calistir:
	./bin/InfixPostfix