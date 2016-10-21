test: myTunez.c
	gcc main.c newMyLink.c myTunez.c -o test

run: test
	./test

clean:
	rm *~;
	rm *.o;
