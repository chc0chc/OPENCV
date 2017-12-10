CC = g++

CFLAGS += -g -O3 -Wall
INC += -I. `pkg-config --cflags opencv`
LIBS += `pkg-config --libs opencv` -lfreeimage 

TARGET = main.bin
OBJS += main.o \
SRC = Test_Fr.cpp

#all:$(TARGET)
#$(TARGET):$(OBJS)
#	$(CC) $(INC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
#$(OBJS):%.o:%.cpp
#	$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(TARGET): Test_Fr.cpp
	$(CC) -g $(INC) $(CFLASS) Test_Fr.cpp  -o $@ $(LIBS)

.PHONY:clean
clean:
	rm -r  $(TARGET)
