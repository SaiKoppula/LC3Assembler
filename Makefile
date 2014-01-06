#  Assembler Makefile
#  Author: Sai Koppula
#  Created: January 2014
#  Updated: January 2014
#  Adapted from UIUC CS225 Spring 2013 MP7 Makefile

EXES = assemble
OBJS = main.o parser.o lib.o

CXX = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
CXX_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)

.PHONY: all clean

all: $(EXES)

clean:
	-rm *.o $(EXES) 2>/dev/null

tidy:
	-rm -rf doc

$(EXES): $(OBJS)
	$(CXX) -o $@ $^

main.o: main.cpp parser.o lib.o
	$(CXX) $(CXX_OPTS) $<

parser.o: parser.cpp parser.h
	$(CXX) $(CXX_OPTS) $<

lib.o: lib.cpp lib.h
	$(CXX) $(CXX_OPTS) $<

