# =========================================================================
# slist-plot-all.py
# =========================================================================
# Simple python script for plotting all of the results on a single plot.
#
# Author : Christopher Batten
# Date   : October 14, 2021

# Set the backend to PDF to avoid using the GUI

import matplotlib

matplotlib.use("PDF")

# Import matplotlib for plotting and numpy for data analysis

import matplotlib.pyplot as plt
import numpy as np

# Import other Python packages

import os

# Make sure results file exists

if not os.path.exists("slist-int-reverse-v2-eval.txt"):
    print("slist-int-reverse-v2-eval.txt does not exist!")
    exit(1)

# v1 data

v1_n = []
v1_t = []

# Read data from results file

with open("slist-int-reverse-v1-eval.txt") as f:
    for line in f:
        if "Fill and reverse with size" in line:
            v1_n.append(float(line.split()[5]))
        if "Average: elapsed time" in line:
            v1_t.append(float(line.split()[4]))

# v2 data

v2_n = []
v2_t = []

# Read data from results file

with open("slist-int-reverse-v2-eval.txt") as f:
    for line in f:
        if "Fill and reverse with size" in line:
            v2_n.append(float(line.split()[5]))
        if "Average: elapsed time" in line:
            v2_t.append(float(line.split()[4]))

# Create the figure and axis for our plot

fig, ax = plt.subplots()

# Plot the data

ax.plot(v1_n, v1_t, marker="o", label="SListInt::reverse_v1")
ax.plot(v2_n, v2_t, marker="^", label="SListInt::reverse_v2")

# Add some labels, grid, an save to a PDF

ax.set(xlabel="Input Array Size", ylabel="Measured Execution Time (s)")
ax.grid()
ax.legend()

fig.savefig("slist-plot-all.pdf", bbox_inches="tight")
