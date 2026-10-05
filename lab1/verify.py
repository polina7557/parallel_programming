import sys

try:
    import numpy as np

    with open('input.txt', 'r') as f:
        data = f.read().split()

    n = int(data[0])
    A = np.array(data[1 : 1 + n*n], dtype=float).reshape(n, n)
    B = np.array(data[1 + n*n :], dtype=float).reshape(n, n)

    C_python = np.dot(A, B)

    with open('output.txt', 'r') as f:
        data_cpp = f.read().split()

    if len(data_cpp) == n*n + 1:
        data_cpp = data_cpp[1:]
        
    C_cpp = np.array(data_cpp, dtype=float).reshape(n, n)

    if np.allclose(C_python, C_cpp):
        print("Верно. Результаты одинаковые")
    else:
        print("Неверно. Результаты разные")

except Exception as e:
    print("Ошибка:", e)

input("\nНажмите Enter для выхода...")
