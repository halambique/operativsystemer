#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Error: Requires 2 arguments"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Error: '$1' is not a valid directory"
    exit 1
fi

if [ ! -d "$2" ]; then
    echo "Error: '$2' is not a valid directory"
    exit 1
fi

moved_files=0

if [ -w "$1" ] && [ -w "$2" ]; then
    for i in ls "$1" | grep '\.mp3$'
    do
    mv "$1/$i" "$2"
    moved_files++
done

echo "Moved $moved_files mp3-filer fra $1 til $2"
