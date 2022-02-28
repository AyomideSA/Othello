/**
 * @author : Ayomide Sola-Ayodele
 * @mailto : ayomide.sola-ayodele@ucdconnect.ie
 * @created : 26/02/2022, Saturday
 **/

import java.util.*;

public class Sorting {
  static Random rand = new Random();

  public static void main(String[] args) {
    List<Integer> list1 = new LinkedList<Integer>();
    Comparator<Integer> integerComparator = (o1, o2) -> {
      return o1.compareTo(o2);
    };
    Integer[] array1 = new Integer[]{8, 7, 2, 21, 8, 5, 0, 23, 4, 3};

    list1.add(1);
    list1.add(3);
    list1.add(2);
    list1.add(2);
    list1.add(0);
    list1.add(8);
    list1.add(6);
    list1.add(0);
    list1.add(4);
    list1.add(10);

    System.out.println("Original List:" + list1);
    System.out.println("Original Array" + Arrays.toString(array1));

    // Sort array/list Here //

    System.out.println("Sorted List:" + list1);
    System.out.println("Sorted Array:" + Arrays.toString(array1));
  }

  /**
   * Sorts a given list by using the Bogo Sort algorithm. <p>
   * @param list
   * @param comparator
   *<p>
   * Worst Case Time Complexity is infinite/undefined <p>
   * Worst Case: Permutation where list is sorted is never produced <p>
   * As the list is randomly shuffled, theoretically, it is possible for a permutation where
   * the list is sorted to never be produced. <p>
   *</p>
   * Worst Case Space Complexity is O(1) <p>
   * No matter how large the size of the list is, the same amount of space will be used i.e.
   * only additional space needed is the space for the temporary variable used when swapping elements in the list.
   */
  public static <T extends Comparable<T>> void bogoSort(final List<T> list, final Comparator<T> comparator) {
    //int count = 0;
    while (!isSorted(list, comparator)) {
      Collections.shuffle(list);
      //count++;
    }
    //System.out.println(count);
  }

  /** Same as Bogo Sort implementation for lists */
  public static <T extends Comparable<T>> void bogoSort(final T[] array, final Comparator<T> comparator) {
    int j;
    while (!isSorted(Arrays.asList(array), comparator)) {
      // Fisher Yates Shuffle: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
      for (int i = array.length - 1; i > 0; i--) {
        j = rand.nextInt(0, i + 1);
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }

  /**
   * @param list
   * @param comparator
   * @param <T>
   * @return true if list is sorted, false if it is not
   */
  private static <T extends Comparable<T>> boolean isSorted(final List<T> list, final Comparator<T> comparator) {
    int i = 0;
    while (i + 1 < list.size()) {
      if (comparator.compare(list.get(i), list.get(i + 1)) > 0) {
        return false;
      }
      i++;
    }
    return true;
  }

  /**
   * Sorts a given list by using the Bubble Sort algorithm.<p>
   * @param list
   * @param comparator
   *<p>
   * Worst Case Time Complexity is O(n^2) <p>
   * Worst Case: Has to go through the whole list during every pass n times.<p>
   * In this implementation, (n - 1) comparisons are made during each pass
   * through the list and n passes through the list are made.<p>
   * n*(n - 1) comparisons would have to be made in total in the worst case.<p>
   * n*(n - 1) = n^2 - n = O(n^2).<p>
   *<p>
   * Worst Case Space Complexity is O(1)<p>
   * Similarly to Bogo Sort,the only additional space required is for a temporary variable
   * used when swapping elements in the list.<p>
   * <p>
   * Improvements<p>
   * As during the first pass, the largest element will be in the correct place and then during the next pass
   * the second-largest element will be in its correct position,<p>there would be no need to pass through the full list
   * each time. So the condition for the inner loop's termination could be changed to (j + 1 < list.size() - i).<p>
   * As passing through the list with no swaps occurring means that the list is already sorted, a condition to
   * terminate the sorting algorithm when a pass with no swapping has occurred could be added.<p>
   */
  public static <T extends Comparable<T>> void bubbleSort(final List<T> list, final Comparator<T> comparator) {
    //int comparisons = 0;
    for (int i = 0; i < list.size(); i++) {
      // Adjacent elements in list compared against each other list.size-1 times
      for (int j = 0; j + 1 < list.size(); j++) {
        if (comparator.compare(list.get(j), list.get(j + 1)) > 0) {
          Collections.swap(list, j, j + 1);
        }
        //comparisons++;
      }
    }
    //System.out.println(comparisons);
  }

  /** Same as Bubble Sort implementation for lists */
  public static <T extends Comparable<T>> void bubbleSort(final T[] array, final Comparator<T> comparator) {
    T data1;
    T data2;
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j + 1 < array.length; j++) {
        data1 = array[j];
        data2 = array[j + 1];
        if (comparator.compare(data1, data2) > 0) {
          swapArray(array, j, j + 1);
        }
      }
    }
  }

