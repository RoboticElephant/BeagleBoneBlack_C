CC=gcc #-std=c99
IDIR =../include
LDIR =../lib 
CFLAGS=-Wall -I$(IDIR)
OUTPUT = TestMePlz

all: $(OUTPUT)

# $@ is the left side of : and $^ is the right side
$(OUTPUT): TestPWM.o ../lib/JB_PWM.o ../lib/JBUtility.o
	$(CC) -o $@ $^ $(CFLAGS)

TestPWM.o: TestPWM.c
	$(CC) -c $< $(CFLAGS)

JB_PWM.o: JB_PWM.c
	$(CC) -c $< $(CFLAGS)

JBUtility.o: JBUtility.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *o $(OUTPUT)

rebuild: clean all
