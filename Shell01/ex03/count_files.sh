#!bin/sh
find . -type d -or -type f | wc -l | sed -e 's/ //g'
