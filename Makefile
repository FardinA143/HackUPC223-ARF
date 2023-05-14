SFML_OPTIONS = -lsfml-graphics -lsfml-window -lsfml-system
all: main

main: main.o Enemy.o Player.o EnemyPool.o 
	g++ main.o Enemy.o Player.o EnemyPool.o -o HackRooms $(SFML_OPTIONS)

EnemyPool.o: EnemyPool.cc Enemy.cc
	g++ -c EnemyPool.cc

Enemy.o: Enemy.cc Player.cc
	g++ -c Enemy.cc

Player.o: Player.cc
	g++ -c Player.cc

main.o: main.cc
	g++ -c main.cc 


clean:
	rm *.o
	rm ./HackRooms

run:
	./HackRooms


