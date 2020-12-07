using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOPs
{
    class Program
    {

        static void Main(string[] args)
        {
            string cmd = "";
            IDemo demo = null;
            while (cmd != "quit")
            {
                Console.Clear();
                Console.Write("Enter a command: ");
                cmd = Console.ReadLine();
                if (!string.IsNullOrEmpty(cmd))
                {
                    switch(cmd.ToLower())
                    { 
                        case "evtd":
                            demo = new EventDemo();
                            break;
                        case "vod":
                            demo = new VirtualOverride.VirtualOverRideDemo();
                            break;
                        case "td":
                            demo = new Types.TypeDemo();
                            break;
                        default:
                            break;
                    }
                    if(demo != null && cmd.ToLower() != "quit")
                    {
                        ShowDemo(demo);
                    }
                }
            }
            
        }
    

        public static void ShowDemo(IDemo demo)
        {
            demo.StartDemo();
            demo.EndDemo();
            Console.ReadKey();
        }
    }
}
