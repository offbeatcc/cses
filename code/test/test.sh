#!/bin/sh

set -e

check()
{
    printf '%s ... ' $(printf '%s' "$1" | head -n 1)
    printf '%s\n' "$1" > input.txt
    printf '%s\n' "$2" > expected.txt
    ./a.out < input.txt > output.txt
    printf '=> %s ... ' $(head -n 1 output.txt)
    if $(diff -u expected.txt output.txt > error.diff)
    then
        printf 'pass\n'
    else
        printf 'fail\n'
        cat error.diff
        exit 1
    fi
}

main()
{
    SUFFIX=$(sed -n 's/\/\/ test_suffix=//p' "$1")
    F=${1%.*}  # Remove .cc
    F=${F%_0*} # Remove _01, _02, etc.
    F="$F$SUFFIX.sh" # Add suffix and extension.
    if [ -e "test/$F" ]
    then
        . "test/$F"
    else
        printf 'test file not found'
    fi
    printf 'done\n'
    unset F
}

main "$@"
