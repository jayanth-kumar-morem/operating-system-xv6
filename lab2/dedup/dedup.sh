#!/bin/bash
for file1 in "$(find "$1/inputs" -name '*.csv')"; do
    shift
    for file2 in "$(find "$1/inputs" -name '*.csv')"; do
        compare=$(diff -q "$file1" "$file2")
        if [ -z "$compare" ]; then
            echo the "$file1" is a dublicate of "$file2"
            nw="$file2"
            $(sudo rm "$file2")
            $(ln -sf "$file1" "$nw")
        fi
    done
done