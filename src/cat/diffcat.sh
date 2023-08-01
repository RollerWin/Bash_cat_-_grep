echo ----------------------------------------------*CAT 1
diff <(cat -b text.txt) <(./s21_cat -b text.txt) -s
echo ----------------------------------------------*CAT 2
diff <(cat -e "text.txt") <(./s21_cat -e "text.txt") -s
echo ----------------------------------------------*CAT 3
diff <(cat -n text.txt) <(./s21_cat -n text.txt) -s
echo ----------------------------------------------*CAT 4
diff <(cat "text.txt" -n) <(./s21_cat "text.txt" -n) -s
echo ----------------------------------------------*CAT 5
diff <(cat -s "text.txt") <(./s21_cat -s "text.txt") -s
echo ----------------------------------------------*CAT 6
diff <(cat -t "text.txt") <(./s21_cat -t "text.txt") -s