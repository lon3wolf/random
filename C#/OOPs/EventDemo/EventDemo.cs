using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OOPs.EventPublisher;

namespace OOPs
{
    class EventDemo:IDemo
    {
        public void StartDemo()
        {
            Console.Clear();
            Publisher pub = new Publisher();
            pub.on5 += pub_on5;
            pub.TakeUserInput();
        }

        void pub_on5(object sender, NumEventArgs e)
        {
            Console.WriteLine("A value of {0} was entered", e.value);
        }

        public void EndDemo()
        {
            Console.Clear();
        }
    }
}
