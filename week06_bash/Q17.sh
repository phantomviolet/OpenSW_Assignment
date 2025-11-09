#! /bin/bash

sh_count() {
    SHCNT=$(find *.sh | wc -l)
    echo "$SHCNT"
}

file_wordcnt() {
    files=$(ls *.txt)
    for i in $files; 
        do
            result=$(cat $i | wc -w)
            echo "$i 파일의 단어는 $result 개 입니다."
        done
}

# sh_count
# file_wordcnt

seq 1 2 10