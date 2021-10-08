using System;

namespace Hack
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Input #items:");
            var itemCount = Double.Parse(Console.ReadLine());
            System.Console.WriteLine("Input price:");
            var pricePerItem = Double.Parse(Console.ReadLine());

            System.Console.WriteLine("Input State:");
            var stateCode = Console.ReadLine().ToUpper();

            if (stateCode != "UT" &&
                stateCode != "NV" &&
                stateCode != "TX" &&
                stateCode != "AL" &&
                stateCode != "CA") {
                System.Console.WriteLine("Error State code");
                System.Environment.Exit(0);
            }

            var total = itemCount * pricePerItem;

            total = CalculateDiscount(total);
            total = CalculateTax(total, stateCode.ToUpper());

            System.Console.WriteLine("Total: " + total);
        }

        private static double CalculateTax(double total, string stateCode) {
            if (stateCode == "UT") {
                return total + (total*0.0685);
            }
            if (stateCode == "NV") {
                return total + (total*0.08);
            }
            if (stateCode == "TX") {
                return total + (total*0.0625);
            }
            if (stateCode == "AL") {
                return total + (total*0.04);
            }
            if (stateCode == "CA") {
                return total + (total*0.0825);
            }
            return total;
        }

        private static double CalculateDiscount(double total) {
            if (total >= 50000) {
                return total - (total*0.15);
            }
            else if (total >= 10000) {
                return total - (total*0.10);
            }
            else if (total >= 7000) {
                return total - (total*0.07);
            }
            else if (total >= 5000) {
                return total - (total*0.05);
            }
            else if (total >= 1000) {
                return total - (total*0.03);
            }
            return total;
        }
    }
}
