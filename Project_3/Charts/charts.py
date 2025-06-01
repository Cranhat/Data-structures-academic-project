import matplotlib.pyplot as plt
import pandas as pd
from pathlib import Path
import numpy as np

plt.rcParams.update({'font.size': 18})


# path_modulo = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/Results/"
# path_modulo = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsMultiplication/"
path_modulo = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/Results/"
path_multiplication = "C:/Users/cypri/Projects/Data-structures-academic-project/Project_3/ResultsMultiplication/"


files_modulo = ["oa add 0.5.csv", "oa add 0.7.csv", "oa add 0.9.csv", "oa add 0.99.csv",
        "oa delete 0.5.csv", "oa delete 0.7.csv", "oa delete 0.9.csv", "oa delete 0.99.csv",
        "sc add 0.5.csv", "sc add 0.6.csv", "sc add 0.7.csv", "sc add 0.9.csv", "sc add 0.7.csv", "sc add 0.99.csv", "sc add 2.csv", "sc add 4.csv",
        "sc delete 0.5.csv", "sc delete 0.6.csv", "sc delete 0.7.csv", "sc delete 0.9.csv", "sc delete 0.7.csv", "sc delete 0.99.csv", "sc delete 2.csv", "sc delete 4.csv"]
 
files_multiplication = ["oa1 add 0.5.csv", "oa1 add 0.7.csv", "oa1 add 0.9.csv", "oa1 add 0.99.csv",
        "oa1 delete 0.5.csv", "oa1 delete 0.7.csv", "oa1 delete 0.9.csv", "oa1 delete 0.99.csv",
        "sc1 add 0.5.csv", "sc1 add 0.7.csv", "sc1 add 0.9.csv", "sc1 add 0.99.csv", "sc1 add 2.csv", "sc1 add 4.csv",
        "sc1 delete 0.5.csv", "sc1 delete 0.7.csv", "sc1 delete 0.9.csv", "sc1 delete 0.99.csv", "sc1 delete 2.csv", "sc1 delete 4.csv"]

data_modulo = {}
data_multiplication = {}

for i, element in enumerate(files_modulo):
    data_modulo[element[:-4]] = pd.read_csv(path_modulo + element, sep = ";")

for i, element in enumerate(files_multiplication):
    data_multiplication[element[:-4]] = pd.read_csv(path_multiplication + element, sep = ";")

# -------------------------------
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "oa" in modulo:
        ax.plot(data_modulo[modulo]["count"], data_modulo[modulo]["time"], 'o-', label = modulo)
    
title = "Wszystkie lf dla open addressing haszowania modulo"
ax.grid()
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


fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "oa" in multiplication:
        ax.plot(data_multiplication[multiplication]["count"], data_multiplication[multiplication]["time"], 'o-', label = multiplication)
    
title = "Wszystkie lf dla open addressing haszowania multiplication"
ax.grid()
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

# -------------------------------
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "sc" in modulo:
        ax.plot(data_modulo[modulo]["count"], data_modulo[modulo]["time"], 'o-', label = modulo)
    
title = "Wszystkie lf dla separate chaining haszowania modulo"
ax.grid()
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


fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "sc" in multiplication:
        ax.plot(data_multiplication[multiplication]["count"], data_multiplication[multiplication]["time"], 'o-', label = multiplication)
    
title = "Wszystkie lf dla separate chaining haszowania multiplication"
ax.grid()
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
# -------------------------------