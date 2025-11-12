.PHONY: all clean dynamic

PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
BIN_DIR=$(PROJ_DIR)/bin
LIB_DIR=$(PROJ_DIR)/lib
INC_DIR=$(PROJ_DIR)/include
TARGET=$(BIN_DIR)/myapp
LIB_OBJ=$(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
CC=clang

$(TARGET): $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmyops.1.0.dylib
	$(CC) $(OBJ_DIR)/myapp.o -Llib -lmyops -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

$(LIB_DIR)/libmyops.1.0.dylib: $(LIB_OBJ)
	$(CC) -dynamiclib $^ -o $@
	ln 	-s	$(LIB_DIR)/libmyops.1.0.dylib $(LIB_DIR)/libmyops.1.dylib
	ln	-s	$(LIB_DIR)/libmyops.1.dylib $(LIB_DIR)/libmyops.dylib

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* $(LIB_DIR)/*