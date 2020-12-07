
namespace SingletonCSharp
{
    class Singleton
    {
        private Singleton()
        {
            data = 0;
            msg = string.Empty;
            instance = this;
        }

        static volatile Singleton instance = null;

        public int data
        {
            get;
            set;
        }

        public string msg
        { get; set; }

        public static Singleton getInstance()
        {
            var temp = instance;
            if (temp == null)
            {
                temp = new Singleton();
            }
            return temp;
        }

    }
}
