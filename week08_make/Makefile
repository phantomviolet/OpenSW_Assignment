PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR = $(PROJ_DIR)/lib
LIB_NAME = libmybasic.a
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME)
BASIC_SRCS = $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
LIB_OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(BASIC_SRCS:.c=.o))
APP_TARGET = $(BIN_DIR)/myapp
APP_OBJS = $(OBJ_DIR)/myapp.o

AR =ar
CC=clang

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

$(LIB_TARGET):$(LIB_OBJS)
	$(AR) rcs $@ $^

$(BIN_DIR)/myapp: $(LIB_TARGET) $(APP_OBJS)
	$(CC) -o $(APP_TARGET) $(APP_OBJS) -L$(LIB_DIR) -lmybasic


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ -c $< -I$(INC_DIR)

.PHONY: basic clean all
all:$(APP_TARGET)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_TARGET)

basic: $(LIB_TARGET)
