# Makefile to make the voting_system executable and the Java display

EXEFILE = voting_system
DISPLAY = display
SRCFILES = $(wildcard *.cpp) $(wildcard *.cc)
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(SRCFILES))))

.PHONY: clean

all: $(EXEFILE)

$(DISPLAY): display.java
	javac display.java

%.o: %.cc
	g++ -c $< -o $@

$(EXEFILE): $(OBJFILES) | $(DISPLAY)
	g++ $(OBJFILES) -o $@

clean:
	rm -f *.o
	rm -f $(EXEFILE)
	rm -f audit.txt
	rm -f *.class
