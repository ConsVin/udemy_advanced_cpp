# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = gcc                        # compiler to use

LINKERFLAG = -lm
CXXFLAGS='-std=c++17'


SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%)

all: ${BINS}

%: %.o
		@echo "Checking.."
		${CC} ${LINKERFLAG} -I./ $< -o $@
%.o: %.cpp
		@echo "Creating object.."
		${CC} ${CXXFLAGS} -c   $<

clean:
		@echo "Cleaning up..."
		rm -rvf *.o ${BINS}