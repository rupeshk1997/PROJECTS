def odd_even_sort(input_list):
    """this algorithm uses the same idea of bubblesort,
    but by first dividing in two phase (odd and even).
    Originally developed for use on parallel processors
    with local interconnections.
    """
    sorted = False
    while sorted is False:  # Until all the indices are traversed keep looping
        sorted = True
        for i in range(0, len(input_list) - 1, 2):  # iterating over all even indices
            if input_list[i] > input_list[i + 1]:
                input_list[i], input_list[i +
                                          1] = input_list[i + 1], input_list[i]
                # swapping if elements not in order
                sorted = False

        for i in range(1, len(input_list) - 1, 2):  # iterating over all odd indices
            if input_list[i] > input_list[i + 1]:
                input_list[i], input_list[i +
                                          1] = input_list[i + 1], input_list[i]
                # swapping if elements not in order
                sorted = False
    return input_list


if __name__ == "__main__":
    print("Enter list to be sorted: ", end="")
    # Entering elements of the list in one line
    list1 = [int(x) for x in input().split()]
    input_list = list(list1)
    sorted_list = odd_even_sort(input_list)
    print("The sorted list is: ", end="")
    print(sorted_list)
