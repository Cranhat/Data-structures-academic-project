import matplotlib.pyplot as plt
import pandas as pd
from pathlib import Path
import numpy as np

plt.rcParams.update({'font.size': 18})


path_modulo = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsModulo/"
path_multiplication = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsMultiplication/"
path_AVL = "C:/Users/Cyprian/Projects/Data-structures-academic-project/Project_3/ResultsAVL/"

files_modulo = ["oa add 0.5.csv", "oa add 0.7.csv", "oa add 0.9.csv", "oa add 0.99.csv",
        "oa delete 0.5.csv", "oa delete 0.7.csv", "oa delete 0.9.csv", "oa delete 0.99.csv",
        "sc add 0.5.csv", "sc add 0.7.csv", "sc add 0.9.csv", "sc add 0.7.csv", "sc add 0.99.csv", "sc add 2.csv", "sc add 4.csv",
        "sc delete 0.5.csv", "sc delete 0.7.csv", "sc delete 0.9.csv", "sc delete 0.7.csv", "sc delete 0.99.csv", "sc delete 2.csv", "sc delete 4.csv"]
 
files_multiplication = ["oa1 add 0.5.csv", "oa1 add 0.7.csv", "oa1 add 0.9.csv", "oa1 add 0.99.csv",
        "oa1 delete 0.5.csv", "oa1 delete 0.7.csv", "oa1 delete 0.9.csv", "oa1 delete 0.99.csv",
        "sc1 add 0.5.csv", "sc1 add 0.7.csv", "sc1 add 0.9.csv", "sc1 add 0.99.csv", "sc1 add 2.csv", "sc1 add 4.csv",
        "sc1 delete 0.5.csv", "sc1 delete 0.7.csv", "sc1 delete 0.9.csv", "sc1 delete 0.99.csv", "sc1 delete 2.csv", "sc1 delete 4.csv"]

files_AVL = ["avl add.csv", "avl delete.csv"]

data_modulo = {}
data_multiplication = {}
data_avl = {}

for i, element in enumerate(files_modulo):
    data_modulo[element[:-4]] = pd.read_csv(path_modulo + element, sep = ";")

for i, element in enumerate(files_multiplication):
    data_multiplication[element[:-4]] = pd.read_csv(path_multiplication + element, sep = ";")

for i, element in enumerate(files_AVL):
    data_avl[element[:-4]] = pd.read_csv(path_AVL + element, sep = ";")


# comparison of every add operation for 0.7 load factor
fig, ax = plt.subplots(figsize=(14, 7))

ax.plot(data_avl["avl add"]["count"], data_avl["avl add"]["time"], 'o-', label = "avl add")
ax.plot(data_modulo["sc add 0.7"]["count"], data_modulo["sc add 0.7"]["time"], 'o-', label = "sc add 0.7")
ax.plot(data_modulo["oa add 0.7"]["count"], data_modulo["oa add 0.7"]["time"], 'o-', label = "oa add 0.7")
    
    
title = "Porównanie add dla każdej implementacji"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# comparison of every delete operation for 0.7 load factor
fig, ax = plt.subplots(figsize=(14, 7))

ax.plot(data_avl["avl delete"]["count"], data_avl["avl delete"]["time"], 'o-', label = "avl delete")
ax.plot(data_modulo["sc delete 0.7"]["count"], data_modulo["sc delete 0.7"]["time"], 'o-', label = "sc delete 0.7")
ax.plot(data_modulo["oa delete 0.7"]["count"], data_modulo["oa delete 0.7"]["time"], 'o-', label = "oa delete 0.7")
    
    
title = "Porównanie delete dla każdej implementacji"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# --all charts for avl
fig, ax = plt.subplots(figsize=(14, 7))

for i, avl in enumerate(data_avl):
    if "avl" in avl:
        ax.plot(data_avl[avl]["count"], data_avl[avl]["time"], 'o-', label = avl)
    
title = "Add i delete dla AVL"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# all delete for open addressing modulo
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "oa" in modulo and "delete" in modulo:
        ax.plot(data_modulo[modulo]["count"], data_modulo[modulo]["time"], 'o-', label = modulo)
    
title = "Wszystkie load factor dla operacji delete open addressing haszowania modulo"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# all add for open addressing modulo
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "oa" in modulo and "add" in modulo:
        ax.plot(data_modulo[modulo]["count"], data_modulo[modulo]["time"], 'o-', label = modulo)

title = "Wszystkie load factor dla operacji add open addressing haszowania modulo"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()



# all add for open addressing multiplication
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "oa" in multiplication and "add" in multiplication:
        ax.plot(data_multiplication[multiplication]["count"], data_multiplication[multiplication]["time"], 'o-', label = multiplication)
    
    
title = "Wszystkie load factor dla operacji add open addressing haszowania multiplication"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# all delete for open addressing multiplication
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "oa" in multiplication and "delete" in multiplication:
        ax.plot(data_multiplication[multiplication]["count"], data_multiplication[multiplication]["time"], 'o-', label = multiplication)
    
    
title = "Wszystkie load factor dla operacji delete open addressing haszowania multiplication"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# all add for separate chaining modulo
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "sc" in modulo and "add" in modulo:
        ax.plot(data_modulo[modulo]["count"], data_modulo[modulo]["time"], 'o-', label = modulo)
    
title = "Wszystkie load factor dla operacji add separate chaining haszowania modulo"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()


# all delete for separate chaining modulo
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "sc" in modulo and "delete" in modulo:
        ax.plot(data_modulo[modulo]["count"], data_modulo[modulo]["time"], 'o-', label = modulo)
    
title = "Wszystkie load factor dla operacji delete separate chaining haszowania modulo"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()

# all add for separate chaining modulo
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "sc" in multiplication and  "add" in multiplication:
        ax.plot(data_multiplication[multiplication]["count"], data_multiplication[multiplication]["time"], 'o-', label = multiplication)
    
title = "Wszystkie load factor dla operacji add separate chaining haszowania multiplication"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()


# all delete for separate chaining modulo
fig, ax = plt.subplots(figsize=(14, 7))

for i, (modulo, multiplication) in enumerate(zip(data_modulo, data_multiplication)):
    if "sc" in multiplication and "delete" in multiplication:
        ax.plot(data_multiplication[multiplication]["count"], data_multiplication[multiplication]["time"], 'o-', label = multiplication)
    
title = "Wszystkie load factor dla operacji delete separate chaining haszowania multiplication"
ax.grid()
ax.set_title(title)
plt.legend()
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.xticks(rotation=45) 
plt.yticks(rotation=45) 
ax.set_xticklabels(ax.get_xticks(), fontsize=11)
plt.tight_layout() 
plt.savefig(title + ".pdf", format="pdf") 
plt.show()
# -------------------------------