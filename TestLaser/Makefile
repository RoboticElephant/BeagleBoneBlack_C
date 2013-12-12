CC=gcc #-std=c99
IDIR =../include
LDIR =../lib 
CFLAGS=-Wall -I$(IDIR)
OUTPUT = TestMePlz

all: $(OUTPUT)

# $@ is the left side of : and $^ is the right side
$(OUTPUT): TestLaser.o ../lib/JB_GPIO.o ../lib/JBUtility.o
	$(CC) -o $@ $^ $(CFLAGS)

TestLaser.o: TestLaser.c
	$(CC) -c $< $(CFLAGS)

JB_GPIO.o: JB_GPIO.c
	$(CC) -c $< $(CFLAGS)

JBUtility.o: JBUtility.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *o $(OUTPUT)

rebuild: clean all
