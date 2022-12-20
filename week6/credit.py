# TODO

# Main function
def main():
    num = get_card()
    checksum = check_card(num)
    print_card(num, checksum)


# Get valid input of the user
def get_card():
    while True:
        num = input("Number: ")
        length = len(str(num))
        if length != 13 and length != 15 and length != 16:
            print("INVALID")
            break
        elif num.isnumeric():
            break

    return num


# Logic of the code to check credit
def check_card(num):
    length = len(str(num))

    if length % 2 == 0:
        flag = True
    else:
        flag = False

    checksum = 0
    for i in range(length):
        if flag:
            tmp = int(num[i]) * 2

            if tmp >= 10:
                checksum += tmp - 9
            else:
                checksum += tmp
            flag = False
        else:
            checksum += int(num[i])
            flag = True
    return checksum


# Prints the final value
def print_card(num, checksum):
    check = int(num[0]) * 10 + int(num[1])

    if checksum % 10 == 0:
        if check == 34 or check == 37:
            print("AMEX")
        elif 51 <= check <= 55:
            print("MASTERCARD")
        elif int(num[0]) == 4:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


# Calling from the main function
if __name__ == "__main__":
    main()