SOURCEFILES = main.cpp
DEPFILES = $(SOURCEFILES)

all : TestAlign

TestAlign: $(DEPFILES)
	g++ -O3 -march=native $(SOURCEFILES) -lpthread -o TestAlign

clean:
	rm -f TestAlign
