DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin
DIR_TEST_SRC = ./test-src
DIR_TEST_OBJ = $(DIR_OBJ)/test
DIR_TEST_BIN = ./test-bin

INCLUDES=-I${DIR_INC}

CC  = gcc
CXX = g++

# CC=clang
# CXX=clang++

CFLAGS = -g -Wall

BEST_OBJS = $(DIR_OBJ)/datatype.o $(DIR_OBJ)/utility.o $(DIR_OBJ)/main.o

TARGETS = $(DIR_BIN)/trade

all: $(TARGETS)


$(DIR_BIN)/trade: $(BEST_OBJS)
	$(CXX) -o $@ $(BEST_OBJS)

$(DIR_OBJ)/utility.o: $(DIR_SRC)/utility.cpp $(DIR_INC)/utility.h
	$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(DIR_OBJ)/datatype.o: $(DIR_SRC)/datatype.cpp $(DIR_INC)/datatype.h
	$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDES)


$(DIR_OBJ)/main.o: $(DIR_SRC)/main.cpp $(DIR_INC)/datatype.h $(DIR_INC)/utility.h
	$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDES)

############################################################
## UINT TEST

TEST_TARGETS = $(DIR_TEST_BIN)/test_utility

.PHONY:test

test: $(TEST_TARGETS)

$(DIR_TEST_BIN)/test_utility: $(DIR_TEST_OBJ)/test_utility.o $(DIR_OBJ)/utility.o $(DIR_OBJ)/datatype.o
	$(CXX) -o $@ $(DIR_TEST_OBJ)/test_utility.o $(DIR_OBJ)/utility.o $(DIR_OBJ)/datatype.o

$(DIR_TEST_OBJ)/test_utility.o: $(DIR_TEST_SRC)/test_utility.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDES)

##
############################################################

.PHONY:clean
clean:
	rm -f $(DIR_OBJ)/*.o \;
	rm -f $(TARGETS) \;


.PHONY:clean_test
clean_test:
	rm -f $(DIR_TEST_OBJ)/*.o \;
	rm -f $(TEST_TARGETS) \;
