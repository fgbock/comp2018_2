rm e3results
for filename in ./e2tests/*
do
    (cat "$filename" | ./etapa3) > out 
    echo "\n" >> e3results
    (diff "$filename" out) >> e3results
    rm edited
done
