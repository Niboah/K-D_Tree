



for i in range(2, 7):
    nombre_archivo_entrada = f'estandard_k{i}.txt'


    # Leer el archivo de entrada y almacenar los datos en una lista
    datos = []
    with open(nombre_archivo_entrada, 'r') as archivo_entrada:
        for linea in archivo_entrada:
            columna1, columna2 = linea.strip().split()  # Suponiendo que las columnas están separadas por espacios en blanco
            datos.append((int(columna1), columna2))

    # Ordenar los datos por la primera columna
    datos_ordenados = sorted(datos, key=lambda x: x[0])

    # Guardar el archivo ordenado
    with open(nombre_archivo_entrada, 'w') as archivo_salida:
        for dato in datos_ordenados:
            archivo_salida.write(f"{dato[0]} {dato[1]}\n")

    print(f"Archivo ordenado y guardado como {nombre_archivo_entrada}")

for i in range(2, 7):
    nombre_archivo_entrada = f'relaxat_k{i}.txt'


    # Leer el archivo de entrada y almacenar los datos en una lista
    datos = []
    with open(nombre_archivo_entrada, 'r') as archivo_entrada:
        for linea in archivo_entrada:
            columna1, columna2 = linea.strip().split()  # Suponiendo que las columnas están separadas por espacios en blanco
            datos.append((int(columna1), columna2))

    # Ordenar los datos por la primera columna
    datos_ordenados = sorted(datos, key=lambda x: x[0])

    # Guardar el archivo ordenado
    with open(nombre_archivo_entrada, 'w') as archivo_salida:
        for dato in datos_ordenados:
            archivo_salida.write(f"{dato[0]} {dato[1]}\n")

    print(f"Archivo ordenado y guardado como {nombre_archivo_entrada}")

for i in range(2, 7):
    nombre_archivo_entrada = f'squarish_k{i}.txt'


    # Leer el archivo de entrada y almacenar los datos en una lista
    datos = []
    with open(nombre_archivo_entrada, 'r') as archivo_entrada:
        for linea in archivo_entrada:
            columna1, columna2 = linea.strip().split()  # Suponiendo que las columnas están separadas por espacios en blanco
            datos.append((int(columna1), columna2))

    # Ordenar los datos por la primera columna
    datos_ordenados = sorted(datos, key=lambda x: x[0])

    # Guardar el archivo ordenado
    with open(nombre_archivo_entrada, 'w') as archivo_salida:
        for dato in datos_ordenados:
            archivo_salida.write(f"{dato[0]} {dato[1]}\n")

    print(f"Archivo ordenado y guardado como {nombre_archivo_entrada}")