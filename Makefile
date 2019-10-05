CC = cc
CFLAGS = -O2 -Wall -c -o $@


all: addsub100 do_math marathon maratho2 maratho3 muldiv muldiv2 plusmin

addsub100: src/addsub100.o 
	$(CC) -Wall -o addsub100 src/addsub100.o

do_math: src/do_math.o 
	$(CC) -Wall -o do_math src/do_math.o

marathon: src/marathon.o 
	$(CC) -Wall -o marathon src/marathon.o

maratho2: src/maratho2.o 
	$(CC) -Wall -o maratho2 src/maratho2.o

maratho3: src/maratho3.o 
	$(CC) -Wall -o maratho3 src/maratho3.o

muldiv: src/muldiv.o 
	$(CC) -Wall -o muldiv src/muldiv.o

muldiv2: src/muldiv2.o 
	$(CC) -Wall -o muldiv2 src/muldiv2.o

plusmin: src/plusmin.o 
	$(CC) -Wall -o plusmin src/plusmin.o

src/addsub100.o: src/addsub100.c

src/do_math.o: src/do_math.c

src/marathon.o: src/marathon.c

src/maratho2.o: src/maratho2.c

src/maratho3.o: src/maratho3.c

src/muldiv.o: src/muldiv.c

src/muldiv2.o: src/muldiv2.c

src/plusmin.o: src/plusmin.c

clean:
	rm -f src/*.o *.exe 

