CC = gcc
CFLAGS = -O3 -g
LIBS = -lz
OBJS = recue_ngs.o mg_string.o mg_vector.o
TARGET = rescue_ngs

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean :
	rm ./*.o rescue_ngs
