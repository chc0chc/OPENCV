INCLUDES = -I/usr/local/include/opencv
LIBS= -lopencv_core -lopencv_imgproc -lopencv_highgui
LIBDIRS= -L/usr/local/lib

CC= g++

SOURCE= ./*.cpp
OBJ= test

$(OBJ):$(SOURCE)
	$(CC) -o $(OBJ) $(SOURCE) $(INCLUDES) $(LIBDIRS) $(LIBS) 
clean: 
	rm -f $(OBJ) 

