using System;

// Algo to find the unique number, When the number in the array is duplicate and only one number is unique
// Algo - Do streaming XOR
namespace DuplicateNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = {1,2,5,6,7,9,2, 5, 6, 7, 9 };
            int dup = arr[0]; // the single number
            for (int i=1; i<arr.Length; i++)
            {
                dup ^= arr[i];
            }

            Console.WriteLine("the single number is: {0}", dup);
            Console.ReadKey();
        }
    }
}
