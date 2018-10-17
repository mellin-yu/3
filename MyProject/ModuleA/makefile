CC=gcc
YL=-I../Include/
stu:
	$(CC) -c *.c $(YL) 
	ar -rsv ../RELEASE/libstu.a *.o
	mv *.o ../RELEASE/
clean:
	rm ../RELEASE/*.o ../RELEASE/libstu.a
	
