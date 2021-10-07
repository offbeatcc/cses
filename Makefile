*.cc: clean
	c++ -g -std=c++11 -Wall -Wextra -pedantic "$@" 2>&1
	sh test/test.sh "$@"
	make clean

clean:
	rm -rf *.out *.dSYM input.txt expected.txt output.txt

css: FORCE
	curl -sS https://offbeatcc.github.io/css/main.css -o web/main.css

pset:
	curl -sS https://cses.fi/problemset/ -o /tmp/problemset.html
	sbcl --script pset.lisp > problemset.md

pub:
	git diff --exit-code
	git diff --cached --exit-code
	git push
	cd ../offbeat && make pub

FORCE:
