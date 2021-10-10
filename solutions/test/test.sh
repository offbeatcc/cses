#!/bin/sh

set -e

check()
{
    printf 'input: %s ... ' $(printf '%s' "$1" | head -n 1)
    printf '%s\n' "$1" > input.txt
    printf '%s\n' "$2" > expected.txt
    ./a.out < input.txt > output.txt
    if diff=$(diff -u expected.txt output.txt)
    then
        printf 'pass\n'
    else
        printf 'fail\n'
        printf '%s\n' "$diff"
    fi
}

main()
{
    . test/"${1%.*}.sh"
    printf 'done\n'
}

main "$@"
