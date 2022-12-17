#include "helpers.h"
#include<math.h>

// Capping max value to 255 for sepia filter
int cap255(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else
    {
        return color;
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float greyScale;
    int initialRed, initialGreen, initialBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            initialRed = image[i][j].rgbtRed;
            initialGreen = image[i][j].rgbtGreen;
            initialBlue = image[i][j].rgbtBlue;

            greyScale = round((initialRed + initialGreen + initialBlue) / 3.0);

            image[i][j].rgbtRed = greyScale;
            image[i][j].rgbtGreen = greyScale;
            image[i][j].rgbtBlue = greyScale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int initialRed, initialGreen, initialBlue;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            initialRed = image[i][j].rgbtRed;
            initialGreen = image[i][j].rgbtGreen;
            initialBlue = image[i][j].rgbtBlue;

            sepiaRed = round(.393 * initialRed + .769 * initialGreen + .189 * initialBlue);
            sepiaGreen = round(.349 * initialRed + .686 * initialGreen + .168 * initialBlue);
            sepiaBlue = round(.272 * initialRed + .534 * initialGreen + .131 * initialBlue);

            sepiaRed = cap255(sepiaRed);
            sepiaGreen = cap255(sepiaGreen);
            sepiaBlue = cap255(sepiaBlue);

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int j = 0;
        RGBTRIPLE temp_row;

        while (j < width - j - 1)
        {
            int loop = width - j - 1;

            temp_row.rgbtBlue = image[i][j].rgbtBlue;
            temp_row.rgbtGreen = image[i][j].rgbtGreen;
            temp_row.rgbtRed = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][loop].rgbtBlue;
            image[i][j].rgbtGreen = image[i][loop].rgbtGreen;
            image[i][j].rgbtRed = image[i][loop].rgbtRed;

            image[i][loop].rgbtBlue = temp_row.rgbtBlue;
            image[i][loop].rgbtGreen = temp_row.rgbtGreen;
            image[i][loop].rgbtRed = temp_row.rgbtRed;
            j++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_photo[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = 0;
            int green = 0;
            int red = 0;
            int num = 0;
            for (int k = 0; k < 3; k++)
            {
                int a = i - 1 + k;
                for (int l = 0; l < 3; l++)
                {
                    int b = j - 1 + l;
                    if (a >= 0 && a < height && b >= 0 && b < width)
                    {
                        blue += image[a][b].rgbtBlue;
                        green += image[a][b].rgbtGreen;
                        red += image[a][b].rgbtRed;
                        num++;
                    }
                }
            }
            blue = roundf((float)blue / num);
            green = roundf((float)green / num);
            red = roundf((float)red / num);
            temp_photo[i][j].rgbtBlue = blue;
            temp_photo[i][j].rgbtGreen = green;
            temp_photo[i][j].rgbtRed = red;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp_photo[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp_photo[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp_photo[i][j].rgbtRed;
        }
    }
    return;
}

