all: corpo empresa funcionario funcoesGerencia menu
	g++ teste/corpo.o teste/empresa.o teste/funcionario.o teste/funcoesGerencia.o teste/menu.o -o teste/teste -Wall
corpo: corpo.cpp
	g++ corpo.cpp -c -o teste/corpo.o -Wall
empresa: empresa.cpp
	g++ empresa.cpp -c -o teste/empresa.o -Wall
funcionario: funcionario.cpp
	g++ funcionario.cpp -c -o teste/funcionario.o -Wall
funcoesGerencia: funcoesGerencia.cpp
	g++ funcoesGerencia.cpp -c -o teste/funcoesGerencia.o -Wall
menu: menu.cpp
	g++ menu.cpp -c -o teste/menu.o -Wall