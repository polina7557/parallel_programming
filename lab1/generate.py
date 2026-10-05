import random

for size in [50, 100, 200]:
    with open(f"input_{size}.txt", "w") as f:
        f.write(f"{size}\n")

        for _ in range(size):
            f.write(' '.join(str(random.randint(0, 9)) for _ in range(size)) + '\n')

        for _ in range(size):
            f.write(' '.join(str(random.randint(0, 9)) for _ in range(size)) + '\n')
    print(f"Файл input_{size}.txt создан!")
