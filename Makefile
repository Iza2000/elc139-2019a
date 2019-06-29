FLAGS=-O3 -std=c++11 

RM=rm -f

EXEC=mandelbrot

all: $(EXEC)

$(EXEC):
	$(CXX) $(FLAGS) $(EXEC).cpp -fopenmp -c -o $(EXEC).o
	$(CXX) $(FLAGS) $(EXEC).o -o $(EXEC)

clean:
	$(RM) $(EXEC).o $(EXEC)
