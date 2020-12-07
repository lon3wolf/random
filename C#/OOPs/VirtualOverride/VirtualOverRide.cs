using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOPs.VirtualOverride
{
    class VirtualOverRideDemo : IDemo
    {
        public void StartDemo()
        {
            Shape shape = new Shape() { height = 5, width = 5, ShapeName = "shape" };
            Circle circle = new Circle() { height = 5, width = 5, ShapeName = "Circle" };
            Square square = new Square() { height = 5, width = 5, ShapeName = "Square" };

            Console.WriteLine("Shape - Area: {0}", shape.Area());
            Console.WriteLine("Circle - Area: {0}", circle.Area());
            Console.WriteLine("Square - Area: {0}", square.Area());

            shape.SayHello();
            circle.SayHello();
            square.SayHello();

            

            Shape s = circle;
            s.fnShapeName();
            Console.WriteLine("Circle as Shape - Area: {0}", s.Area());
            
            s = square;
            s.fnShapeName();
            Console.WriteLine("Square as Shape - Area: {0}", s.Area());

            
        }

        public void EndDemo()
        {
            Console.ReadKey();
            Console.Clear();
        }
    }

    abstract class BaseClass
    {
        public double width, height;

        public virtual double Area()
        {
            Console.WriteLine("Error: Can't determine area of a generic shape");
            return 0;
        }
    }

    class Shape : BaseClass
    {
        public string ShapeName;
        public void fnShapeName()
        {
            Console.WriteLine(ShapeName);
        }
        public void SayHello()
        {
            Console.WriteLine("I am a base class:");
            this.fnShapeName();
        }
    }

    class Square : Shape
    {
        public override double Area()
        {
            return width * height;
        }

        
    }

    class Circle : Shape
    {
        public override double Area()
        {
            return Math.PI * height * width;
        }

        public new void SayHello() // new : To avoid warning : Warning	Circle.SayHello() hides inherited member Shape.SayHello() Use the new keyword if hiding was intended.
        {
            Console.WriteLine("This is a circle!");
        }
    }
}
