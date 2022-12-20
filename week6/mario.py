# TODO

# Main function with main logic
def main():
    height = get_height()
    for row in range(height):
        for i in range(height - row - 1, 0, -1):
            print(" ", end="")
        for i in range(row + 1):
            print("#", end="")
        print()

# Get valid input from user


def get_height():
    while True:
        try:
            num = int(input("Height: "))
            if 1 <= num <= 8:
                break
        except ValueError:
            print("Provide an integer.")
    return num


main()
