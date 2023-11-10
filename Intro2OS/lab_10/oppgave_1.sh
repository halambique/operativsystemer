#!/bin/bash

read -p "Fornavn? " first_name

count=0

grep "$first_name" /etc/passwd | while IFS=: read -r username full_name rest

do
    if [[ "$full_name" == *"$first_name" ]];
    then ((count++))
    fi
done

echo "Det er $count andre $first_name i systemet"
