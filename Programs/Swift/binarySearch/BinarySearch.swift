import Foundation

func binarySearch<T: Comparable>(_ array: [T], key: T) -> Int {
    var lower = 0
    var upper = array.count
    while lower < upper {
        let midIndex = lower + (upper - lower) / 2
        if array[midIndex] == key {
            return midIndex
        } else if array[midIndex] < key {
            lower = midIndex + 1
        } else {
            upper = midIndex
        }
    }
    return -1
}

let numbers = [5, 31, 30, 40, 50, 1, 53, 59, 200, 4000]
print("Array index response: \(binarySearch(numbers, key: 1))") 

