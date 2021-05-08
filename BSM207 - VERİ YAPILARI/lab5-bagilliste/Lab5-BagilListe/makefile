hepsi: derle calistir
Nesneler :=  ./lib/Hata.o ./lib/Hatalar.o ./lib/Dugum.o ./lib/ListeGezici.o ./lib/BagilListe.o

derle:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/Hatalar.o -c ./src/Hatalar.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/ListeGezici.o -c ./src/ListeGezici.cpp
	g++ -I ./include/ -o ./lib/BagilListe.o -c ./src/BagilListe.cpp
	g++ -I ./include/ -o ./bin/test $(Nesneler) ./src/test.cpp
	
calistir:
	./bin/test