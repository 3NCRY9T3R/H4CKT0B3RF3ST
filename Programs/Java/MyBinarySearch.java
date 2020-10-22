public class MybinarySearch {

	private int[] arr;

    public MybinarySearch(int[] arr){
        this.arr = arr;
    }
    public boolean binarySearch(int searchElement){
        boolean response = false;
        int low = 0;
        int high = arr.length -1;
        while(low <= high){
            int mid = (low + high) /2;
            if(searchElement == arr[mid]){
                response = true;
                return response;
            }
            else if(searchElement < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return response;
    }

    public static void main(String[] args) {
        int[] sortedArray = {10, 20, 30, 40, 50, 60, 70};
        MybinarySearch object = new MybinarySearch(sortedArray);
        boolean result = object.binarySearch(60);
        if(result){
            System.out.println("element found");
        }
        else {
            System.out.println("element not found");
        }
    }
}