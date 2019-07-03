using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Radar
{
    class Radar
    {
        double xKoordinata;
        double yKoordinata;
        double tavolsag1;
        double tavolsag2;
        
        public Radar(double xKoordinata, double yKoordinata, double tavolsag1, double tavolsag2)
        {
            this.xKoordinata = xKoordinata;
            this.yKoordinata = yKoordinata;
            this.tavolsag1 = tavolsag1;
            this.tavolsag2 = tavolsag2;
        }

        public double Xkoordinata
        {
            get { return xKoordinata; }
            set { xKoordinata = value; }
        }

        public double Ykoordinata
        {
            get { return yKoordinata; }
            set { yKoordinata = value; }
        }

        public double Tavolsag1
        {
            get { return tavolsag1; }
            set { tavolsag1 = value; }
        }

        public double Tavolsag2
        {
            get { return tavolsag2; }
            set { tavolsag2 = value; }
        }
    }
}
