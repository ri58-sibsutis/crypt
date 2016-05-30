.PHONY: clean

bin/crypt: obj/main.o obj/affine.o obj/caesar.o obj/substitution.o obj/viginere.o obj/verrnam.o
	gcc -Wall -o bin/crypt obj/main.o obj/affine.o obj/caesar.o obj/substitution.o obj/viginere.o obj/verrnam.o

obj/main.o: src/main.c
	gcc -Wall -o obj/main.o -c src/main.c

obj/affine.o: src/affine.c
	gcc -Wall -o obj/affine.o -c src/affine.c

obj/caesar.o: src/caesar.c
	gcc -Wall -o obj/caesar.o -c src/caesar.c

obj/substitution.o: src/substitution.c
	gcc -Wall -o obj/substitution.o -c src/substitution.c

obj/viginere.o: src/viginere.c
	gcc -Wall -o obj/viginere.o -c src/viginere.c

obj/verrnam.o: src/verrnam.c
	gcc -Wall -o obj/verrnam.o -c src/verrnam.c

clean:
	rm -f bin/crypt obj/*.o
