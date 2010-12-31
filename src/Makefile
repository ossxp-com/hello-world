OBJECTS = main.o
TARGET = hello

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean

# vim: noet
