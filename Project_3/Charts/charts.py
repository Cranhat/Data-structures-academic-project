import matplotlib.pyplot as plt
import pandas as pd
from pathlib import Path
import numpy as np

plt.rcParams.update({'font.size': 18})


path = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/Results/"
# path = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Results/"


files = ["ar changeKey.csv", "ar extractMax.csv", "ar getSize.csv", "ar insert.csv", "ar peek.csv", "hp changeKey.csv", "hp extractMax.csv", "hp getSize.csv", "hp insert.csv", "hp peek.csv"]
data = {}

for i, element in enumerate(files):
    data[element[:-4]] = pd.read_csv(path + element, sep = ";")


fig, ax = plt.subplots(figsize=(20, 10))

for i, element in enumerate(data):
    if "ar" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)
title = "Wszystkie operacje dla tablicy dynamicznej"
ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
ax.set_title(title)
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()
