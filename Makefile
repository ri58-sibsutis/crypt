.PHONY: clean

bin/crypt: obj/main.o
	gcc -o bin/crypt obj/main.o

obj/main.o: src/main.c
	gcc -o obj/main.o -c src/main.c


clean:
	rm -f bin/crypt obj/main.o
