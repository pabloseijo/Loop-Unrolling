import pandas as pd
import matplotlib.pyplot as plt

# Reading data from file with the updated separator argument
data = pd.read_csv('../data/arrayTam.txt', sep='\s+', header=None, names=['arrayTam', 'Tiempo'])

# Separating execution times for normal loop and unrolled loop
tiempos_normal = data.loc[0::2, 'Tiempo'].values  # Use 'loc' for label-based indexing
tiempos_desenrollado = data.loc[1::2, 'Tiempo'].values
arrayTam = data.loc[0::2, 'arrayTam'].values

# Calculate the percentage improvement
mejora_porcentual = ((tiempos_normal - tiempos_desenrollado) / tiempos_normal) * 100

# Create the plot for improvement
plt.figure(figsize=(10, 5))
plt.bar(arrayTam.astype(str), mejora_porcentual, color='skyblue')  # Cast to string if iteraciones are integers

# Add labels and title
plt.xlabel('Tamaño del Array')
plt.ylabel('Mejora de Rendimiento (%)')
plt.title('Histograma de Mejora de Rendimiento')

# Rotate the X-axis labels for better readability
plt.xticks(rotation=45)  # Rotate labels to avoid overlap

# Display grid
plt.grid(True, axis='y')

# Show the plot
plt.tight_layout()  # Adjust the layout to fit rotated labels
plt.show()
