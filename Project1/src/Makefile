# Makefile to make the voting_system executable and the Java display

EXEFILE = voting_system
SRCFILES = $(wildcard *.cpp) $(wildcard *.cc)
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(SRCFILES))))

JAVAFILES = $(wildcard *.java)
JAVACLASSES = $(JAVAFILES:.java=.class)

.PHONY: clean

all: $(EXEFILE)

%.class: %.java
	javac display.java

%.o: %.cc
	g++ -c $< -o $@

$(EXEFILE): $(OBJFILES) | $(JAVACLASSES)
	g++ $(OBJFILES) -o $@

clean:
	rm -f *.o
	rm -f $(EXEFILE)
	rm -f audit.txt
	rm -f *.class
