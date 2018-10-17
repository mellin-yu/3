CC=gcc
YL=-I../Include/
class:
	$(CC) -c *.c $(YL)
	ar -rsv ../RELEASE/libclass.a *.o
	mv *.o ../RELEASE/
clean:
	rm ../RELEASE/*.o ../RELEASE/libclass.a
