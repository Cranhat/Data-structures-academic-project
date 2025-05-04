import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from pathlib import Path
import numpy as np

plt.rcParams.update({'font.size': 18})
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
ax.set_title("Wszystkie operacje dla tablicy dynamicznej")
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()


fig, ax = plt.subplots(figsize=(20, 10))

for i, element in enumerate(data):
    if "hp" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
ax.set_title("Wszystkie operacje dla kopca")
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

fig, ax = plt.subplots(figsize=(20, 10))
for i, element in enumerate(data):
    if "changeKey" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
ax.set_title("Operacja changeKey dla wszystkich struktur")
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

fig, ax = plt.subplots(figsize=(20, 10))
for i, element in enumerate(data):
    if "extractMax" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
ax.set_title("Operacja extractMax dla wszystkich struktur")
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

fig, ax = plt.subplots(figsize=(20, 10))
for i, element in enumerate(data):
    if "getSize" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
plt.legend(fontsize = "x-large")
ax.set_title("Operacja getSize dla wszystkich struktur")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

fig, ax = plt.subplots(figsize=(20, 10))
for i, element in enumerate(data):
    if "insert" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
ax.set_title("Operacja insert dla wszystkich struktur")
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

fig, ax = plt.subplots(figsize=(20, 10))
for i, element in enumerate(data):
    if "peek" in element:
        ax.plot(data[element]["count"], data[element]["time"], 'o-', label = element)

ax.grid()
ax.set(xticks = data["ar changeKey"]["count"])
ax.set_title("Operacja peek dla wszystkich struktur")
plt.legend(fontsize = "x-large")
plt.xlabel("count")
plt.ylabel("time [ns]")
plt.show()

