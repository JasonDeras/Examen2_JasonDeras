all:
	g++ Tupla.cpp \
	Relacion.cpp \
	Main.cpp \
	-o Ejecutable
cleanup:
	rm Ejecutable
