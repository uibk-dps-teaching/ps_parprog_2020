set terminal gif animate delay 100
set output 'output.gif'

set style line 2 lc rgb 'black' pt 7   # circle
stats 'data.dat' nooutput
set xrange [-0.5:100.5]
set yrange [-0.5:100.5]

do for [i=1:int(STATS_blocks)] {
   plot 'data.dat' index (i-1) with points ls 2 ps 0.4
}