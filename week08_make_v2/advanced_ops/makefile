.PHONY: all advanced_ops clean

PROJ_DIR = $(shell pwd)
ROOT_DIR = $(PROJ_DIR)/..

SRC_DIR  = $(PROJ_DIR)/src
OBJ_DIR  = $(PROJ_DIR)/obj
INC_DIR  = $(ROOT_DIR)/include
LIB_DIR  = $(ROOT_DIR)/lib

LIB_NAME   = libmyadvanced.a
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME)

BASIC_SRCS = $(SRC_DIR)/mymod.c $(SRC_DIR)/mypow.c
LIB_OBJS   = $(subst $(SRC_DIR), $(OBJ_DIR), $(BASIC_SRCS:.c=.o))

AR = ar
CC = clang

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

# make lib 
advanced_ops: $(LIB_TARGET)

# make lib/libmyadvanced.a
$(LIB_TARGET): $(LIB_OBJS)
	$(AR) rcs $@ $^

# make obj files obj/*.o 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_TARGET)