GCC=gcc
CFLAGS=-Wall

LDIR=libs
ODIR=objs
BLD=builds

_DEPS = tlib.h tarray.h ttypes.h
DEPS=$(patsubst %,$(LDIR)/%,$(_DEPS))

_OBJS = tlib.o main.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: app

#$(OBJS): $(ODIR)/%.o: $(SRC)/%.c $(DEPS)
#	$(GCC) -c -o $@ $< $(CFLAGS) -I$(LDIR)

$(ODIR)/tlib.o: $(LDIR)/tarray.c $(DEPS)
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

$(ODIR)/main.o: main.c $(ODIR)/tlib.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

app: $(OBJS)
	$(GCC) -o $(BLD)/$@ $^ -I$(LDIR) $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BLD)/*
