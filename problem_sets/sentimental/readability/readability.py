from cs50 import get_string

# Get user input
text = get_string("Text: ")

# Initialize counts
letters = 0
words = 1  # Start at 1 to count the first word
sentences = 0

# Analyze text
for char in text:
    if char.isalpha():
        letters += 1
    elif char.isspace():
        words += 1
    elif char in ['.', '!', '?']:
        sentences += 1

# Calculate averages per 100 words
L = (letters / words) * 100
S = (sentences / words) * 100

# Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Output grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
