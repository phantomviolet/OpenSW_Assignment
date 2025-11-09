#! /bin/bash

file_wordcnt() {
    FILE=$1
    word_count=$(wc -w < "$FILE")
    echo "$FILE 파일의 단어는 $word_count 개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt "$FILE"