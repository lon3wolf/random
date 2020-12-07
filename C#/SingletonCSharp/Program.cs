using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SingletonCSharp
{
    class Program
    {
        static void Main(string[] args)
        {

            Singleton test1 = Singleton.getInstance();
            test1.data = 5;
            test1.msg = "This is an instance";
            Singleton test2 = Singleton.getInstance();
            Console.WriteLine(test2.data);
            Console.WriteLine(test2.msg);
            Console.ReadKey();
        }
    }
}
