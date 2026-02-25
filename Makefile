CC=gcc
CFLAGS = -g -Wall -Wpedantic -ansi
EJS = p1_e1 p1_e2 p1_e3

# Se definen los objetos necesarios para cada ejecutable
OBJECTSP1E1 = p1_e1.o music.o radio.o
OBJECTSP1E2 = p1_e2.o music.o radio.o
OBJECTSP1E3 = p1_e3.o music.o radio.o

all: $(EJS)

p1_e1: $(OBJECTSP1E1)
	$(CC) $(CFLAGS) -o p1_e1 $(OBJECTSP1E1)

p1_e2: $(OBJECTSP1E2)
	$(CC) $(CFLAGS) -o p1_e2 $(OBJECTSP1E2)
p1_e3: $(OBJECTSP1E3)
	$(CC) $(CFLAGS) -o p1_e3 $(OBJECTSP1E3)

# Reglas de compilación de módulos
p1_e1.o: p1_e1.c
	$(CC) $(CFLAGS) -c p1_e1.c

music.o: music.c
	$(CC) $(CFLAGS) -c music.c

radio.o: radio.c
	$(CC) $(CFLAGS) -c radio.c

p1_e2.o: p1_e2.c
	$(CC) $(CFLAGS) -c p1_e2.c

p1_e3.o: p1_e3.c
	$(CC) $(CFLAGS) -c p1_e3.c

clean:
	rm -rf *.o $(EJS)

run1:
	@echo ">>>>>>Running p1_e1"
	./p1_e1

run2:
	@echo ">>>>>>Running p1_e2"
	./p1_e2
run3:
	@echo ">>>>>>Running p1_e3 with radio1.txt"
	./p1_e3 radio1.txt
runv1:
	@echo ">>>>>>Running p1_e1 with valgrind"
	valgrind --leak-check=full ./p1_e1
	
runv2:
	@echo ">>>>>>Running p1_e2 with valgrind"
	valgrind --leak-check=full ./p1_e2
runv3:
	@echo ">>>>>>Running p1_e3 with valgrind"
	valgrind --leak-check=full ./p1_e3 radio1.txt
