import sys
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

sns.set_theme(style='whitegrid', context='paper', font_scale=1.75, rc={'axes.facecolor': 'white', 'figure.figsize':(7,4)})

input_file = sys.argv[1]
nmodes = int(sys.argv[2])
mode = sys.argv[3]
database_type = sys.argv[4]

measured_metric = [0]*nmodes # First tab cell is for user 0 then 1, etc...

print("Plotting", mode, "with input file", input_file, "and", nmodes, "modes")
	
data = pd.read_csv(input_file)
df=pd.DataFrame(data)

Job_unique_id = list(df.iloc[:, 0])
Nlines = len(Job_unique_id) # Number of lines in the file without the header
Job_shared_id = list(df.iloc[:, 1])
Container_mode = list(df.iloc[:, 2])
Runtime = list(df.iloc[:, 3])
Start_time = list(df.iloc[:, 4])
Build_time = list(df.iloc[:, 5])

if mode == "total_start_time":
	for i in range(0, Nlines):
		measured_metric[Container_mode[i]] += Start_time[i]
elif mode == "total_build_time":
	for i in range(0, Nlines):
		measured_metric[Container_mode[i]] += Build_time[i]
elif mode == "total_start_and_build_time":
	for i in range(0, Nlines):
		measured_metric[Container_mode[i]] += Start_time[i] + Build_time[i]
elif mode == "total_start_and_build_and_run_time":
	for i in range(0, Nlines):
		measured_metric[Container_mode[i]] += Start_time[i] + Build_time[i] + Runtime[i]
elif mode == "stretch":
	list_of_improvement_from_always_cold = []
	always_cold_times = []
	for i in range(0, nmodes - 1):
		list_of_improvement_from_always_cold.append([])
	for i in range(0, Nlines):
		if Container_mode[i] != 0:
			break
		always_cold_times.append(Start_time[i] + Build_time[i] + Runtime[i])
	
	k = 0
	for j in range(0, Nlines):
		if Container_mode[j] == 1:
			list_of_improvement_from_always_cold[0].append(always_cold_times[k]/(Start_time[j] + Build_time[j] + Runtime[j]))
			k = k + 1
	k = 0
	for j in range(0, Nlines):
		if Container_mode[j] == 2:
			list_of_improvement_from_always_cold[1].append(always_cold_times[k]/(Start_time[j] + Build_time[j] + Runtime[j]))
			k = k + 1
	k = 0
	for j in range(0, Nlines):
		if Container_mode[j] == 3:
			list_of_improvement_from_always_cold[2].append(always_cold_times[k]/(Start_time[j] + Build_time[j] + Runtime[j]))
			k = k + 1
	k = 0
	for j in range(0, Nlines):
		if Container_mode[j] == 4:
			list_of_improvement_from_always_cold[3].append(always_cold_times[k]/(Start_time[j] + Build_time[j] + Runtime[j]))
			k = k + 1
else:
	print("ERROR: Wrong mode in plot_batrplots.py")

print(measured_metric)

if mode != "stretch":
	# Settings of the plot
	bar_width = 0.2
	separation_between_bars=0.3
			
	x = [1*separation_between_bars, 2*separation_between_bars, 3*separation_between_bars, 4*separation_between_bars, 5*separation_between_bars]
	colors = ["#C8E9E9", "#ffedbf", "#ffca7b", "#ff7251", "#9b2948"]

	for i in range (0, nmodes):
		plt.bar((i+1)*separation_between_bars, measured_metric[i], bar_width, color=colors[i])

	labels = ['Always cold', 'Hot for 5min', 'Hot for 10min', 'Hot for 15min', 'Always hot']
	plt.xticks(x, labels, rotation=42)
else:
	colors = ["#ffedbf", "#ffca7b", "#ff7251", "#9b2948"]
	columns = [list_of_improvement_from_always_cold[0], list_of_improvement_from_always_cold[1], list_of_improvement_from_always_cold[2], list_of_improvement_from_always_cold[3]]
	fig = sns.boxplot(data=columns, whis=[12.5, 100 - 12.5], palette=colors, showmeans = True, showfliers = False)
	plt.ylim(4.75, 5.75)
	labels = ['Hot for 5min', 'Hot for 10min', 'Hot for 15min', 'Always hot']
	
if mode == "total_start_time":
	plt.ylabel("Total start times (s)")
	mode_name = "start"
elif mode == "total_build_time":
	plt.ylabel("Total build times (s)")
	mode_name = "build"
elif mode == "total_start_and_build_time":
	plt.ylabel("Total Environment Setup Time (s)")
	mode_name = "start_and_build"
elif mode == "total_start_and_build_and_run_time":
	plt.ylabel("Total flow (s)")
	mode_name = "flow"
elif mode == "stretch":
	plt.ylabel("Stretch")
	mode_name = "stretch"

# Saving plots
fig_name = "plot/" + database_type + "_" + str(Nlines/nmodes) + "_jobs_" + str(nmodes) + "_modes_" + mode_name + ".pdf"
print("Saved in", fig_name)
plt.savefig(fig_name, bbox_inches='tight')
