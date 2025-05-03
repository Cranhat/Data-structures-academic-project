import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from pathlib import Path
import numpy as np

# path = "../Results/"

path = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_2/Results/"

files = ["ar changeKey.csv", "ar extractMax.csv", "ar getSize.csv", "ar insert.csv", "ar peek.csv", "hp changeKey.csv", "hp extractMax.csv", "hp getSize.csv", "hp insert.csv", "hp peek.csv"]
data = {}

for i, element in enumerate(files):
    data[element[:-4]] = pd.read_csv(path + element, sep = ";")



fig, ax = plt.subplots(figsize=(20, 10))

for i, element in enumerate(data):
    if "ar" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

fig, ax = plt.subplots(figsize=(20, 10))

for i, element in enumerate(data):
    if "hp" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

