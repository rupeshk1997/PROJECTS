# Python program to implement Morse Code encoder
# Morse code values represented in form of dictionary
Morse_Code_values = {'A': '.-', 'B': '-...',
                     'C': '-.-.', 'D': '-..', 'E': '.',
                     'F': '..-.', 'G': '--.', 'H': '....',
                     'I': '..', 'J': '.---', 'K': '-.-',
                     'L': '.-..', 'M': '--', 'N': '-.',
                     'O': '---', 'P': '.--.', 'Q': '--.-',
                     'R': '.-.', 'S': '...', 'T': '-',
                     'U': '..-', 'V': '...-', 'W': '.--',
                     'X': '-..-', 'Y': '-.--', 'Z': '--..',
                     '1': '.----', '2': '..---', '3': '...--',
                     '4': '....-', '5': '.....', '6': '-....',
                     '7': '--...', '8': '---..', '9': '----.',
                     '0': '-----', ', ': '--..--', '.': '.-.-.-',
                     '?': '..--..', '/': '-..-.', '-': '-....-',
                     '(': '-.--.', ')': '-.--.-'}


# Function to encrypt the string i.e. converting message to morse code
def encrypt(message):
    english_to_morse = ''  # it stores the morse translated form of the english string
    for char in message:
        if char != ' ':

            # Search the above dictionary and assign the
            # indicated morse code to individual character of the string entered.
            # With proper spacing betweeen words.
            english_to_morse += Morse_Code_values[char] + ' '
        else:
            # 1 space for different characters
            # and 2 space for different words
            english_to_morse += ' '

    return english_to_morse


def main_function():  # driver function
    message = input("Enter the message you want to encrypt: ")
    output = encrypt(message.upper())
    print(output)


if __name__ == '__main__':
    main_function()
