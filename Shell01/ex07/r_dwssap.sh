#!/bin/sh

cat /etc/passwd | grep -v '\#' | sed '1!n;d' |  cut -d':' -f1 | rev | sort -r | awk 'NR>= ENVIRON["FT_LINE1"] && NR<= ENVIRON["FT_LINE2"]' | paste -s -d"," - | sed 's/,/, /g' | sed 's/$/./' | tr -d '\n'

#grep -v '\#' prints lines that don't have '\#' 
#sed '1!n;d' prints lines in a yes/no sequence
#cut : -d ':' -f1 deletes whats on the right side of the ':'
#rev inverts the login 
#sort -r organizes the text in a reverse order from z to a
#awk processes the specified beggining and end of the print with the variables FT_LINE1 and FT_LINE2
#pastes the processed information
#sed 's/,/, /g' substitutes all the ',' for ', '
#sed 's/$/./' substitutes the last $ for a '.'
#tr -d '\n' deletes the last blank line
