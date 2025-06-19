from cs50 import get_float

# Prompt user until a non-negative float is provided
while True:
    dollars = get_float("Change owed: ")
    if dollars >= 0:
        break

# Convert dollars to cents, rounding to avoid floating-point imprecision
cents = round(dollars * 100)

# Initialize coin count
coins = 0

# Count coins using a greedy algorithm
for coin in [25, 10, 5, 1]:
    coins += cents // coin
    cents %= coin

# Output the result
print(coins)
