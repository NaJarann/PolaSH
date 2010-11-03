APPL = polash

#
### Paramètres de compilation et d’édition de liens
#
CC = gcc
LD = $(CC)
CFLAGS = -c -g
LDFLAGS = -g 

## Librairies
LIBS =

#
# Executables de l’application
#
EXEC = $(APPL)

#
## Objets de l’application
#
OBJ1 = main.o
OBJ2 = polash.o
OBJ3 = polaparser.o

#
## Sources de l’application
#
SRC1 = main.c
SRC2 = polash.c
SRC3 = polaparser.c
INCL2 = polash.h
INCL3 = polaparser.h

# Règle d’inférence, construction des .o a partir des .c

.SUFFIXES: .o .c

$(OBJ1): $(SRC1)
	$(CC) $(LDFLAGS) $(SRC1) $(SRC2)

$(OBJ2): $(SRC2)
	$(CC) $(LDFLAGS) $(SRC2) $(SRC3)

$(OBJ3): $(SRC3)
	$(CC) $(LDFLAGS) $(SRC3)

#
# Cibles et leurs actions
# 
all: $(EXEC)

$(APPL): $(OBJ1) $(OBJ2) $(OBJ3)
	$(LD) $(LDFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(LIBS) -o $@
#
clean:
	-@rm $(OBJS) $(EXEC) core 1>/dev/null 2>&1
#
tar:
	tar cvf $(APPL1).tar $(SOURCES)
#                                         
archive: tar
	$(COMPRESS) $(APPL2).tar
#
