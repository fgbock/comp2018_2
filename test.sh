for filename in ./e2tests/*
do
    rm e3results
    (cat "$filename" | ./etapa3) > out 
    (diff "$filename" out) >> e3results
done
