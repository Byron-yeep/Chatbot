
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/chatbot

SRC= chatbot.c storeFile.c converse.c match.c

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

chatbot.o:  chatbot.c struct.h storeFile.h converse.h match.h
storeFile.o: storeFile.c struct.h storeFile.h
converse.o: converse.c struct.h converse.h
match.o: match.c struct.h match.h