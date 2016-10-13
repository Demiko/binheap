CC=clang

all: binheap

binheap: binheap.c
	gcc -o binheap binheap.c
test: binheap
	seq 1 100 | sort -R | perl -lne 'push@r,$$_;END{print@r+0;print for@r}' | $(CURDIR)/binheap
clean:
	rm binheap
