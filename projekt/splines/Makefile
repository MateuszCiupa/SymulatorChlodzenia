static: points.o splines.o gaus/matrix.o gaus/piv_ge_solver.o gaus/pivot.o
	ar rvs static.a $^ 

points.o: points.c points.h

splines.o: splines.c splines.h

matrix.o: gaus/matrix.c gaus/matrix.h 

pivot.o: gaus/pivot.c gaus/matrix.h

piv_ge_solver.o: gaus/piv_ge_solver.c gaus/piv_ge_solver.h gaus/matrix.h

.PHONY: clean

clean:
	rm *.o
