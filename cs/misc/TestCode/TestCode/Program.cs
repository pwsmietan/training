using System.Reflection;

namespace TestCode
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Fun with arrays!");

            string[] a = {
                "Laurie","Paul", "Spencer",
            };
            Console.WriteLine(a.Length);

            string[,] b = {
                { "a", "b", "c" },
                { "d","e","f" },
                { "g","h","i" }
            };
            Console.WriteLine(b.Length);

            Console.WriteLine("Reflection");
            Type tc = typeof(Customer);
            //ConstructorInfo? constructorInfo = type.GetConstructor(Type.EmptyTypes);
            //ConstructorInfo? constructorInfo = type.GetConstructor(new Type[] { typeof(string) });
            ConstructorInfo? constructorInfo = tc.GetConstructor(BindingFlags.Instance | BindingFlags.NonPublic, null, new Type[] { typeof(string) }, null);

            Console.WriteLine(value: $"Is constructor? {constructorInfo?.IsConstructor}");
            Console.WriteLine($"Is public? {constructorInfo?.IsPublic}");
            Console.WriteLine($"Is protected? {constructorInfo?.IsFamily}");



        }

        public class Customer
        {
            protected Customer(string s)
            {

            }

        }
    }
}
