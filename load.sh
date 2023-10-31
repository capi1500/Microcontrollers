#!/bin/bash

# Loads bin file in the current directory to microcontoller

# Quick Flash script for STM32 NUCLEO-F4xxxx boards

if [ $# -eq 0 ]; then
  file_count=`ls *.bin 2> /dev/null | wc -l`
  if [ $file_count -lt 1 ]; then
    echo "No .bin file"
    exit
  elif [ $file_count -gt 1 ]; then
    echo "Too many .bin files"  
    echo "Use:"
    echo "$0 the_name_of_the_file_with_the_binary_flash_image"
    exit
  else
    file=`ls *.bin`
  fi
elif [ $# -eq 1 ]; then
  file=$1
else
  echo "Usage:"
  echo $0 "[the_name_of_the_file_with_the_binary_flash_image]"
  exit
fi

openocd -d0 \
 -f board/st_nucleo_f4.cfg \
 -c "init" -c "reset halt" \
 -c "flash write_image erase $file 0x8000000" \
 -c "verify_image $file" -c "reset" -c "shutdown"
