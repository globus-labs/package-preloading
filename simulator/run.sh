#!/usr/bin/bash

# bash run.sh ../my_data_sorted.csv outputs/my_data_sorted.csv 

workload=$1
output=$2
nmodes=$3

make -C src/

./src/main ${workload} no_schedule ${output}

python3 src/plot.py ${output} ${nmodes} "total_start_time"
python3 src/plot.py ${output} ${nmodes} "total_build_time"
python3 src/plot.py ${output} ${nmodes} "total_start_and_build_time"
python3 src/plot.py ${output} ${nmodes} "total_start_and_build_and_run_time"
python3 src/plot.py ${output} ${nmodes} "stretch"
