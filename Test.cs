using System;

/* C# 1.0 feature test */
namespace Test1
{
    public class SimpleClass : SimpleInterface
    {
        SimpleStruct ss;
        int i;

        public static SimpleStruct StaticFunc(SimpleStruct ss) {
            Console.WriteLine(ss);
            return new SimpleStruct();
        }

        public SimpleStruct InstanceFunc(SimpleStruct ss) {
            Console.WriteLine(ss);
            return this.ss;
        }

        public int func(int val) {
            return val + 42;
        }

        public delegate SimpleStruct SimpleDelegate(SimpleStruct ss);
        public event SimpleDelegate SimpleEvent;
        public int SimpleProperty {
            get { return 0; }
            set { }
        }
    }

    public struct SimpleStruct : SimpleInterface
    {
        SimpleClass sc;
        int i;

        public static SimpleStruct StaticFunc(SimpleStruct ss) {
            Console.WriteLine(ss);
            return new SimpleStruct();
        }

        public SimpleClass InstanceFunc(SimpleStruct ss) {
            Console.WriteLine(ss);
            return this.sc;
        }

        public int func(int val) {
            return ((SimpleInterface)sc).func(val) + 13;
        }
    }

    public interface SimpleInterface
    {
        int func(int val);
    }
}

/* C# 2.0 feature test */
namespace Test2
{
    public interface GenericInterface<T>
    {
        T func(T v);
        T genericMethod<T2>(T v, T2 w);
    }

    public class GenericClass<T> : GenericInterface<T>
    {
        T x;

        public T func(T v) {
            return v;
        }

        public T genericMethod<T2>(T v, T2 w) {
            return x;
        }

        public static T myMethod(T x) {
            return x;
        }
    }

    public class DerivedGenericClass<T, T2> : GenericClass<T>, GenericInterface<T2>
    {
        T2 t2;
        public T2 func(T2 v) {
            return t2;
        }

        public T2 genericMethod<T3>(T2 v, T3 w) {
            return v;
        }

        public T2 newGenericMethod() {
            return t2;
        }

        public static int Return42() {
            return 42;
        }
    }

    public struct GenericStruct<T> : GenericInterface<T> where T : struct
    {
        T a;
        public T func(T v) {
            throw new NotImplementedException();
        }

        public T genericMethod<T2>(T v, T2 w) {
            throw new NotImplementedException();
        }

        public T? genericMethod2(T x) {
            return (42 < 43) ? null : (T?)x;
        }

        public static GenericStruct<T> ReturnStruct(T y) {
            var res = new GenericStruct<T>();
            res.a = y;
            return res;
        }
    }

    public interface IVariance<in T1, out T2>
    {
        T2 func(T1 v);
    }

    public class UseGenerics
    {
        public static void Main(string[] args) {
            GenericStruct<int>[] arr = new GenericStruct<int>[3];
            arr[0] = GenericStruct<int>.ReturnStruct(3);
            DerivedGenericClass<string, string> gc = new DerivedGenericClass<string, string>();
            string c = gc.func("oops");
            Console.WriteLine(c);
            gc.genericMethod("hello", arr[0].genericMethod2(3) ?? 0);
            GenericInterface<string> s = gc;
            s.genericMethod("goodbye", c);
            GenericClass<object>.myMethod(42);
            IVariance<string, int> q = null;
            q.func("nope");

            foreach (var v in arr) {
                v.genericMethod(64, "nope");
            }
        }
    }
}

/* C# 3.0 feature test */
namespace Test3
{
    public class FeatureTest
    {
        public string AutoProp { get; set; }
        public void AnonType() {
            var c = new { Value = 3, Message = "Nobody" };
            Console.WriteLine(c);
        }

#if FALSE // Linq requires anonymous functions, which would pull in a lot of dependencies
        public int Linq() {
            var scores = new int[] { 1, 2, 3, 4 };
            var highScoresQuery =
                from score in scores
                where score > 80
                orderby score descending
                select score;
            return highScoresQuery.Count();
        }
#endif
    }
}

/* Generics test */
namespace TestGenerics
{
    public class FunkyA<AT>
    {
        public AT at;
        public FunkyA() {
        }
        public FunkyA(AT at) {
            this.at = at;
        }
        public AT rt(AT x) {
            return x;
        }
    }

    public class FunkyB<BT1, BT2> : FunkyA<BT2>
    {
        public BT1 bt1;
        public BT2 bt2;
        public BT2 rt1(BT1 x) {
            return bt2;
        }
        public BT1 rt2(BT2 y) {
            return bt1;
        }
        public FunkyA<FunkyA<BT1>> rtx(FunkyA<FunkyA<BT2>> z) {
            return new FunkyA<FunkyA<BT1>>(new FunkyA<BT1>(bt1));
        }
    }

    public class FunkyC<CT1, CT2, CT3> : FunkyB<CT3, CT1>
    {
    }

