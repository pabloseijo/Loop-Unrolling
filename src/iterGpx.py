import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos desde el archivo, asumiendo que cada par de líneas pertenece a la misma cantidad de iteraciones
# y alternan entre bucle normal y bucle desenrollado.
data = pd.read_csv('unrolling.txt', delim_whitespace=True, header=None, names=['Iteraciones', 'Tiempo'])

# Separar los tiempos de ejecución del bucle normal y desenrollado
# Asumimos que las líneas impares (0, 2, 4, ...) son del bucle normal y las pares (1, 3, 5, ...) son del desenrollado
tiempos_normal = data.iloc[0::2, 'Tiempo'].values  # Toma cada segunda fila comenzando de la primera
tiempos_desenrollado = data.iloc[1::2, 'Tiempo'].values
iteraciones = data.iloc[0::2, 'Iteraciones'].values  # Las iteraciones son iguales en pares de líneas

# Crear el gráfico
plt.figure(figsize=(10, 5))
plt.plot(iteraciones, tiempos_normal, label='Bucle Normal', marker='o')
plt.plot(iteraciones, tiempos_desenrollado, label='Bucle Desenrollado', marker='x')

# Añadir etiquetas y título
plt.xlabel('Número de Iteraciones')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.title('Comparación de Tiempo de Ejecución: Bucle Normal vs. Desenrollado')
plt.legend()

# Mostrar la cuadrícula
plt.grid(True)

# Mostrar el gráfico
plt.show()
