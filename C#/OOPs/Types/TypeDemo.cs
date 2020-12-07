using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace OOPs.Types
{
    class TypeDemo : IDemo
    {
        public void StartDemo()
        {
            SampleType st = new SampleType();
            st.str = "Demo";
            st.count = 1;

            Type t = st.GetType();
            FieldInfo[] fields  = t.GetFields(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.DeclaredOnly | System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.NonPublic);

            foreach(FieldInfo field in fields)
            {
                Console.Write("Name: \t"+field.Name + " \t Type: " + field.FieldType.Name +" \t Public: "+ field.IsPublic);
                Console.WriteLine("\tValue: \t" + field.GetValue(st).ToString());
            }
        }

        public void EndDemo()
        {
            Console.ReadKey();
            Console.Clear();
        }
    }

    class SampleType
    {
        int i = 0;
        public int count = 0;
        public string str;
        public List<int> TestList;
        public string[] Names = new string[5];

        public SampleType()
        {
            TestList = new List<int>();
        }
    }
}