    public class FunkyTest
    {
        public FunkyA<int> x;
        public FunkyB<string, int> y;
        public FunkyC<object, int, string> z;
        void test() {
            x.rt(0);
            y.rt1("");
            y.rt2(0);
            z.rtx(null);
        }
    }
}

/* VTable test */
namespace TestVTables
{
    public struct Vector3
    {
        public float x, y, z;
    }

    public class TestVTable
    {
        public interface TestInterface
        {
            int overrideme();
        }

        public interface TestInterface2
        {
            int overrideme2();
        }

        public interface TestInterface3
        {
            int overrideme3();
        }

        public interface IT1
        {
            void f1();
            void f2();
        }

        public interface IT2
        {
            void f1();
            void f3();
        }

        public interface IT3 : IT2, IT1
        {
            void f2();
            void f1();
        }

        public class WeirdLayout1
        {
            public ulong x;
            public char y;
        }

        public class WeirdLayout2 : WeirdLayout1
        {
            public char z;
            public short f;
        }

        public struct TestStruct : TestInterface, TestInterface2, IT1, IT2
        {
            int x;
            public int overrideme() {
                return 42 + x;
            }

            public int overrideme2() {
                return 42000 * x;
            }

            public void f1() {

            }

            public void f2() {

            }

            public void f3() {

            }
        }

        public class TestClass : TestInterface, TestInterface3, IT3
        {
            int x;
            public virtual int overrideme() {
                return 64 - x;
            }
            public void normal1() {

            }
            public virtual int overrideme3() {
                return -1 + x;
            }
            public void normal2() {

            }
            public void f1() { }
            public void f2() { }
            public void f3() { }
        }

        public class TestClass2 : TestClass
        {
            int y;
            public override int overrideme() {
                return 1 + y;
            }
            public new void normal2() {

            }
        }

        public interface ITestGeneric<T>
        {
            void genericFunc(T t);
        }

        public class TestGeneric<T> : ITestGeneric<T>
        {
            T m_t;
            public T[] arr;
            public int x;
            public TestGeneric(T[] arr) {
                this.arr = arr;
                this.x = 0;
                for (int i = 0; i < arr.Length; i++) {
                    x += arr[i].GetHashCode();
                }
            }
            public void genericFunc(T t) {
                x += arr[0].Equals(t) ? 1 : 0;
            }
        }

        public class TestGeneric2<T1, T2> : TestGeneric<T2>
        {
            T1 m_t1;
            T2 m_t2;
            public TestGeneric2(T2[] t2) : base(t2) {

            }
            public void secondGenericFunc(T1 t1, T2 t2) {
                genericFunc(t2);
                TestGeneric<T1> tg1 = new TestGeneric<T1>(null);
                tg1.genericFunc(t1);
            }
        }

        public void overrideme(int x) {
            Console.WriteLine(x);
        }
        public float takestruct(Vector3 a, Vector3 b, Vector3 c) {
            return a.x + b.y + c.z;
        }
        public delegate void callit(int x);
        callit monkey;

        public int doit(TestInterface ti, TestInterface2 ti2, TestInterface3 ti3) {
            return ti.overrideme() * 2 + ti2.overrideme2() + ti3.overrideme3();
        }

        public void calltypes(ref Vector3 vin, ref Vector3 vout, ref Vector3 vref, params Vector3[] vparams) {
            vout = vin;
        }

        public void callgeneric<T>(ITestGeneric<T> it, T t) {
            it.genericFunc(t);
        }

        public void callints(IT1 it1, IT2 it2, IT3 it3) {
            it1.f1();
            it1.f2();
            it2.f1();
            it2.f3();
            it3.f1();
            it3.f2();
            it3.f3();
        }

        public int[] intProperty { get; set; }
        public int[] intProp2 { get { return intArray; } set { intArray = value; } }
        private int[] intArray;
        public object[] objArray;

        // Start is called before the first frame update
        void Start() {
            if (monkey != null)
                monkey(0);
            TestClass i1 = new TestClass2();
            i1.overrideme();
            i1.overrideme3();
            i1.normal2();
            TestStruct i2 = new TestStruct();
            i2.overrideme();
            i2.overrideme2();
            doit(i1, i2, i1);
            doit(i2, i2, i1);
            callints(i2, i2, i1);
            int res = 0;
            for (int i = 0; i < intArray.Length; i++) {
                res += intArray[i];
            }
            for (int i = 0; i < objArray.Length; i++) {
                res += (int)objArray[i];
            }
            ITestGeneric<int> x1 = new TestGeneric<int>(new int[] { 1, 2, 3 });
            ITestGeneric<object> x2 = new TestGeneric<object>(new object[] { new object() });
            callgeneric(x1, 0);
            callgeneric(x2, "foo");
            ITestGeneric<string> x3 = new TestGeneric2<int, string>(new string[] { "as", "de" });
            new WeirdLayout2().f = 3;
        }

        // Update is called once per frame
        void Update() {
            overrideme(0);
        }
    }
}
