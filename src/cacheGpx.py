import pandas as pd
import matplotlib.pyplot as plt

# Define the data for rolled and unrolled loops including all types of misses
# Leer los datos del archivo CSV para bucles enrollados
df_rolled = pd.read_csv('../data/rolled.csv')

# Leer los datos del archivo CSV para bucles desenrollados
df_unrolled = pd.read_csv('../data/unrolled.csv')
# Set up the plot figure and axes
fig, ax = plt.subplots(3, 1, figsize=(12, 18), sharex=True)

# Plot for LL Misses
ax[0].plot(df_rolled['ArrayTam'], df_rolled['LL Misses'], 'o-', color='blue', label='Bucle Enrollado - Fallos LL')
ax[0].plot(df_unrolled['ArrayTam'], df_unrolled['LL Misses'], 's-', color='red', label='Bucle Desenrollado - Fallos LL')
ax[0].set_title('Comparación de Fallos LL')
ax[0].set_ylabel('Fallos LL')
ax[0].legend()
ax[0].grid(True)

# Plot for D1 Misses
ax[1].plot(df_rolled['ArrayTam'], df_rolled['D1 Misses'], '^-', color='green', label='Bucle Enrollado - Fallos D1')
ax[1].plot(df_unrolled['ArrayTam'], df_unrolled['D1 Misses'], 'x-', color='purple', label='Bucle Desenrollado - Fallos D1')
ax[1].set_title('Comparación de Fallos D1')
ax[1].set_ylabel('Fallos D1')
ax[1].legend()
ax[1].grid(True)

# Plot for I1 Misses
ax[2].plot(df_rolled['ArrayTam'], df_rolled['I1 Misses'], 'd-', color='orange', label='Bucle Enrollado - Fallos I1')
ax[2].plot(df_unrolled['ArrayTam'], df_unrolled['I1 Misses'], 'p-', color='brown', label='Bucle Desenrollado - Fallos I1')
ax[2].set_title('Comparación de Fallos I1')
ax[2].set_xlabel('Tamaño del Array')
ax[2].set_ylabel('Fallos I1')
ax[2].legend()
ax[2].grid(True)

# Set log scale for x and y axis
for axis in ax:
    axis.set_xscale('log')
    axis.set_yscale('log')

# Display the plots
plt.tight_layout()
plt.show()
