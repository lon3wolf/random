using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixRotation
{
    class Program
    {
        static void Main(string[] args)
        {
            int m = 4, n = 4, r = 1, l = 0;
            string[] parts = Console.ReadLine().Split(new char[] { ' ' });
            m = Convert.ToInt32(parts[0]);
            n = Convert.ToInt32(parts[1]);
            r = Convert.ToInt32(parts[2]);

            int[,] arr = new int[m, n];

            for (int j = 0; j < m; j++)
            {
                parts = Console.ReadLine().Split(new char[] { ' ' });

                for (int i = 0; i < n; i++)
                {
                    arr[j, i] = Convert.ToInt32(parts[i]);
                }
            }

            //printArr(arr, m, n);

            while (r > 0)
            {
                r--;
                while (rotate(arr, m, n, l))
                {
                    l++;
                }
                l = 0;
            }

            printArr(arr, m, n);
            // wait for the input
            Console.ReadKey();
        }

        static bool rotate(int[,] arr, int m, int n, int l) // l is layer
        {
            if (m - l <= l || n - l <= l)
            {
                return false;
            }

            int t = arr[l, l]; //temp store;
            for (int i = l + 1; i < n - l; i++)
            {
                arr[l, i - 1] = arr[l, i];
            }

            for (int i = l + 2; i <= m; i++)
            {
                arr[i - 2, n - l - 1] = arr[i - 1, n - l - 1];
            }

            for (int i = n - l; i > l+1; i--)
            {
                arr[m - l - 1, i - 1] = arr[m - l - 1, i - 2];
            }

            for (int i = m - l; i >= l + 2; i--)
            {
                arr[i - 1, l] = arr[i - 2, l];
            }

            arr[l + 1, l] = t;
            return true;
        }

        static void printArr(int[,] arr, int m, int n)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write("{0} ", arr[i, j]);
                }
                Console.WriteLine();
            }
        }
    }
}

#region Test Input
//  first line has dimension of array m,n & number of rotations
//  m n r
//  4 4 2
//  1 2 3 4
//  5 6 7 8
//  9 10 11 12
//  13 14 15 16
//  
//  4 4 1
//  1 2 3 4
//  5 6 7 8
//  9 10 11 12
//  13 14 15 16
//  
//  5 4 7
//  1 2 3 4
//  7 8 9 10
//  13 14 15 16
//  19 20 21 22
//  25 26 27 28
//  
//  10 8 40
//  9718805 60013003 5103628 85388216 21884498 38021292 73470430 31785927
//  69999937 71783860 10329789 96382322 71055337 30247265 96087879 93754371
//  79943507 75398396 38446081 34699742 1408833 51189 17741775 53195748
//  79354991 26629304 86523163 67042516 54688734 54630910 6967117 90198864
//  84146680 27762534 6331115 5932542 29446517 15654690 92837327 91644840
//  58623600 69622764 2218936 58592832 49558405 17112485 38615864 32720798
//  49469904 5270000 32589026 56425665 23544383 90502426 63729346 35319547
//  20888810 97945481 85669747 88915819 96642353 42430633 47265349 89653362
//  55349226 10844931 25289229 90786953 22590518 54702481 71197978 50410021
//  9392211 31297360 27353496 56239301 7071172 61983443 86544343 43779176
#endregion
