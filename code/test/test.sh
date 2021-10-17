#!/bin/sh

set -e

check()
{
    printf 'input: %s ... ' $(printf '%s' "$1" | head -n 1)
    printf '%s\n' "$1" > input.txt
    printf '%s\n' "$2" > expected.txt
    ./a.out < input.txt > output.txt
    if $(diff -u expected.txt output.txt > output.diff)
    then
        printf 'pass\n'
    else
        printf 'fail\n'
        cat output.diff
        exit 1
    fi
}

main()
{
    SUFFIX=$(sed -n 's/\/\/ test_suffix=//p' "$1")
    F=${1%.*}  # Remove .cc
    F=${F%_0*} # Remove _01, _02, etc.
    F="$F$SUFFIX.sh" # Append suffix and .sh
    . test/"$F"
    printf 'done\n'
    unset F
}

main "$@"
