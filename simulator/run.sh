#!/usr/bin/bash

# bash run.sh ../my_data_sorted_all_top_10.csv outputs/my_data_sorted_all_top_10.csv 5 all_top_10
# bash run.sh ../my_data_sorted_cluster_top_10.csv outputs/my_data_sorted_cluster_top_10.csv 5 cluster_top_10
# bash run.sh ../my_data_sorted_vanilla_approach.csv outputs/my_data_sorted_vanilla_approach.csv 5 vanilla_approach

workload=$1
output=$2
nmodes=$3
type=$4

make -C src/

./src/main ${workload} no_schedule ${output}

python3 src/plot.py ${output} ${nmodes} "total_start_time" ${type}
python3 src/plot.py ${output} ${nmodes} "total_build_time" ${type}
python3 src/plot.py ${output} ${nmodes} "total_start_and_build_time" ${type}
python3 src/plot.py ${output} ${nmodes} "total_start_and_build_and_run_time" ${type}
python3 src/plot.py ${output} ${nmodes} "stretch" ${type}
