// See https://aka.ms/new-console-template for more information
// Console.WriteLine("Hello, World!");

using MySpace;

namespace test
{
    class Program
    {
        static void Main(string[] args) 
        {
            Student student = new Student();
            student.SayHello();
        }
    }
}

namespace MySpace
{
    class Student
    {
        public void SayHello()
        {
            Console.WriteLine("Hello World\n");
            Console.Read();
        }
    }
}