#!/bin/bash

mkdir -p compile_db
make clean
compiledb -o compile_db/compile_commands.json make
