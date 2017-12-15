CC = g++

CFLAGS += -g -O3 -Wall
INC += -I./include
LIBS += 

TARGET = main.bin
OBJS += main.o \
SRC = ./*.cpp

#all:$(TARGET)
#$(TARGET):$(OBJS)
#	$(CC) $(INC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
#$(OBJS):%.o:%.cpp
#	$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(TARGET): $(SRC)
	$(CC) -g $(INC) $(CFLASS) *.cpp  -o $@ $(LIBS)

.PHONY:clean
clean:
	rm -r  $(TARGET)
