set terminal png
set output "plot.png"
plot "results.txt" using 1:2 title 'Pret', "results.txt" using 1:3 title 'Oil'
