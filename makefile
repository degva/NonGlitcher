GCC=gcc
CFLAGS=-Wall

LDIR=libs
ODIR=objs
SRC=source
BLD=builds

_DEPS = tarray.h tlib.h ttypes.h
DEPS=$(patsubst %,$(LDIR)/%,$(_DEPS))

_OBJS = tlib.o main.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: app

$(OBJS): $(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(GCC) -c -o $@ $< $(CFLAGS) -I$(LDIR)

app: $(OBJS)
	$(GCC) -o $(BLD)/$@ $^ -I$(LDIR) $(CFLAGS) 


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BLD)/*
