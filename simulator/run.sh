#!/usr/bin/bash

# bash run.sh ../all_top_10_data_sorted_no_NaN.csv outputs/all_top_10_data_sorted_no_NaN.csv 5 all_top_10
# bash run.sh ../cluster_top_10_data_sorted_no_NaN.csv outputs/cluster_top_10_data_sorted_no_NaN.csv 5 cluster_top_10
# bash run.sh ../vanilla_approach_data_sorted_no_NaN.csv outputs/vanilla_approach_data_sorted_no_NaN.csv 5 vanilla_approach

# Latest data
# bash run.sh ../latest_input_data/all_top_10_data_sorted.csv outputs/all_top_10_data_sorted.csv 5 all_top_10
# bash run.sh ../latest_input_data/cluster_top_10_data_sorted.csv outputs/cluster_top_10_data_sorted.csv 5 cluster_top_10
# bash run.sh ../latest_input_data/vanilla_approach_data_sorted.csv outputs/vanilla_approach_data_sorted.csv 5 vanilla_approach
# bash run.sh ../latest_input_data/on_the_fly_data_sorted.csv outputs/on_the_fly_data_sorted.csv 5 on_the_fly

# Binder
# bash run.sh ../all_top_10_binder_sorted.csv outputs/all_top_10_binder_sorted.csv 5 all_top_10
# bash run.sh ../cluster_top_10_binder_sorted.csv outputs/cluster_top_10_binder_sorted.csv 5 cluster_top_10
# bash run.sh ../vanilla_approach_binder_sorted.csv outputs/vanilla_approach_binder_sorted.csv 5 vanilla_approach
# bash run.sh ../on_the_fly_binder_sorted.csv outputs/on_the_fly_binder_sorted.csv 5 on_the_fly

workload=$1
output=$2
nmodes=$3
type=$4

make -C src/

./src/main ${workload} no_schedule ${output}

#~ python3 src/plot.py ${output} ${nmodes} "total_start_time" ${type}
#~ python3 src/plot.py ${output} ${nmodes} "total_build_time" ${type}
#~ python3 src/plot.py ${output} ${nmodes} "total_start_and_build_time" ${type}
#~ python3 src/plot.py ${output} ${nmodes} "total_start_and_build_and_run_time" ${type}
#~ python3 src/plot.py ${output} ${nmodes} "stretch" ${type}
