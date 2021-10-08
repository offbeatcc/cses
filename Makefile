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
