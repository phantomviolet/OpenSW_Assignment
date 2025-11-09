#! /bin/bash

[ 5 -gt 3 ]; echo $? #return 0
[ 1 -gt 3 ]; echo $? #return 1
[ 256 -le 256 ]; echo $? #return 0
[ 4096 -eq 8192 ]; echo $? #return 1
[ 77 -gt 63 ]; echo $? #return 0
[ -5 -le -3 ]; echo $? #return 0
[ -100 -eq 100 ]; echo $? #return 1
