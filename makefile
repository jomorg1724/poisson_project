jump_totals: jump_totals.o use_jump_totals.o
	gcc -Wall use_jump_totals.o jump_totals.o -o jump_totals

jump_totals.o: jump_totals.c jump_totals.h
	gcc -c -Wall jump_totals.c -o jump_totals.o

usemakeheaders.o: use_jump_totals.c jump_totals.h
	gcc -c -Wall use_jump_totals.c -o use_jump_totals.o
.PHONY: clean
clean:
	sudo rm -f use_jump_totals *.o *.c~ *.h~
