import java.util.Arrays;

public class HW11
{  
    public static void main( String[] args ) {
    	int size = 10000;
        int[][] arr1 = new int[size][size];
        int[][] arr2 = new int[size][size];
        int[][] arrFinal = new int[size][size];
        int numThreads[] = {1, 2, 4};
        
        for(int[] row: arr1)
        {
        	Arrays.fill(row, 2);
        }
        
        for(int[] row: arr2)
        {
        	Arrays.fill(row, 3);
        }
        
        for(int num: numThreads)
        {
        	Thread[] threads = new Thread[num];
        	
        	long before = System.currentTimeMillis();
        
        	for(int temp = 0; temp < num; temp++)
        	{
        		if(num == 1)
        		{
        			threads[temp] = new Thread(new ThreadingMultiply(0, size - 1, 0, size - 1, arr1, arr2, arrFinal));
        		}
        		
        		else if(num == 2)
        		{
        			threads[temp] = new Thread(new ThreadingMultiply((size / 2) * temp, size - 1 - (size / 2) * (temp - 1), 0, size - 1, arr1, arr2, arrFinal));
        		}
        		
        		else if(num == 4)
        		{
        			if(temp == 0)
        			{
        				threads[temp] = new Thread(new ThreadingMultiply(0, (size / 2) - 1, 0, (size / 2) - 1, arr1, arr2, arrFinal));
        			}
        			
        			else if(temp == 1)
        			{
        				threads[temp] = new Thread(new ThreadingMultiply(0, (size / 2) - 1, (size / 2), size - 1, arr1, arr2, arrFinal));
        			}
        			
        			else if(temp == 2)
        			{
        				threads[temp] = new Thread(new ThreadingMultiply((size / 2), size - 1, 0, (size / 2) - 1, arr1, arr2, arrFinal));
        			}
        			
        			else if(temp == 3)
        			{
        				threads[temp] = new Thread(new ThreadingMultiply((size / 2), size - 1, (size / 2), size - 1, arr1, arr2, arrFinal));
        			}
        		}
        	}
        	
        	long after = System.currentTimeMillis();
        	
        	long timeTaken = after - before;
        	
        	System.out.println("Time taken for " + num + " threads was " + timeTaken);
        }
	}
}