  /**
   * Sorts a given list by using the selection sort algorithm.<p>
   * @param list
   * @param comparator
   *<p>
   * Worst Case Time Complexity is O(n^2)<p>
   * Worst case: Has to go through the all the remaining elements in the list to find minimum value.<p>
   * (n - 1) + (n - 2) + (n - 3)...+ 1 comparisons would have to be made in the worst case.<p>
   * (n - 1) + (n - 2)...+ 1 = (n^2 - n)/2 = O(n^2).<p>
   *<p>
   * Worst Case Space Complexity is O(1)<p>
   * Similarly to Bogo Sort and Bubble Sort the amount of additional space used is not dependent on the
   * size of the list.<p>
   *<p>
   */
  public static <T extends Comparable<T>> void selectionSort(final List<T> list, final Comparator<T> comparator) {
    int mininumValueIndex;
    for (int i = 0; i < list.size() - 1; i++) {
      mininumValueIndex = findIndexMin(list, comparator, i);
      Collections.swap(list, i, mininumValueIndex);
    }
  }

  /** Same as Selection Sort implementation for lists */
  public static <T extends Comparable<T>> void selectionSort(final T[] array, final Comparator<T> comparator) {
    int mininumValueIndex;
    for (int i = 0; i < array.length-1; i++) {
      mininumValueIndex = findIndexMin(Arrays.asList(array), comparator, i);
      swapArray(array, i, mininumValueIndex);
    }
  }

