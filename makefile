CC = gcc
CFLAGS = -O3 -g
LIBS = -lz
OBJS = rescue_ngs.o mg_string.o mg_vector.o
TARGET = rescue
.SUFFIEXES : .c .o

all : $(TARGET)

$(TARGET) : $(OBJS)
  $(CC) $(CFLAGS) -o $@ $^ $(LIBS)
  
