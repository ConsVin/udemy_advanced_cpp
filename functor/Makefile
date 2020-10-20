# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = gcc                        # compiler to use

LINKERFLAG = -lm

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%)

all: ${BINS}

%: %.o
		@echo "Checking.."
		${CC} ${LINKERFLAG} $< -o $@
%.o: %.cpp
		@echo "Creating object.."
		${CC} -c   -std=c++17 $<

clean:
		@echo "Cleaning up..."
		rm -rvf *.o ${BINS}