#/******************************************************************************
#*  ASR => 4R2.04                                                              *
#*******************************************************************************
#*                                                                             *
#*  N° de Sujet : Sujet 2                                                      *
#*                                                                             *
#*******************************************************************************
#*                                                                             *
#*  Intitulé : Analyse adresse IP                                              *                
#*                                                                             *
#*******************************************************************************
#*                                                                             *
#*  Nom-prénom1 : AL-HABSI Ayoub                                               *              
#*                                                                             *
#*  Nom-prénom2 : BAYCHE Baptiste                                              *             
#*                                                                             *
#*  Nom-prénom3 : ASSELINE Téo                                                 *          
#*                                                                             *
#*  Nom-prénom4 : WEIDNER Arthur                                               *            
#*                                                                             *
#*******************************************************************************
#*                                                                             *
#*  Nom du fichier : makefile                                                  *
#*                                                                             *
#******************************************************************************/

CC = gcc
CFLAGS = -g
SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})

all : ${BINAIRES}
	${CC} ${CFLAGS} -o main $^

main.o : analyseIP.h

analyseIP.o : analyseIP.h

clean :
	rm -f main
	rm -f *.o

