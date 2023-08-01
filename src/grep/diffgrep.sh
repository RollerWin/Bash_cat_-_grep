filename1=text1.txt;
filename2=text2.txt;
# filename3 is also used for -f flag patterns:
filename3=reg.txt;
echo ----------------------------------------------*GREP 1
diff <(grep a "$filename2" "$filename1") <(./s21_grep a "$filename2" "$filename1") -s -q
echo ----------------------------------------------*GREP 1 -e
diff <(grep -e ab "$filename2" "$filename1") <(./s21_grep -e ab "$filename2" "$filename1") -s -q
echo ----------------------------------------------*GREP 2
diff <(grep -i ab "$filename1") <(./s21_grep -i ab "$filename1") -s -q
echo ----------------------------------------------*GREP 3
diff <(grep -v a "$filename1") <(./s21_grep -v a "$filename1") -s -q
echo ----------------------------------------------*GREP 4
diff <(grep -c a "$filename1") <(./s21_grep -c a "$filename1") -s -q
echo ----------------------------------------------*GREP 5
diff <(grep -l aboba "$filename2" "$filename3" "$filename1") <(./s21_grep -l aboba "$filename2" "$filename3" "$filename1") -s -q
echo ----------------------------------------------*GREP 6
diff <(grep -n a "$filename1") <(./s21_grep -n a "$filename1") -s -q
echo ----------------------------------------------*GREP 7 BONUS
diff <(grep -h a "$filename1") <(./s21_grep -h a "$filename1") -s -q
echo ----------------------------------------------*GREP 8 BONUS
diff <(grep -o a "$filename1") <(./s21_grep -o a "$filename1") -s -q
echo ----------------------------------------------*GREP 9 BONUS
diff <(grep -h a "$filename2" "$filename1") <(./s21_grep -h a "$filename2" "$filename1") -s -q
echo ----------------------------------------------*GREP 10 BONUS
diff <(grep a -s aboba) <(./s21_grep a -s aboba) -s -q
echo ----------------------------------------------*GREP 11 BONUS
diff <(grep -f "$filename3" "$filename2") <(./s21_grep -f "$filename3" "$filename2") -s -q
echo ----------------------------------------------*GREP 12 BONUS
diff <(grep -in a "$filename1") <(./s21_grep -in a "$filename1") -s -q
echo ----------------------------------------------*GREP 13 BONUS
diff <(grep -cv a "$filename1") <(./s21_grep -cv a "$filename1") -s -q
echo ----------------------------------------------*GREP 14 BONUS
diff <(grep -iv a "$filename1") <(./s21_grep -iv a "$filename1") -s -q
echo ----------------------------------------------*GREP 15 BONUS
diff <(grep -lv a "$filename2" "$filename3" "$filename1") <(./s21_grep -lv a "$filename2" "$filename3" "$filename1") -s -q
echo ----------------------------------------------*GREP 16 BONUS
diff <(grep -ho a "$filename2" "$filename1") <(./s21_grep -ho a "$filename2" "$filename1") -s -q
echo ----------------------------------------------*GREP 17 BONUS
diff <(grep -nf "$filename3" "$filename2") <(./s21_grep -nf "$filename3" "$filename2") -s -q
echo ----------------------------------------------*Tests ended*
