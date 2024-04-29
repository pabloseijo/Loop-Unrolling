import pandas as pd
import matplotlib.pyplot as plt

# Cargar los datos desde archivos CSV para bucles enrollados y desenrollados
df_rolled = pd.read_csv('../rolled.csv')
df_unrolled = pd.read_csv('../unrolled.csv')

# Calcular fallos por instrucción
df_rolled['LL Misses per Instruction'] = df_rolled['LL Misses'] / df_rolled['I Refs']
df_rolled['D1 Misses per Instruction'] = df_rolled['D1 Misses'] / df_rolled['I Refs']
df_unrolled['LL Misses per Instruction'] = df_unrolled['LL Misses'] / df_unrolled['I Refs']
df_unrolled['D1 Misses per Instruction'] = df_unrolled['D1 Misses'] / df_unrolled['I Refs']

df_rolled['I1 Misses per Instruction'] = df_unrolled['I1 Misses'] / df_unrolled['I Refs']
df_unrolled['I1 Misses per Instruction'] = df_unrolled['I1 Misses'] / df_unrolled['I Refs']

# Configurar la primera figura y sus ejes
fig1, ax1 = plt.subplots(2, 1, figsize=(12, 12))

# Gráfico para Fallos LL por instrucción
ax1[0].plot(df_rolled['ArrayTam'], df_rolled['LL Misses per Instruction'], 'o-', color='blue', label='Bucle Enrollado - Fallos LL por Instrucción')
ax1[0].plot(df_unrolled['ArrayTam'], df_unrolled['LL Misses per Instruction'], 's-', color='red', label='Bucle Desenrollado - Fallos LL por Instrucción')
ax1[0].set_title('Comparación de Fallos LL por Instrucción')
ax1[0].set_ylabel('Fallos LL por Instrucción')
ax1[0].legend()
ax1[0].grid(True)

# Gráfico para Fallos D1 por instrucción
ax1[1].plot(df_rolled['ArrayTam'], df_rolled['D1 Misses per Instruction'], '^-', color='green', label='Bucle Enrollado - Fallos D1 por Instrucción')
ax1[1].plot(df_unrolled['ArrayTam'], df_unrolled['D1 Misses per Instruction'], 'x-', color='purple', label='Bucle Desenrollado - Fallos D1 por Instrucción')
ax1[1].set_title('Comparación de Fallos D1 por Instrucción')
ax1[1].set_ylabel('Fallos D1 por Instrucción')
ax1[1].legend()
ax1[1].grid(True)

plt.tight_layout()
plt.savefig('Fallos_LL_D1.png')  # Guardar la primera figura

# Configurar la segunda figura y su eje para Fallos I1
fig2, ax2 = plt.subplots(figsize=(12, 6))

# Gráfico para Fallos I1 por instrucción
ax2.plot(df_rolled['ArrayTam'], df_rolled['I1 Misses per Instruction'], 'd-', color='orange', label='Bucle Enrollado - Fallos I1 por Instrucción')
ax2.plot(df_unrolled['ArrayTam'], df_unrolled['I1 Misses per Instruction'], 'p-', color='brown', label='Bucle Desenrollado - Fallos I1 por Instrucción')
ax2.set_title('Comparación de Fallos I1 por Instrucción')
ax2.set_xlabel('Número de Iteraciones')
ax2.set_ylabel('Fallos I1 por Instrucción')
ax2.legend()
ax2.grid(True)

plt.tight_layout()
plt.savefig('Fallos_I1.png')  # Guardar la segunda figura

plt.show()
