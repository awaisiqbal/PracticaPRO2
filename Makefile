pro2.exe: pro2.o reloj.o tags.o tarea.o agenda.o
	g++ -o pro2.exe pro2.o reloj.o tags.o tarea.o agenda.o

pro2.o: pro2.cc
	g++ -c pro2.cc -D_GLIBCXX_DEBUG

reloj.o: reloj.cc reloj.hh
	g++ -c reloj.cc -D_GLIBCXX_DEBUG

tags.o: tags.cc tags.hh
	g++ -c tags.cc -D_GLIBCXX_DEBUG

tarea.o: tarea.cc tarea.hh
	g++ -c tarea.cc -D_GLIBCXX_DEBUG

agenda.o: agenda.cc agenda.hh
	g++ -c agenda.cc -D_GLIBCXX_DEBUG

empaquetar: agenda.cc agenda.hh tarea.cc tarea.hh tags.cc tags.hh reloj.cc reloj.hh
	zip ENTREGA_NOMES_AQUEST.zip agenda.cc agenda.hh tarea.cc tarea.hh tags.cc tags.hh reloj.cc reloj.hh

#
# Esta ultima opcion sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe

