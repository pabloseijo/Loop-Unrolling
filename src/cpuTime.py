import pandas as pd
import matplotlib.pyplot as plt

# Read data from file, specify no header and assign column names
data = pd.read_csv('../data/times.csv', header=None, names=['Iteraciones', 'TiempoRealNormal', 'TiempoCPUNormal', 'TiempoRealDesenrollado', 'TiempoCPUDesenrollado'])

# Create the plot for real and CPU times
plt.figure(figsize=(10, 5))

# Plot real times
plt.plot(data['Iteraciones'], data['TiempoRealNormal'], label='Real Time Normal', marker='o', color='blue')
plt.plot(data['Iteraciones'], data['TiempoRealDesenrollado'], label='Real Time Unrolled', marker='x', color='cyan')

# Plot CPU times
plt.plot(data['Iteraciones'], data['TiempoCPUNormal'], label='CPU Time Normal', marker='o', linestyle='--', color='orange')
plt.plot(data['Iteraciones'], data['TiempoCPUDesenrollado'], label='CPU Time Unrolled', marker='x', linestyle='--', color='red')

# Add labels and title
plt.xlabel('Number of Iterations or Size of Array')
plt.ylabel('Time (seconds)')
plt.title('Real Time vs. CPU Time Comparison')
plt.legend()
plt.grid(True)

# Adjust the layout and display the plot
plt.tight_layout()
plt.show()
