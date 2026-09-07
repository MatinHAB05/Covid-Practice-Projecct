MAINEXE=covid
run:
	gcc -o MAINEXE covid.c && .\MAINEXE
build:
	gcc -o MAINEXE covid.c

clean:
	rm MAINEXE.exe