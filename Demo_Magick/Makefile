CC = g++

#INC += -I. `pkg-config --cflags opencv`
#LIBS += `pkg-config --libs opencv`
INC += -I/usr/local/include/ImageMagick-7
LIBS += -L/usr/local/lib -lMagick++-7.Q16HDRI

TARGET = demo.bin

CFLAGS  = -g -O2 -I$(INC) -I.. `Magick++-config --ldflags --libs`
#CXXFLAGS = -g -O2 -I.. `Magick++-config --cxxflags --cppflags`

$(TARGET):demo.cpp
	$(CC)  $(INC)  demo.cpp -o $@  $(LIBS)
	#$(CC)  $(INC)  demo.cpp -o $@  /usr/local/lib/libMagick++-7.Q16HDRI.so

.PHONY:clean
clean:
	rm -r  $(TARGET)
