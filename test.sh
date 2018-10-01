rm e3results
counter=1
for filename in ./e2tests/*
do
    touch original
    grep -v "^/" $filename | while read LINE
    do
        echo $LINE >> original.txt
    done
    (cat "$filename" |  ./etapa3) > new.txt
    (cat new.txt | tr -d " \t\n\r") > new
    (cat original.txt | tr -d " \t\n\r") > original
    echo "\n" >> e3results
    echo "$counter" >> e3results
    (diff original new) >> e3results
    rm original
    rm new.txt
    rm original.txt
    rm new
    counter=$((counter+1))
    echo new >> e3detailed
done
