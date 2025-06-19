from cs50 import get_int

# Prompt user for height until a valid input is received
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

# Print the half-pyramid
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)
