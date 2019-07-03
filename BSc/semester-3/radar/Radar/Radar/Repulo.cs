using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Radar
{
    class Repulo
    {
        double elsoMertX;
        double elsoMertY;
        double masodikMertX;
        double masodikMertY;
        double iranyvektorX;
        double iranyvektorY;

        public Repulo(double elsoMertX, double elsoMertY, double masodikMertX, double masodikMertY, double iranyvektorX, double iranyvektorY)
        {
            this.elsoMertX = elsoMertX;
            this.masodikMertX = masodikMertX;
            this.elsoMertY = elsoMertY;
            this.masodikMertY = masodikMertY;
            this.iranyvektorX = iranyvektorX;
            this.iranyvektorY = iranyvektorY;
        }

        public double ElsoMertX
        {
            get { return elsoMertX; }
            set { elsoMertX = value; }
        }

        public double ElsoMertY
        {
            get { return elsoMertY; }
            set { elsoMertY = value; }
        }

        public double MasodikMertX
        {
            get { return masodikMertX; }
            set { masodikMertX = value; }
        }

        public double MasodikMertY
        {
            get { return masodikMertY; }
            set { masodikMertY = value; }
        }

        public double IranyvektorX
        {
            get { return iranyvektorX; }
            set { iranyvektorX = value; }
        }

        public double IranyvektorY
        {
            get { return iranyvektorY; }
            set { iranyvektorY = value; }
        }
    }
}
