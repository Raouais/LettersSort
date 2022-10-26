CC=gcc 
CDFLAGS=-g -Wall -Werror -Wextra -Wwrite-strings -Wshadow -std=c99
PROG = init

SRC=$(wildcard *.c insertions/*.c removals/*.c utils/*.c design/*.c gamePlay/*.c)
OBJ=$(patsubst %.c , %.o, $(SRC))

default: $(PROG) 

$(PROG): $(OBJ)
	@echo Compilation: executable sera $(PROG).exe
	@$(CC) $(OBJ) $(LDFLAGS) -o $(PROG)
%.o: %.c %.h structures/%.h
utils/%.o: utils/%.c utils/%.h
removals/%.o: showList/%.c showList/%.h
insertions/%.o: insertions/%.c insertions/%.h
design/%.o: design/%.c design/%.h
gamePlay/%.o: gamePlay/%.c gamePlay/%.h

#FOR UNIX
# clean:
# 	@echo suppressions fichiers .o
# 	@rm -f $(OBJ)
# distclean:
# 	@echo suppresion de l'executable
# 	@rm $(PROG)

# FOR WINDOWS
clean:
	@echo suppressions fichiers .o
	@del /S *.o
distclean:
	@echo suppresion de l'executable
	@del $(PROG).exe
