# Makefile to make the voting_system executable and the Java display

EXEFILE = voting_system
SRCFILES = $(wildcard *.cpp) $(wildcard *.cc)
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(SRCFILES))))

JAVAFILES = $(wildcard *.java)
JAVACLASSES = $(JAVAFILES:.java=.class)

.PHONY: clean

all: $(EXEFILE)

%.class: %.java
	javac $<

%.o: %.cpp
	g++ -c $< -o $@

%.o: %.cc
	g++ -c $< -o $@

$(EXEFILE): $(OBJFILES) | $(JAVACLASSES)
	g++ -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 $(OBJFILES) -o $@

clean:
	rm -f *.o
	rm -f $(EXEFILE)
	rm -f audit.txt
	rm -f temp.txt
	rm -f result.txt
	rm -f path.txt
	rm -f *.class
	rm -rf ../documentation/html
	rm -rf ../documentation/latex
