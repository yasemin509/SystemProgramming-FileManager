CC = gcc
CFLAGS = -Wall -g
SRCDIR = src
BINDIR = bin
TARGET = $(BINDIR)/file_manager

# Kaynak dosyalar
SRC = $(SRCDIR)/file_operations.c $(SRCDIR)/directory_ops.c $(SRCDIR)/permission.c $(SRCDIR)/logger.c $(SRCDIR)/main.c

# Nesne dosyaları
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# .c dosyalarını .o dosyalarına dönüştürme
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Temizleme kuralı
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

