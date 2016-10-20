test: myTunez.c
	gcc newMyLink.c myTunez.c -0 test

run: test
	./test

clean:
	rm *~;
	rm *.o;
