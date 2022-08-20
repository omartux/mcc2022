import time
inicio = time.time()


# There are different ways to do a Quick Sort partition, this implements the
# Hoare partition scheme. Tony Hoare also created the Quick Sort algorithm.
def partition(nums, low, high):
    # We select the middle element to be the pivot. Some implementations select
    # the first element or the last element. Sometimes the median value becomes
    # the pivot, or a random one. There are many more strategies that can be
    # chosen or created.
    pivot = nums[(low + high) // 2]
    
    i = low - 1
    j = high + 1
    while True:
        i += 1
        while nums[i] < pivot:
            i += 1

        j -= 1
        while nums[j] > pivot:
            j -= 1

        if i >= j:
            return j

        # If an element at i (on the left of the pivot) is larger than the
        # element at j (on right right of the pivot), then swap them
        nums[i], nums[j] = nums[j], nums[i]


def quick_sort(nums):
    # Create a helper function that will be called recursively
    def _quick_sort(items, low, high):
        if low < high:
            # This is the index after the pivot, where our lists are split
            split_index = partition(items, low, high)
            _quick_sort(items, low, split_index)
            _quick_sort(items, split_index + 1, high)

    _quick_sort(nums, 0, len(nums) - 1)


# Verify it works
random_list_of_nums = [-608, 449, 333, 861, -627, -398, -714, 977, 562, -684, 490, -945, 460, -773, -448, -344, -706, 272, -842, -832, -359, -96, -943, 328, -498, 790, -737, 896, 843, -887, 844, 282, 152, -235, 663, 585, 610, 752, -285, 686, -784, 604, 709, 559, 803, -674, -245, -29, 101, 964, 315, -280, 213, 909, -16, -598, 207, -276, -858, 522, -605, 878, -764, 903, -88, -540, -768, -473, -715, 572, -650, -707, -262, -23, -166, 425, 121, -409, -415, -441, -256, 22, 688, 720, 697, -400, -627, 755, 596, 229, -186, -744, 236, 132, -445, 181, 555, 11, 701, 165]
quick_sort(random_list_of_nums)
print(random_list_of_nums)
fin = time.time()
tiempo = fin-inicio

print(str(tiempo)+" segundos") # 1.5099220275878906
print(str(tiempo*1000)+" milisegundos ")
print('para '+ str(len(random_list_of_nums))+' elementos')
