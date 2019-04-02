all: main/main.c read/read.o errors/errors.o calc/calc.o plot/plot.o approx/approx.o static
	cc -o project main/main.c read/read.o errors/errors.o calc/calc.o plot/plot.o approx/approx.o splines/static.a

static:
	make -C splines

read.o: read/read.c read/read.h calc/calc.h

errors.o: errors/errors.c errors/errors.h

calc.o: calc/calc.c calc/calc.h read/read.h approx/approx.h

plot.o: plot/plot.c plot/plot.h calc/calc.h

approx.o: approx/approx.c approx/approx.h splines/points.h splines/splines.h

.PHONY: clean

clean:
	rm *.o

.PHONY: plot

plot:
	gnuplot -p plik.gp

test1:
	./project 
