# TODO


# Main function defining
def main():
    text = input("Text: ")
    letters = words = sentences = 0

    # Counting for letters words and sentences in text
    for i in range(len(text)):
        if text[i].isalnum():
            letters += 1
        if text[i].isspace():
            words += 1
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            sentences += 1

    # Main logic formula of readability
    words += 1
    l = letters * 100 / words
    s = sentences * 100 / words
    grade = round(0.0588 * l - 0.296 * s - 15.8)

    print_value(grade)


# To print the result
def print_value(grade):
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()