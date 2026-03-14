INCLUDE_DIR = include
OBJ_DIR = obj
SRC_DIR = src

PROG = main.exe
CC = x86_64-w64-mingw32-g++
CFLAGS = -Wall -Wextra -fPIC -c -I$(INCLUDE_DIR) -std=c++14

_DEPS = Cercle.h Forme.h FormeCharger.h FormeChargerCercle.h FormeChargerFormeComposee.h FormeChargerPolygone.h FormeChargerSegment.h FormeChargerTriangle.h FormeComposee.h FormeSauvegarder.h FormeSimple.h FormeVisiteur.h Matrice22.h Polygone.h Segment.h Triangle.h Vecteur2D.h MaWinsock.h FormeDessiner.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ= Cercle.o Forme.o FormeCharger.o FormeChargerCercle.o FormeChargerFormeComposee.o FormeChargerPolygone.o FormeChargerSegment.o FormeChargerTriangle.o FormeComposee.o FormeSauvegarder.o FormeSimple.o FormeVisiteur.o Matrice22.o Polygone.o Segment.o Triangle.o Vecteur2D.o MaWinsock.o FormeDessiner.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

.PHONY: all memorycheck clean

all : $(PROG) ./$(PROG)

memorycheck : $(PROG)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG)

clean :
	rm -f $(OBJ_DIR)/*.o

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

$(PROG) : $(OBJ) $(OBJ_DIR)/Main.o
	$(CC) -o $@ $^ -lm -lws2_32 -static-libgcc -static-libstdc++ -static -lpthread