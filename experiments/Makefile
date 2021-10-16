*.cc: clean
	c++ -g -std=c++11 -Wall -Wextra -pedantic "$@" 2>&1
	./a.out

mod_operator:
	-c++ -std=c++11 -Wall -Wextra -pedantic "$@.cc" && ./a.out
	-cc -std=c89 -Wall -Wextra -pedantic "$@.c" && ./a.out
	-node "$@.js"
	-javac ModOperator.java && java ModOperator
	-python3 "$@.py"

billion_loop:
	c++ -O2 -std=c++11 -Wall -Wextra -pedantic "$@.cc" && time ./a.out

clean:
	rm -rf *.out *.dSYM input.txt expected.txt output.txt

FORCE:
