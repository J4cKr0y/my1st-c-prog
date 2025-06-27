all: bonjour

bonjour: bonjour.c
	gcc bonjour.c -o bonjour

clean:
	rm -f bonjour
