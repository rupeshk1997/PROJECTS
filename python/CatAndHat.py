# Program to Print True if cat and hat appear same number of times in str, otherwise print False.
def cat_hat(str):
    cat_sum = 0
    hat_sum = 0
    for i in range(len(str)-2):
        if (str[i:i+3] == 'cat'):
            cat_sum += 1
        elif (str[i:i+3] == 'hat'):
            hat_sum += 1
    if (hat_sum == cat_sum):
        return True
    else:
        return False


def main():
    testcases = int(input())  # different testcases
    while(testcases > 0):
        str = input()
        print(cat_hat(str))
        testcases -= 1


# Driver code
if __name__ == '__main__':
    main()
