pub:
	git diff --exit-code
	git diff --cached --exit-code
	git push
	cd ../offbeat && make pub

pset:
	curl -sS https://cses.fi/problemset/ -o /tmp/problemset.html
	sbcl --script meta/pset.lisp

# Update CSS file from the mirror website.
css: FORCE
	curl -sS https://offbeatcc.github.io/css/main.css -o web/main.css

# Add problem serial number as prefix to code files in solutions directory.
num:
	sbcl --script meta/num.lisp

# Remove problem serial numbers from code files in solutions directory.
denum:
	sbcl --script meta/denum.lisp


FORCE:
