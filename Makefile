TARGET := kernel.bin
CC := gcc
NASM := nasm
LD := ld
RUBYOBJS := main.o

all: $(TARGET)

kernel.bin: kernel.o loader.o $(RUBYOBJS)
	$(LD) -T linker.ld -o $(TARGET) kernel.o loader.o $(RUBYOBJS)

kernel.o: kernel.c video.h ascii.h
	$(CC) -o kernel.o -c kernel.c -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs

loader.o: loader.s
	$(NASM) -f elf -o loader.o loader.s

%.o: ruby/%.c
	$(CC) -o $@ -c $< -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs -Iinc -Irubyinc

clean:
	rm -rf $(TARGET)
	rm -rf loader.o kernel.o
	rm -rf $(RUBYOBJS)
