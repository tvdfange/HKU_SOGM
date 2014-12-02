CC = g++
CFLAGS = -Wall

OBJ= guitarfxMain.o tremelo.o ampl.o

all: guitarfxMain

guitarfx: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`

