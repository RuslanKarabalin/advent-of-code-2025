PROG ?= template
TESTNUM ?= 01

run:
	g++ -O2 -lm -fno-stack-limit -std=c++23 -x c++ $(PROG)/$(PROG).cpp -o $(PROG).x && \
		./$(PROG).x < $(PROG)/in$(TESTNUM).txt && rm $(PROG).x

generate:
	mkdir -p $(PROG) && cp template/template.cpp $(PROG)/$(PROG).cpp && cp template/in01.txt $(PROG)/in01.txt

format:
	clang-format -i $$(find . \
		-name '*.cpp' -o -name '*.cc' -o -name '*.c' \
		-o -name '*.hpp' -o -name '*.hh' -o -name '*.h')