  /**
   *
   * @param array
   * @param i index of element that will be swapped with element at index i.
   * @param j index of element that will be swapped with element at index j.
   * @param <T>
   */
  private static <T extends Comparable<T>> void swapArray(T[] array, int i, int j) {
    T temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  /**
   *
   * @param list
   * @param comparator
   * @param start beginning of where we will start searching for minimum element in list
   * @param <T>
   * @return the smallest element in the list
   */
  private static <T extends Comparable<T>> int findIndexMin(final List<T> list, final Comparator<T> comparator, int start) {
    T min = list.get(start);
    int minIndex = start;
    for (int i = start; i < list.size(); i++) {
      if (comparator.compare(list.get(i), min) < 0) {
        min = list.get(i);
        minIndex = i;
      }
    }
    return minIndex;
  }

  /**
   * Sorts a given list by using the Merge Sort algorithm.<p>
   * @param list
   * @param comparator
   *<p>
   * Worst Case Time Complexity is O(n(log(n)))<p>
   * Worst Case: Time Complexity for Merge Sort is the same in all situations.<p>
   * Merge sort recursively divides the list into two smaller lists and then those two sub lists are sorted<p>
   * i.e. n -> n/2 -> n/4...n/(2^k)<p>
   * This division can be represented by log(n).<p>
   * When being merged n/2 comparisons are done each time.<p>
   * T(n/2) = O(n)<p>
   * O(n) * log(n)) = O(nlog(n))<p>
   *<p>
   * Worst Case Space Complexity is O(n)<p>
   * Merge Sort is a recursive algorithm divide and conquer algorithm. The number of calls it makes depends on the
   * size of the input.<p>
   * In the worst case, n recursive calls are made (the more calls, the more space taken up on stack)
   * Thus, the worst case space complexity is O(n)<p>
   * <p>
   * Improvements<p>
   * As Merge Sort has a large overhead for small sub lists, we could instead call Insertion Sort for smaller lists
   * (e.g. when list size is <= 10)<p>
   * A check could be added to see if two sub list are already sorted (if last element of first list is smaller than
   * last element of second list then the merge method would not be called)
   */
  public static <T extends Comparable<T>> void mergeSort(final List<T> list, final Comparator<T> comparator) {
    List<T> sortedList = mergeSortWorker(list, comparator);
    list.clear();
    list.addAll(sortedList);
  }

  /** Same as Merge Sort implementation for lists */
  public static <T extends Comparable<T>> void mergeSort(final T[] array, final Comparator<T> comparator) {
    List<T> sortedList = mergeSortWorker(Arrays.asList(array), comparator);
    for (int i = 0; i < array.length; i++) {
      array[i] = sortedList.get(i);
    }
  }

  /**
   * @param list
   * @param comparator
   * @param <T>
   * @return sorted list
   */
  private static <T extends Comparable<T>> List<T> mergeSortWorker(List<T> list, Comparator<T> comparator) {
    if (list.size() == 1) // No need to sort a list that is only one element long
      return list;
    int mid = list.size() / 2;
    List<T> leftDivision = new ArrayList<>();
    List<T> rightDivision = new ArrayList<>();
    for (int i = 0; i < mid; i++) {
      leftDivision.add(list.get(i));
    }
    for (int i = mid; i < list.size(); i++) {
      rightDivision.add(list.get(i));
    }
    List<T> sortedLeftDivision = new ArrayList<>(mergeSortWorker(leftDivision, comparator));
    List<T> sortedRightDivision = new ArrayList<>(mergeSortWorker(rightDivision, comparator));
    // Print statements to show progress of merge sort //
//    System.out.println("Left:" + sortedLeftDivision);
//    System.out.println("Right:" + sortedRightDivision);
//    List<T> sortedList = new ArrayList<>(merge(sortedLeftDivision, sortedRightDivision, comparator));
//    System.out.println("Merged:" + sortedList + "\n");
//    return sortedList;
    return new ArrayList<>(merge(sortedLeftDivision, sortedRightDivision, comparator));
  }

  /**
   * @param leftDivision left part of partitioned list
   * @param rightDivision right part of partitioned list
   * @param comparator comparator for objects in both list divisions
   * @param <T>
   * @return a new list created by merging leftDivision and rightDivision in an ordered way
   */
  private static <T extends Comparable<T>> List<T> merge(List<T> leftDivision, List<T> rightDivision, Comparator<T> comparator) {
    List<T> mergedList = new ArrayList<T>();
    while (!leftDivision.isEmpty() && !rightDivision.isEmpty()) {
      if (comparator.compare(leftDivision.get(0), rightDivision.get(0)) <= 0) {
        mergedList.add(leftDivision.remove(0));
      } else if (comparator.compare(rightDivision.get(0), leftDivision.get(0)) <= 0) {
        mergedList.add(rightDivision.remove(0));
      }
    }
    if (!leftDivision.isEmpty()) {
      mergedList.addAll(leftDivision);
    } else if (!rightDivision.isEmpty()) {
      mergedList.addAll(rightDivision);
    }
    return mergedList;
  }

  /**
   * Sorts a given list by using the Quick Sort algorithm.<p>
   * @param list
   * @param comparator
   *<p>
   * Worst Case Time Complexity is O(n^2)<p>
   * Occurs when pivot chosen is either always the largest or smallest number in the collection.<p>
   * Results in (n-1) comparisons for first partition and the list
   * is divided unevenly i.e. divided into two sub lists of size 0 and (n-1)<p>
   * The next partition does (n-2) comparisons and then the next partition does (n-3) comparisons and so on
   * all the way down to 2 comparisons<p>
   * (n - 1) + (n - 2) + (n - 3)... + 2 = n(n + 1)/2 - 1 = O(n^2)<p>
   *</p>
   * Worst Case Space Complexity is O(n)<p>
   * Similarly to Merge Sort, Quick Sort is also a recursive divide and conquer algorithm.<p>
   * The number of calls it makes depends on the size of the input.<p>
   * In the worst case, n recursive calls are made (more space taken up on stack)<p>
   * thus, the worst case space complexity is O(n)<p>
   * <p>
   * Issues and solutions<p>
   * 1. Similarly to Merge Sort, Quick Sort also has a large overhead for small lists. Insertion sort could be called
   * instead for small lists to overcome this issue<p>
   * 2. The efficiency of Quick Sort relies on picking a good pivot.<p>
   *    If a good pivot isn't picked, Quick Sort's performance can degrade very fast. Instead of picking the first, last or even a random element from a collection, picking the
   *    median element almost ensures that the collection is divided into two approximately equal parts.<p>
   * 3. Quick Sort is unable to efficiently sort a collection where all elements are identical as
   *    sorting a collection with equal elements guarantees worst case performance for Quick Sort.<p>
   *    To lessen the effect of this, the collection could be divided into three parts instead of two parts.<p>
   *    The three parts would be as follows:<p>
   *        Left part: Elements that are less than the pivot but not equal to it.<p>
   *        Middle part: Elements that are equal to the pivot.<p>
   *        Right part: Elements that are greater than the pivot but no equal to it.<p>
   * 4. Quick Sort doesn't work as well for partially sorted collections as there is a higher chance of choosing a pivot that
   *    is the smallest or largest element of the collection.<p>
   *    This can be avoided and Quick Sort's performance can be almost
   *    guaranteed by randomly shuffling the collection before sorting.
   */
  public static <T extends Comparable<T>> void quickSort(final List<T> list, final Comparator<T> comparator) {
    Collections.shuffle(list);
    //System.out.println("List to be sorted " + list);
    quickSortWorker(list, comparator, 0, list.size() - 1);
  }

  /** Same as Quick Sort implementation for lists */
  public static <T extends Comparable<T>> void quickSort(final T[] array, final Comparator<T> comparator) {
    List<T> arrayAsList = Arrays.asList(array);
    quickSortWorker(arrayAsList, comparator, 0, array.length - 1);
    for (int i = 0; i < array.length; i++) {
      array[i] = arrayAsList.get(i);
    }
  }

  /**
   * @param list
   * @param comparator
   * @param low starting point of search for partition.
   * @param high ending point of search for partition.
   * @param <T>
   */
  private static <T extends Comparable<T>> void quickSortWorker(List<T> list, Comparator<T> comparator, int low, int high) {
    if (high > low) {
      int partitoningIndex = partition(list, low, high, comparator);
      quickSortWorker(list, comparator, low, partitoningIndex - 1);
      quickSortWorker(list, comparator, partitoningIndex + 1, high);
    }
  }

  /**
   * @param list
   * @param low starting point of search through list
   * @param high ending point of search through list
   * @param comparator
   * @param <T>
   * @return returns list that has been partitioned based on a chosen pivot.<p>
   *         All elements less than pivot are to its left and all elements greater than pivot are to its right.
   */
  private static <T extends Comparable<T>> int partition(List<T> list, int low, int high, Comparator<T> comparator) {
    T pivot = list.get(low);
    // System.out.println("Pivot: " + pivot);
    int i = low;
    int j = high + 1;
    while (true) {
      // Searches from left for elements equal to or greater than pivot
      while (comparator.compare(list.get(++i), pivot) < 0) {
        if (i == high) {
          break;
        }
      }
      // Searches from right for elements equal to or less than pivot
      while (comparator.compare(pivot, list.get(--j)) < 0) {
        if (j == low) {
          break;
        }
      }
      // If search from left and right overlap with each other
      if (i >= j) {
        break;
      }
      Collections.swap(list, i, j);
    }
    Collections.swap(list, low, j);
    // System.out.println("Partitioned Collection: " + list);
    return j;
  }

}
