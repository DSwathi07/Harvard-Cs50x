#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for height between 1 and 8 (inclusive)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop through each row
    for (int row = 1; row <= height; row++)
    {
        // Print spaces for left pyramid
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print hashes for left pyramid
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print hashes for right pyramid
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}
