rm e3results
counter=0
for filename in ./e2tests/*
do
    touch original
    grep -v "^/" $filename | while read LINE
    do
        echo $LINE >> original
    done
    (cat "$filename" | ./etapa3) > new
    echo "\n" >> e3results
    echo "$counter" >> e3results
    (diff original new) >> e3results
    rm original
    counter=$((counter+1))
done
