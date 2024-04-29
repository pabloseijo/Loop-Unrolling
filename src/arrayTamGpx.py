import pandas as pd
import matplotlib.pyplot as plt

# Reading data from file assuming the 'Iteraciones' column now represents the size of the array
data = pd.read_csv('../data/arrayTam.txt', delim_whitespace=True, header=None, names=['TamañoArray', 'Tiempo'])

# Separating execution times for normal loop and unrolled loop
# Assuming odd lines (0, 2, 4, ...) are for the normal loop and even lines (1, 3, 5, ...) are for the unrolled loop
tiempos_normal = data.loc[0::2, 'Tiempo'].values  # Taking every second row starting from the first
tiempos_desenrollado = data.loc[1::2, 'Tiempo'].values
tamaño_array = data.loc[0::2, 'TamañoArray'].values  # Array sizes are the same for pairs of lines

# Create the comparative plot for array sizes
plt.figure(figsize=(10, 5))
plt.plot(tamaño_array, tiempos_normal, label='Bucle Normal', marker='o')
plt.plot(tamaño_array, tiempos_desenrollado, label='Bucle Desenrollado', marker='x')

# Add labels and title
plt.xlabel('Tamaño del Array')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.title('Gráfico Comparativo por Tamaño del Array')
plt.legend()

# Display grid
plt.grid(True)

# Show the plot
plt.show()
