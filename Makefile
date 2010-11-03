#
### Makefile - maintained by ViVi 
#
SRC = ./
INCL = ./
BIN = ./
OBJ = ./
LIB = ./

APPL = $(BIN)polash

## Outils
#
#SHELL = /bin/sh
PRINTER = echo
COMPRESS = gzip

#
### Paramètres de compilation et d’édition de liens
#
CC = gcc
LD = $(CC)
CFLAGS = -c -g
LDFLAGS = -g 

## Librairies
#
## Solaris
#LIBS = -lsocket -lnsl
# Linux
 LIBS =
#
# Executables de l’application
#
EXEC = $(APPL1)

#
## Objets de l’application
#
OBJ1 = $(OBJ)main.o
OBJ2 = $(OBJ)polash.o
OBJ3 = $(OBJ)polaparser.o

#

## Sources de l’application
#
SRC1 = $(SRC)main.c
SRC2 = $(SRC)polash.c
SRC3 = $(SRC)polapars.c
INCL2 = $(INCL)polash.h
INCL3 = $(INCL)polaparser.h
MANS = $(APPL).$(MANEXT)
SOURCES = README COPYRIGHT INSTALL Makefile $(SRCS) $(INCL) $(MANS)

# Règle d’inférence, construction des .o a partir des .c

#.DEFAULT: 
#	-@echo "$< n’existe pas"

.SUFFIXES: .o .c

$(OBJ1): $(SRC1)
	$(CC) $(LDFLAGS) $(SRC1) $(INCL2)

$(OBJ2): $(SRC2)
	$(CC) $(LDFLAGS) $(SRC2) $(INCL2)

$(OBJ3): $(SRC3)
	$(CC) $(LDFLAGS) $(SRC3)

#
# Cibles et leurs actions
# 
all: $(EXEC)

$(APPL2): $(OBJ2) $(OBJ3)
	$(LD) $(LDFLAGS) $(OBJ2) $(OBJ3) $(LIBS) -o $@
#
$(APPL1): $(OBJ1) $(OBJ3)
	$(LD) $(LDFLAGS) $(OBJ1) $(OBJ3) $(LIBS) -o $@
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
