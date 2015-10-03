import java.util.Arrays;

public class HW11
{  
    public static void main( String[] args ) {           
        int[][] arr1 = new int[100][100];
        int[][] arr2 = new int[100][100];
        
        for(int[] row: arr1)
        {
        	Arrays.fill(row, 2);
        }
        
        for(int[] row: arr2)
        {
        	Arrays.fill(row, 3);
        }
        
        int[][] arrFinal = multiplyOneThread(arr1, arr2);
        
        for(int[] row: arrFinal)
        {
        	for(int val: row)
        	{
        		System.out.print(val);
        	}
        	System.out.println();
        }
    }

	private static int[][] multiplyOneThread(int[][] arr1, int[][] arr2)
	{
		int[][] arrFinal = new int[100][100];
		
		for(int i = 0; i < 100; i++)
		{
			for(int j = 0; j < 100; j++)
			{
				arrFinal[i][j] = arr1[i][j] * arr2[i][j];
			}
		}
		
		return(arrFinal);
	}
}