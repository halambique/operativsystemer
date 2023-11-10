#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Error: Please enter a filename"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Error: '$1' does not exist"
    exit 1
fi

size=$(stat -c "%s" "$1")

while true; do
    sleep 60
    current_size=$(stat -c "%s" "$1")
    if [ "$size" -ne "$current_size" ]; then
        echo "File size has changed - Terminating program"
        exit 0
    fi
done
