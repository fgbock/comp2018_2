rm e3results
for filename in ./e2tests/*
do
    "$filename" | grep -vE '/' >> edited
    (cat "$filename" | ./etapa3) > out 
    (diff edited out) >> e3results
    rm edited
done
