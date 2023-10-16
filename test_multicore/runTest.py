import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import matplotlib
from sklearn.linear_model import LinearRegression
matplotlib.use('Qt5Agg')

#tipo="estandard"
#tipo="relaxat"
tipo="squarish"

df = pd.DataFrame(columns=["N"])

for i in range(2, 7):
    file = pd.read_csv(f"{tipo}_k{i}.txt", sep=" ", header=None, names=["N", f"K{i}"])
    df = df.merge(file, on="N", how="outer")

print(df)

fig, axes = plt.subplots(5, 1, figsize=(10, 25))

for i in range(2, 7):
    ax = axes[i-2]
    ax.plot(df["N"], df[f"K{i}"], color=plt.cm.jet(np.random.rand()))
    ax.set_title(f"Scatter plot de KD-Tree {tipo} para K={i}")
    ax.set_xlabel("N")
    ax.set_ylabel("coste")

plt.tight_layout()
plt.savefig(f'plot_{tipo}.png')

fig, axes = plt.subplots(5, 1, figsize=(10, 25))
for i in range(2, 7):
    ax = axes[i-2]
    n = np.log10(df['N'])
    cost = np.log10(df[f'K{i}'])
    regresion = LinearRegression().fit(n.values.reshape(-1, 1), cost)

    print(f'K{i}')
    print("Intercepto:", regresion.intercept_)
    print("Coeficiente:", regresion.coef_[0])

    ax.scatter(n, cost)
    ax.plot(n, regresion.predict(n.values.reshape(-1, 1)), color='red')
    ax.set_title(f"Log Log plot de KD-Tree {tipo} para K={i}")
    ax.set_xlabel("log10(n)")
    ax.set_ylabel("log10(cost)")
plt.tight_layout()
fig.savefig(f"loglogplot_{tipo}.png")