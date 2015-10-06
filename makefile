GCC=gcc
CFLAGS=-Wall

LDIR=libs
ODIR=objs
BLD=builds

#_DEPS = tlib.h tarray.h ttypes.h
#DEPS=$(patsubst %,$(LDIR)/%,$(_DEPS))

_OBJS = main.o tarray.o menu.o tpersona.o tbanco.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: app

#$(OBJS): $(ODIR)/%.o: $(SRC)/%.c $(DEPS)
#	$(GCC) -c -o $@ $< $(CFLAGS) -I$(LDIR)

#$(ODIR)/tlib.o: $(LDIR)/tarray.c $(DEPS)
#	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

$(ODIR)/tarray.o: $(LDIR)/tarray.c $(LDIR)/tarray.h $(LDIR)/ttypes.h
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

$(ODIR)/menu.o: $(LDIR)/menu.c $(LDIR)/menu.h $(ODIR)/tarray.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

$(ODIR)/tpersona.o: $(LDIR)/tpersona.c $(LDIR)/tpersona.h $(ODIR)/tarray.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

$(ODIR)/tbanco.o: $(LDIR)/tbanco.c $(LDIR)/tbanco.h $(ODIR)/tpersona.o $(ODIR)/tarray.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

$(ODIR)/main.o: main.c $(ODIR)/menu.o $(ODIR)/tarray.o $(ODIR)/tpersona.o $(ODIR)/tbanco.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS)

app: $(OBJS)
	$(GCC) -o $(BLD)/$@ $^ -I$(LDIR) $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BLD)/app
