// See https://aka.ms/new-console-template for more information
//Console.WriteLine("Hello, World!");

//class test
//{
//    static int GetSum(int a, int b)
//    {
//        return a + b;
//    }
//    static void Main(string[] args)
//    {
//        Console.WriteLine(GetSum(10, 20));
//    }
//}

//class test
//{
//    static void example(int a)
//    {
//        a = a * a;

//        Console.WriteLine("自定义函数内a = " + a);
//    }
//    static void Main(string[] args)
//    {
//        int a = 20;

//        Console.WriteLine("调用函数之前函数外a = " + a);

//        example(a);

//        Console.WriteLine("调用函数之后函数外a = " + a);
//    }
//}


//class test
//{
//    static void example(ref int a)
//    {
//        a = a * a;

//        Console.WriteLine("自定义函数内a = " + a);
//    }
//    static void Main(string[] args)
//    {
//        int a = 20;

//        Console.WriteLine("调用函数之前函数外a = " + a);

//        example(ref a);

//        Console.WriteLine("调用函数之后函数外a = " + a);
//    }
//}



//class test
//{

//    static void Main(string[] args)
//    {
//        for(int i = 2008; i <= 2030;  i++)
//        {
//            if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
//                Console.WriteLine(i + " ");
//        }
//    }
//}


class test
{
    static int  Encrypt(int a)//加密函数
    {
        return a ^ 1;
    }
    static int Descrypt(int a)//解密函数
    {
        return a ^ 1;
    }

    static void Main(string[] args)
    {
        int a = 4;
        Console.WriteLine("源数字a = " + a);

        int b = Encrypt(a);
        Console.WriteLine("加密后数字" + b);

        int c = Descrypt(b);
        Console.WriteLine("解密后数字" + c);
    }
}
