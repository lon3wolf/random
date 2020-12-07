using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOPs.EventPublisher
{
    public delegate void NumEventHandler(object sender, NumEventArgs e);
    public class Publisher
    {
        public event NumEventHandler on5;

        protected virtual void RaiseOn5()
        {
            NumEventHandler temp = on5;
            if (temp != null)
            {
                NumEventArgs e = new NumEventArgs();
                e.value = 5;
                temp.Invoke(this, e);
            }
        }

        public void TakeUserInput()
        {
            int i = 0;
            while (i > -1)
            {
                try
                {
                    i = (Convert.ToInt32(Console.ReadLine()));
                }
                catch
                {
                    Console.WriteLine("only number please");
                }
                if (i == 5)
                {
                    RaiseOn5();
                }
            }
        }
    }

    public class NumEventArgs : EventArgs
    {
        public int value { get; set; }
    }
}
