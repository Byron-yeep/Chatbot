
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/chatbot

SRC= chatbot.c storeFile.c inOut.c match.c

# generic build details

CC=      gcc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies
