import pandas as pd
import matplotlib.pyplot as plt

# Reading data from file
data = pd.read_csv('../iter.txt', delim_whitespace=True, header=None, names=['Iteraciones', 'Tiempo'])

# Separating execution times for normal loop and unrolled loop
# Assuming odd lines (0, 2, 4, ...) are for the normal loop and even lines (1, 3, 5, ...) are for the unrolled loop
tiempos_normal = data.loc[0::2, 'Tiempo'].values  # Taking every second row starting from the first
tiempos_desenrollado = data.loc[1::2, 'Tiempo'].values
iteraciones = data.loc[0::2, 'Iteraciones'].values  # Iterations are the same for pairs of lines

# Create the plot
plt.figure(figsize=(10, 5))
plt.plot(iteraciones, tiempos_normal, label='Bucle Normal', marker='o')
plt.plot(iteraciones, tiempos_desenrollado, label='Bucle Desenrollado', marker='x')

# Add labels and title
plt.xlabel('Número de Iteraciones')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.title('Comparación de Tiempo de Ejecución: Bucle Normal vs. Desenrollado')
plt.legend()

# Display grid
plt.grid(True)

# Show the plot
plt.show()
