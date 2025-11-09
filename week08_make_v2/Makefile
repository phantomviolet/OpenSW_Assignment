.PHONY: all basic_ops advanced_ops app clean

ROOT_DIR = $(shell pwd)
SRC_DIR  = $(ROOT_DIR)/src
OBJ_DIR  = $(ROOT_DIR)/obj
BIN_DIR  = $(ROOT_DIR)/bin
LIB_DIR  = $(ROOT_DIR)/lib
INC_DIR  = $(ROOT_DIR)/include

# Toolchain
CC      = clang
LDLIBS  = -lmybasic -lmyadvanced

# App
APP   := $(BIN_DIR)/myapp
SRCS  := $(wildcard $(SRC_DIR)/*.c)
OBJS  := $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

# Libs
LIB_BASIC	= $(LIB_DIR)/libmybasic.a
LIB_ADVANCED= $(LIB_DIR)/libmyadvanced.a

all: basic_ops advanced_ops $(APP)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

# App link
$(APP): $(OBJS) $(LIB_BAS) $(LIB_ADV)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) $(LDLIBS)

# Object build
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@	-I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(APP)
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean