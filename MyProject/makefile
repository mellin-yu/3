CC=gcc
YL=./RELEASE/*.a
K=./RELEASE/ -lstu -lclass
T=./Include/
main:
	make -C ./ModuleA/
	make -C ./ModuleB/
	$(CC) -o main main.c -I $(T) -L $(K)
clean:
	rm $(YL) ./RELEASE/*.o
