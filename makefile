LANG=minor
EXT=min
LIB=lib
UTIL=util
RUN=run
EXS=exs
TST=tests
CC=gcc
CFLAGS=-g -DYYDEBUG


$(LANG): minor.y minor.l
	make -C $(LIB)
	byacc -dv minor.y
	flex -ld minor.l
	$(LINK.c) -o $(LANG) $(ARCH) -I$(LIB) lex.yy.c y.tab.c -L$(LIB) -l$(UTIL)

clean::
	rm -f *.o $(LANG) lib$(LANG).a lex.yy.c y.tab.c y.tab.h

examples::
	for f in *.min; do echo $$f; ./minor < $$f; done

