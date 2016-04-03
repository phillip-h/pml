#!/bin/bash
#
# extract each header file and it's
# dependancies into a seperate directory
###########################################

############
# settings
EXTRACT_DIR="module"
SOURCE_DIR="pml"

EXIT_OK=0
EXIT_BAD_ARG=-1
EXIT_IO_ERROR=-2

##############
# arg parsing
for arg in "$@"; do
    if [ "$arg" = clean ]; then
        rm -rf "$EXTRACT_DIR"
        exit "$EXIT_OK"
    else 
        printf "unknown argument $arg.\n"
        exit "$EXIT_BAD_ARG"
    fi
done

###################################
# create or clean the extract dir
if [ ! -d "$EXTRACT_DIR" ]; then
    mkdir "$EXTRACT_DIR"
else
    rm -rf "$EXTRACT_DIR"/*
fi

#########################################
# check that the source directory exists
if [ ! -d "$SOURCE_DIR" ]; then
    printf "error--source directory does not exist!\n";
    exit "$EXIT_IO_ERROR"
fi

#########################################
# iterate through headers and seperate
# into modules
count=0
for file in "$SOURCE_DIR"/*; do
    dir=${file#"$SOURCE_DIR"/}
    dir=${dir%.hpp}
    mkdir "$EXTRACT_DIR"/"$dir"
    cp "$file" "$EXTRACT_DIR"/"$dir"
    while read -r line; do
        if [[ "$line" = \#include\ \"*\" ]]; then
            line=${line#"#include \""}
            line=${line%"\""}
            if [ -f "$SOURCE_DIR"/"$line" ]; then
                cp "$SOURCE_DIR"/"$line" "$EXTRACT_DIR"/"$dir" 
            else
                printf "error--$file includes unknown file '$line'!\n"
            fi
        fi
    done < "$file"
    ((count++))
done

#########################
# print success and exit
printf "done, created $count modules.\n"
exit "$EXIT_OK"
