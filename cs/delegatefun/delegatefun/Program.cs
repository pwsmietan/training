namespace delegatefun
{
    public delegate void SampleDelegate();

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Single-cast delegate");
            SampleDelegate del = new SampleDelegate(SampleMethodOne);
            del();
            Console.WriteLine("----------------\n");

            Console.WriteLine("Multi-cast delegates");
            SampleDelegate del1, del2, del3, del4; ;
            del1 = new SampleDelegate(SampleMethodOne);
            del2 = new SampleDelegate(SampleMethodTwo);
            del3 = new SampleDelegate(SampleMethodThree);

            Console.WriteLine("Chaining delegates together!");
            del4 = del1 + del2 + del3;
            del4();
            Console.WriteLine("----------------\n");

            Console.WriteLine("\nRemove MethodTwo() from chain:");

            if(del2 != null)
            {
                Console.WriteLine("del2 is not null!");
                del2.Invoke();
                
            }

            del4 -= del2;
            del4();
        }

        public static void SampleMethodOne()
        {
            Console.WriteLine("Hello from SampleMethodOne()!");
        }
        public static void SampleMethodTwo()
        {
            Console.WriteLine("Hello from SampleMethodTwo()!");
        }
        public static void SampleMethodThree()
        {
            Console.WriteLine("Hello from SampleMethodThree()!");
        }
    }
}
