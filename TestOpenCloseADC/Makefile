CC=gcc #-std=c99
IDIR =../include
LDIR =../lib 
CFLAGS=-Wall -I$(IDIR)
OUTPUT = RunTestADC

all: $(OUTPUT)

# $@ is the left side of : and $^ is the right side
$(OUTPUT): TestOpenCloseADC.o ../lib/JB_ADC.o
	$(CC) -o $@ $^ $(CFLAGS)

TestOpenCloseADC.o: TestOpenCloseADC.c
	$(CC) -c $< $(CFLAGS)

JB_ADC.o: JB_ADC.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *o $(OUTPUT)

rebuild: clean all
