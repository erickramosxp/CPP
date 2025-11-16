echo "date | value" > big_input.txt
for i in $(seq 1 50000); do
  echo "2012-01-11 | $((i % 1000))" >> big_input.txt
done