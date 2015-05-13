program.exe: program.o reloj.o tags.o tarea.o agenda.o
	g++ -o program.exe program.o reloj.o tags.o tarea.o agenda.o

program.o: program.cc
	g++ -c program.cc -D_GLIBCXX_DEBUG

reloj.o: reloj.cc reloj.hh
	g++ -c reloj.cc -D_GLIBCXX_DEBUG

tags.o: tags.cc tags.hh
	g++ -c tags.cc -D_GLIBCXX_DEBUG

tarea.o: tarea.cc tarea.hh
	g++ -c tarea.cc -D_GLIBCXX_DEBUG

agenda.o: agenda.cc agenda.hh
	g++ -c agenda.cc -D_GLIBCXX_DEBUG

practica.tar: agenda.cc agenda.hh Makefile program.cc reloj.cc reloj.hh tags.cc tags.hh tarea.cc tarea.hh
	tar -cvf practica.tar agenda.cc agenda.hh Makefile program.cc reloj.cc reloj.hh tags.cc tags.hh tarea.cc tarea.hh

#
# Esta ultima opcion sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe

