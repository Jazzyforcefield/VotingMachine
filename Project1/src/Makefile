EXEFILE = voting_system
SRCFILES = $(wildcard *.cpp) $(wildcard *.cc)
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(SRCFILES))))

.PHONY: clean

all: $(EXEFILE)

%.o: %.cc
	g++ -c $< -o $@

$(EXEFILE): $(OBJFILES)
	g++ $(OBJFILES) -o $@

clean:
	rm -rf *.o
	rm -rf $(EXEFILE)
