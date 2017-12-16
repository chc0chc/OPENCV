CC = g++

#INC += -I. `pkg-config --cflags opencv`
#LIBS += `pkg-config --libs opencv`

TARGET = demo.bin

CFLAGS  = -g -O2 -I.. `Magick++-config --ldflags --libs`
CXXFLAGS = -g -O2 -I.. `Magick++-config --cxxflags --cppflags`

$(TARGET):demo.cpp
	$(CC)  $(CFLASS) $(CXXFLAGS) demo.cpp -o $@ 

.PHONY:clean
clean:
	rm -r  $(TARGET)
