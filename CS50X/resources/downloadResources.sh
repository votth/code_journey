#/usr/bin/shell

# loop from 0 to 15
for lecture in $(seq 0 15)
do 
    # save the webpage, just 1 level
    wget -EHkKp https://cs50.harvard.edu/x/2022/notes/$lecture/ || break
    wget https://cdn.cs50.net/2021/fall/lectures/$lecture/lecture$lecture.pdf
    wget https://cdn.cs50.net/2021/fall/lectures/$lecture/src$lecture.zip
    # break if encounters error, out-of-bound for example lecture=15 doesn't exist
done
# feedback
echo Downloaded CS50\'s $lecture lectures
