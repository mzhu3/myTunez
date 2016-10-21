test: myTunez.c
	gcc newMyLink.c myTunez.c -o test

run: test
	./test

clean:
	rm *~;
	rm *.o;
