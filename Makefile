all:
	g++ Tupla.cpp \
	Relacion.cpp \
	Main.cpp \
	-o Programa
cleanup:
	rm Programa
