#!/usr/bin/bash

# bash run.sh ../my_data_sorted.csv

workload=$1

make -C src/

./src/main ${workload} no_schedule outputs/${workload}

echo ""
echo "Plot barplots"

#~ python3 src/plot.py outputs/${workload} ${nmodes} "total_start_time"
#~ python3 src/plot.py outputs/${workload} ${nmodes} "total_build_time"
#~ python3 src/plot.py outputs/${workload} ${nmodes} "total_start_and_build_time"
#~ python3 src/plot.py outputs/${workload} ${nmodes} "total_start_and_build_and_run_time"
