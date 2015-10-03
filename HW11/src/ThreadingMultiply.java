public class ThreadingMultiply implements Runnable
{
	private int rowStart;
	private int rowStop;
	private int colStart;
	private int colStop;
	private int arr1[][];
	private int arr2[][];
	private int arrFinal[][];
	
	public ThreadingMultiply(int rowStart, int rowStop, int colStart, int colStop, int arr1[][], int arr2[][], int arrFinal[][])
	{
		this.rowStart = rowStart;
		this.rowStop = rowStop;
		this.colStart = colStart;
		this.colStop = colStop;
		this.arr1 = arr1;
		this.arr2 = arr2;
		this.arrFinal = arrFinal;
	}
	
	@Override
	public void run()
	{
		for(int i = rowStart; i < rowStop; i++)
		{
			for(int j = colStart; j < colStop; j++)
			{
				arrFinal[i][j] = arr1[i][j] * arr2[i][j];
			}
		}
	}
}